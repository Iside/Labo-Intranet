<div class="span9">
              <?=$widget->load("menu")?>
              <!--<div id="activite-header" class="row-fluid" style="position: relative">
                  <img src="img/map.jpg" />
                  <div style="position: absolute;top: 15px;right: 15px;width: 170px;">
                    <a class="btn btn-primary" href=""><i class="icon-plus-sign icon-white"></i> CrÃ©e une activitÃ©</a>
                  </div>
              </div>-->
              
              <div class="liste box padding30">
                <table class="table">
                  <thead>
                    <tr>
                      <th class="name">Nom de l'événement</th>
                      <th class="members">Membres</th>
                      <th class="status">Status</th>
                      <th class="activity">Activité</th>
                    </tr>
                  </thead>
                  <tbody>
                    <tr>
                      <td><a href="activite_salon.html">Open Labs</a></td>
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
                      <td><a href="">RÃ©union SPR</a></td>
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
                      <td><a href="">Salon de l'étudiant</a></td>
                      <td>8</td>
                      <td>Terminé</td>
                      <td>Ok C'est cool, j'attends que Ã§a soit terminé mais bon, je n'ai pas le temps, je vais dormir</td>
                    </tr>
                  </tbody>
                </table>
                <?=$widget->load("pagination")?>
              </div>

              
              <div class="box padding30 nopaddingtop">
                <div class="page-header">
                    <h3>A venir <small></small></h3>
                </div>
                <div class="row-fluid">
                  <div class="span2"></div>
                  <div class="span2"></div>
                  <div class="span2"></div>
                  <div class="span2"></div>
                </div>
              </div>              
            </div>
<?=$widget->load("talk")?>
