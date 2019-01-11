#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "creds.h"

#define LED_PIN 2

const char* home =
#include "webpages/homePage.h"
;
const char* led =
#include "webpages/ledPage.h"
;
const char* notFound =
#include "webpages/notFoundPage.h"
;
const char* login =
#include "webpages/loginPage.h"
;
const uint16_t port = 80;

ESP8266WebServer server(port);

void connectToWiFi() {
    delay(10);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.print(SSID);
    /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
    would try to act as both a client and an access-point and could cause
    network-issues with your other WiFi-devices on your WiFi-network. */
    WiFi.mode(WIFI_STA);
    //start connecting to WiFi
    WiFi.begin(SSID, PASSWORD);
    //while client is not connected to WiFi keep loading
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi connected to ");
    Serial.println(SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("");
    // Start the mDNS responder for esp8266.local
    if (!MDNS.begin("esp")) {
        Serial.println("Error setting up MDNS responder!");
    }
    Serial.println("mDNS responder started");
}

void initRoutesCallbacks() {
    server.on("/",[]() {
            server.send(200,"text/html", home);
            Serial.println("/ is requested");
    });

    server.on("/led", []() {
      server.send(200, "text/html", led);
      Serial.println("/led is requested");
    });

    server.on("/body", []() {
        Serial.println("/body is requested");
        if (server.hasArg("plain")== false) {
            server.send(200, "text/plain", "Body not received");
            return;
        }
        String message = "Body received:\n";
        message += server.arg("plain");
        message += "\n";

        server.send(200, "text/plain", message);
        Serial.println(message);
    });

    server.on("/toggle", HTTP_POST, []() {
        digitalWrite(LED_PIN,!digitalRead(LED_PIN));
        server.sendHeader("Location","/led");
        server.send(303);
    });

    server.on("/login", []() {
        server.send(200, "text/html", login);
        Serial.println("/login is requested");
    });

    server.on("/verifyLogin", HTTP_POST, []() {
        // If a POST request is made to URI /login
        if( !server.hasArg("username") ||
            !server.hasArg("password") ||
            server.arg("username") == NULL ||
            server.arg("password") == NULL) {
            // If the POST request doesn't have username and password data
            server.send(400, "text/plain", "400: Invalid Request");
            // The request is invalid, so send HTTP status 400
            return;
        }
        if( server.arg("username") == USERNAME &&
            server.arg("password") == USER_PASSWORD) {
            // If both the username and the password are correct
            server.send(200, "text/html", "<h1>Welcome, " + server.arg("username") + "!</h1><p>Login successful</p>");
        } else {
            // Username and password don't match
            server.send(401, "text/plain", "401: Unauthorized");
        }
    });

    server.onNotFound([]() {
        Serial.println("Not Found request");
        server.send(404, "text/html", notFound);
    });
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    Serial.begin(115200);
    connectToWiFi();
    initRoutesCallbacks();
    server.begin();
    Serial.print("Server listening on port ");
    Serial.println(port);
}

void loop() {
    server.handleClient();
}
