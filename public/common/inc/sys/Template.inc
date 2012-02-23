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

  function useTemplate($begin=array('Home', true, true, ""), $end=array(true)) {
    if ($begin != null)
      $this->Begin($begin[0], isset($begin[1]) ? $begin[1] : true, isset($begin[2]) ? $begin[2] : true, $begin[3] );
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
      $this->Close($end[0]);
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
    header("location:" . SITE_PATH . 'load/' . $action . '.php' . $arguments);
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

  function Begin($title='Home', $layout=true, $showMenu=True, $infos="") {
    ?>
<!DOCTYPE html>
<html>
  <head>
    <title>SUPINFO</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
     <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
    
    <!-- Le styles -->
        <?php
        if ($layout) {
          Dir::IncludeDirectory(CSS_PATH, 'css');
          Dir::IncludeDirectory(JS_PATH, 'js');
        }
        ?>
  </head>
  <body>
    <div id="background" class="lazyHeight">
     <div id="bg-user" class="lazyHeight">
      
     </div>
     <div id="bg-liner" class="lazyHeight">
      
     </div>      
    </div>
      
<div id="doc" class="text-shadow">
      <div id="content">
        <div id="header">
            <div class="header-colors"></div>
            <div class="container-fluid text-right">
              <!-- SI NON CONNECTE -->
              <a class="btn btn-success" href="suscribe.php">Inscription</a>
              
              <!-- SI CONNECTE
              <a class="uiProfile nodeco" href="https://www.facebook.com/mangoberry?ref=tn_tnmn" title="Profil">
                <img class="uiProfilePhoto" width="32" src="https://fbcdn-profile-a.akamaihd.net/hprofile-ak-snc4/48769_770534613_1336862317_q.jpg" alt="">
                <span class="lien uiName nodeco">Steffi Rakotozafy</span>
              </a>
              -->
            </div>
        </div>
        <div id="main" class="container-fluid">
          <?php                    if ($infos!=""):?>
                      <div class="alert alert-info"><strong>Attention!</strong> <?php print $infos ?></div>
          <?php endif;?>
          
          <div id="main-wrapper" class="row-fluid show-grid">
            <div class="span9">
            <!-- CONNEXION -->
              <?php if ($showMenu): ?>
              <div class="menu box">
                <ul class="nav nav-pills">
                  <li <?php print stripos($_SERVER['SCRIPT_NAME'], "accueil") ? 'class="selected"' : '' ?>><a href="" class="nodeco">Accueil</a></li>
                  <li <?php print stripos($_SERVER['SCRIPT_NAME'], "profil") ? 'class="selected"' : '' ?>><a href="" class="nodeco">Profil</a></li>
                  <li <?php print stripos($_SERVER['SCRIPT_NAME'], "activities") ? 'class="selected"' : '' ?>><a href="" class="nodeco">Activités</a></li>
                  <li <?php print stripos($_SERVER['SCRIPT_NAME'], "membres") ? 'class="selected"' : '' ?>><a href="" class="nodeco">Membres</a></li>
                  <li <?php print stripos($_SERVER['SCRIPT_NAME'], "questions") ? 'class="selected"' : '' ?>><a href="" class="nodeco">Questions</a></li>
                </ul>
              </div>
              <?php endif; ?>
        <?php
        }

        function Close($showChat=true) {?>
        </div>
          <?php if ($showChat):?>
                      <div class="span3">
              <div id="chat" class="well nopadding">
                <ul id="chat-title" class="nav nav-list nopadding">
                  <li class="nav-header"><i class="icon-comment"></i> Chat</li>
                </ul>
                <ul id="chat-content" class="nav nav-list list-contact nopadding">
                  <div id="chat-contacts" style="">
                      <li class="contact" data-name="Thi Hong Hoa">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Thi Hong Hoa</span> <span class="notifications-number">2</span>
                      </li>
                      <li class="contact" data-name="Mihanta">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Mihanta</span>
                      </li>
                      <li class="contact" data-name="Osin">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Osin</span>
                      </li>
                      <li class="contact" data-name="Vincent">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Vincent</span>
                      </li>
                      <li class="contact" data-name="Léa">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Léa</span>
                      </li>
                      <li class="contact" data-name="Nicolas">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Nicolas</span>
                      </li>
                      <li class="contact" data-name="Michael">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Michael</span>
                      </li> 
                      <li class="contact" data-name="Hugo">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Hugo</span>
                      </li>
                      <li class="contact" data-name="Kelly">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Kelly</span>
                      </li>
                      <li class="contact" data-name="Bob">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Bob</span>
                      </li>
                      <li class="contact" data-name="Guillaume">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Guillaume</span>
                      </li>
                      <li class="contact" data-name="Robert">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Robert</span>
                      </li>
                      <li class="contact" data-name="Georges">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Georges</span>
                      </li>
                      <li class="contact" data-name="Eddy">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Eddy</span>
                      </li> 
                      <li class="contact" data-name="Iony">
                        <img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" />
                        <span>Iony</span>
                      </li>
                  </div>
                  <div id="chat-message">
                    <div id="chat-user" class="padding5">
                      <i class="icon-remove"></i> <span class="name">Vincent Bismuth</span>
                    </div>                  
                    <div id="chat-dialogg"></div>
                    <div id="chat-composer" class="padding10">
                      <input type="text" class="nomargin" id="input01">
                    </div>
                  </div>
                </ul>
              </div>              
            </div>
            <!-- FIN CONNEXION -->
            <?php endif;?>
      </div>
    </div>
      </div>
</div>
  
    <script type="text/javascript">
    $(document).ready(function() {

      setTimeout('heighty()',1000);
            
      $("#chat-title").click(function(){ 
        $("#chat-content").slideToggle("50","easeOutExpo");
      });
 
      $("#chat-user .icon-remove").click(function(){ 
        $("#chat-message").hide();
        $("#chat-contacts").css("height","379px");
      });
      
      $("#chat-contacts .contact").each(function(n){
        $(this).bind("click",function(){
          var name = $(this).data("name");
          $("#chat-contacts").css("height","200px"); 
          $("#chat-message").show();  
          $("#chat-user .name").text(name);  
        });
      });
      
      $(window).scroll(function(){
        if ($(window).scrollTop() >= "94" && $(window).width() > 968){
          $("#chat").css({
            "position" : "fixed",
            "top" : "15px",
            "width" : "238px"
          });
        }
        if ($(window).scrollTop() < "94" && $(window).width() > 968){
          $("#chat").css({
            "position" : "relative",
            "top" : "0px",
            "width" : "238px"
          });
        }
      });
    
    });
    
    function scrollTo(top){
      $('html, body').animate({scrollTop: top + "px" }, 200);
    }
    
    function heighty () {
      $('.lazyHeight').each(function(n) { 
        var documentHeight = $(document).height();
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
