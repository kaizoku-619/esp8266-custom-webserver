R"(
  <html>
    <head>
      <title>LED</title>
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
          <ul class="nav navbar-nav navbar-right">
            <li>
              <a href="login">
                <span class="glyphicon glyphicon-log-in">
                </span> Login
              </a>
            </li>
          </ul>
        </div>
      </nav>
      <div class='container'>
        <form action='/toggle' method='POST'>
          <input type="submit" class='btn btn-primary btn-lg btn-block' value='Toggle LED'>
        </form>
      </div>
    </body>
  </html>
)"
