<?php

class Template {

  private static $instances = array();

  /**
   * Static method for instantiating a singleton object.
   *
   * @return object
   */
  final public static function instance() {
    if (!isset(self::$instances['Template']))
      self::$instances['Template'] = new Template();

    return self::$instances['Template'];
  }

  final private function __clone() {
    
  }

  final protected function get_called_class() {
    $backtrace = debug_backtrace();
    return get_class($backtrace[2]['object']);
  }

  public function __construct() {
    
  }

  /*
   * Vous pouvez mettre nul ici pour ne pas décorer le template comma valeur à begin. La vue sera chargé si elle existe.
   */

  function useTemplate($begin=array('Home', true, true)) {
    if ($begin != null)
      $this->Begin($begin[0], isset($begin[1]) ? $begin[1] : true, isset($begin[2]) ? $begin[2] : true );
    $paths = explode('/', $_SERVER['SCRIPT_NAME']);
    foreach (get_object_vars($this) as $key => $var) {
      global $$key;
      $$key = $var;
    }
    $script = $paths[count($paths) - 1];
    if (is_file(VIEW_PATH . '/' . $script)) {
      include VIEW_PATH . '/' . $script;
    }
    if ($begin != null)
      $this->Close();
  }

  function load($action, $args=array()) {
    $arguments = "";
    if (count($args))
      $arguments = "?";
    $count = 1;
    foreach ($args as $key => $arg) {
      $arguments .= $key . '=' . $arg;
      $count++;
      $count == count($args) ? $arguments .= "&amp;" : $arguments .="";
    }
    if (!preg_match('/', $action))
      preg_match('.php', $action) ? header("location:" . SITE_PATH . 'load/' . $action . $arguments) : header("location:" . SITE_PATH . 'load/' . $action . '.php' . $arguments);
    header("location:" . $action . $arguments);
  }

  function reload($action, $args=array()) {
    $this->load($_SERVER['SCRIPT_NAME'], $args);
  }

  public static function asLink($action="") {
    if ($action == "")
      return;
    if (is_file(LOAD_PATH . '/' . $action .'.php'))
      return LOAD_PATH . '/' . $action .'.php';
    elseif ((is_file(VIEW_PATH . '/' . $action .'.php')))
      return VIEW_PATH . '/' . $action .'.php';
    return;
  }

  function Begin($title='Home', $layout=true, $showMenu=True) {
    ?>


    <!DOCTYPE html>
    <html lang="en">
      <head>
        <meta charset="ISO-8859-1">
        <title><?php print SiteName . " - " . $title ?></title>

        <!-- Le styles -->
        <?php
        if ($layout) {
          Dir::IncludeDirectory(CSS_PATH, 'css');
          Dir::IncludeDirectory(JS_PATH, 'js');
        }
        ?>
      </head>
      <body>
        <div class="navbar navbar-fixed-top">
          <div class="navbar-inner">
            <div class="container">   
              <a class="brand" href="<?php print SITE_PATH ?>">Labo-Robotique</a>
              <?php if ($showMenu): ?>
                <ul class="nav">
                  <li><a href="<?php print SITE_PATH . 'load/profil.php' ?>">Mon Profil</a></li>
                  <li><a href="#">En cours de construction, nous reviendrons vite vers vous...</a></li>
                  <li>
                    <form class="form-search" method="POST" action="../controllers/signin.php">
                      <input type="text" placeholder="Email" class="input-small">
                      <input type="password" placeholder="Password" class="input-small">
                      <button  class="btn" type="submit">Go</button></form>
                  </li>
                </ul>
              <?php endif; ?>
            </div>
          </div>
        </div>
        <div class="container" style="margin-top: 50px;">

        <?php
        }

        public

        function Close() {
          ?>
          <footer>
            <p>&copy; Copyright SUPINFO International University</p>
          </footer>
        </div> <!-- /container -->
      </body>
    </html>
    <?php
  }

}
?>
