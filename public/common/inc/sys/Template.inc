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
      <div id="background" class="lazyHeight" style="opacity: 0.2">
     <div id="bg-user" class="lazyHeight" style="display:none">
      
     </div>
     <div id="bg-liner" class="lazyHeight">
      
     </div>      
    </div>
      <?php if ($showMenu): ?>
                <div id="doc" class="text-shadow">
      <div id="content">
        <div id="header">
            <div class="header-colors"></div>
            <div class="container-fluid text-right">
              <!-- SI NON CONNECTE -->
              <a class="btn" href="connexion.html">Connexion</a> <a class="btn btn-success" href="inscription.html">Inscription</a>
              
              <!-- SI CONNECTE
              <a class="uiProfile nodeco" href="https://www.facebook.com/mangoberry?ref=tn_tnmn" title="Profil">
                <img class="uiProfilePhoto" width="32" src="https://fbcdn-profile-a.akamaihd.net/hprofile-ak-snc4/48769_770534613_1336862317_q.jpg" alt="">
                <span class="lien uiName nodeco">Steffi Rakotozafy</span>
              </a>
              -->
            </div>
        </div>
        <div id="main" class="container-fluid">
          
          <div class="alert alert-info"><strong>Heads up!</strong> All javascript plugins require the latest version of jQuery.</div>
          
          <div id="main-wrapper" class="row-fluid show-grid">
            
            <!-- CONNEXION -->
            <div class="span9">
              <div class="menu box">
                <ul class="nav nav-pills">
                  <li><a href="" class="nodeco">Accueil</a></li>
                  <li><a href="" class="nodeco">Profil</a></li>
                  <li class="selected"><a href="" class="nodeco">Activité</a></li>
                  <li><a href="" class="nodeco">Membres</a></li>
                  <li><a href="" class="nodeco">Questions</a></li>
                </ul>
              </div>
              <?php endif; ?>
            
        <?php
        }

        public

        function Close() {
          ?>
                      <div class="span3">
              <div id="chat-block" class="nomargin">
                <div class="menu box" style="margin-bottom: 3px;">
                  <ul class="nav nav-pills">
                    <li><a href="" class="nodeco">Discussion</a></li>
                  </ul>
                </div>
                <div class="box">
                  <div id="chat-contacts" style="height: 200px; overflow-y: auto">
                    <ul class="padding10">
                      <li>Thi Hong Hoa</li>
                      <li>Osin</li>
                      <li>Vincent</li>
                      <li></li>
                      <li></li>
                      <li></li> 
                      <li></li>
                      <li></li>
                      <li></li>   
                      <li></li> 
                      <li></li>
                      <li></li>
                      <li></li>                        
                    </ul>
                  </div>
                  <div id="chat-composer" class="padding10" style="background: #EEE; border-top: 1px solid #D4D4D6">
                    Vincent Bismuth
                  </div>                  
                  <div id="chat-message" style="height: 120px; overflow-y: auto"></div>
                  <div id="chat-composer" class="padding10" style="border-top: 1px solid #D4D4D6">
                    <input type="text" class="nomargin" id="input01" style="width: 96%;">
                  </div>
                </div>                  
              </div>
            </div>
            <!-- FIN CONNEXION -->
            
          </div>
        </div>
      </div>
    </div>

    <script type="text/javascript">
    $(document).ready(function() {

      heighty ();
      $(window).resize(function(){ heighty (); });      
      //$(window).scroll(function(){ heighty (); });
      
      /*  
      $(window).scroll(function(){
          if ($(window).scrollTop() >= "94"){
            $("#chat-block").addClass("span3").css("position","fixed").css("top","20px");
          }
          if ($(window).scrollTop() < "94"){
            $("#chat-block").removeClass("span3").css("position","relative").css("top","0px");
          } 
      });
      */
    });
    
    function heighty () {
      $('.lazyHeight').each(function(n) { 
        var documentHeight = $(document).height() + 100;
        $(this).css("height", documentHeight + "px");
      });
    }
    </script>
    
    
  </body>
</html>
    <?php
  }

}
?>
