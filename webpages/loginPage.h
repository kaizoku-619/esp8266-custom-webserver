R"(
  <html>
    <head>
      <title>Login</title>
      <meta charset='utf-8'>
      <meta name='viewport' content='width=device-width, initial-scale=1'>
      <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
      <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>
      <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>
    </head>

    <body>
      <nav class='navbar navbar-inverse '>
        <div class='container-fluid'>
          <div class='navbar-header'>
            <a class='navbar-brand' href='/'>Home</a>
            <a class='navbar-brand' href='led'>LED</a>
          </div>
          <ul class='nav navbar-nav navbar-right'>
            <li>
              <a href='login'>
                <span class='glyphicon glyphicon-log-in'>
                </span> Login
              </a>
            </li>
          </ul>
        </div>
      </nav>
      <div class='container'>
  	  	<form role='form' action='/verifyLogin' method='POST'>
          <fieldset>
            <div class='form-group'>
              <input class='form-control' placeholder='Username' name='username' type='text' autofocus>
            </div>
            <div class='form-group'>
              <input class='form-control' placeholder='Password' name='password' type='password' value=''>
            </div>
            <!-- Change this to a button or input when using this as a form -->
            <input type='submit' class='btn btn-success btn-lg btn-block' value='Login'>
            <!-- <p>New Member? <a href='signup.html' class=''>Sign up</a></p> -->
          </fieldset>
        </form>
  	  </div>
    </body>
  </html>
)"
