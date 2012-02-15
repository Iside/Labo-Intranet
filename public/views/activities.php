<!DOCTYPE html>
<html>
  <head>
    <title>SUPINFO</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <link rel="stylesheet" type="text/css" href="style.css" media="screen" />
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" media="screen" />
    <link rel="stylesheet" type="text/css" href="css/bootstrap.responsive.css" media="screen" />
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
  </head>
  <body>
    
    <div id="background" class="lazyHeight" style="opacity: 0.2">
     <div id="bg-user" class="lazyHeight" style="display:none">
      
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
              
              <div class="box">
                <div id="activite-header" class="row-fluid" style="">
                  <div class="span9"><img src="http://dummyimage.com/680x151/3a6dc4/ffffff.jpg"></div>
                  <div class="span">
                    <div class="padding10 text-center">
                      <a class="btn" href=""><i class="icon-plus-sign"></i> Crée une activité</a>
                    </div>
                  </div>
                </div>
              </div>
              
              <div class="box padding10">
                <button class="btn">Classe</button>
                <button class="btn">Status</button>
              </div>
              
              <div class="liste box padding30">
                <table class="table">
                  <thead>
                    <tr>
                      <th class="name">Nom de l'évènement</th>
                      <th class="members">Membres</th>
                      <th class="status">Status</th>
                      <th class="activity">Activité</th>
                    </tr>
                  </thead>
                  <tbody>
                    <tr>
                      <td><a href="">Open Labs</a></td>
                      <td>4</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>
                    <tr>
                      <td><a href="">JPO</a></td>
                      <td>12</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>
                    <tr>
                      <td><a href="">Salon de l'Informatique</a></td>
                      <td>12</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>
                    <tr>
                      <td><a href="">Salon MBA</a></td>
                      <td>5</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>
                    <tr>
                      <td><a href="">Réunion SPR</a></td>
                      <td>20</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>
                    <tr>
                      <td><a href="">Salon Masters</a></td>
                      <td>12</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>                    
                    <tr>
                      <td><a href="">Salon ADREP</a></td>
                      <td>2</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>
                    <tr class="finish">
                      <td><a href="">iRobot</a></td>
                      <td>20</td>
                      <td>Terminé</td>
                      <td></td>
                    </tr>
                    <tr>
                      <td><a href="">Conférence Oracle</a></td>
                      <td>104</td>
                      <td>En cours</td>
                      <td></td>
                    </tr>                    
                    <tr class="finish">
                      <td><a href="">Salon de l'Étudiant</a></td>
                      <td>8</td>
                      <td>Terminé</td>
                      <td>Ok C'est cool, j'attends que ça soit terminé mais bon, je n'ai pas le temps, je vais dormir</td>
                    </tr>
                  </tbody>
                </table>
              </div>
              
              <div class="box padding30 nopaddingtop">
                <div class="page-header">
                    <h3>À venir <small></small></h3>
                </div>
                <div class="row-fluid">
                  <div class="span2"></div>
                  <div class="span2"></div>
                  <div class="span2"></div>
                  <div class="span2"></div>
                </div>
              </div>
                            
            </div>
            <div class="span3">
              <div id="chat-block" class="nomargin">
                <div class="menu box" style="margin-bottom: 3px;">
                  <ul class="nav nav-pills">
                    <li><a href="" class="nodeco">Discussion</a></li>
                  </ul>
                </div>
                <div class="box">
                  <div id="chat-contacts" style="height: 200px; background: #CCC; overflow-y: auto">
                    <ul class="padding10">
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
                      <li></li>
                      <li></li>
                      <li></li>                        
                    </ul>
                  </div>
                  <div id="chat-message" style="height: 120px; overflow-y: auto"></div>
                  <div id="chat-composer" class="padding10" style="background: #EEE;">
                    <input type="text" class="nomargin" id="input01">
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