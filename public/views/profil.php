            <div class="span9">
              <?$res->get("menu")?>
              <div id="user-profil" class="box padding15">
                <div class="row-fluid">
                <div class="span12">
                    <div style="float: left;overflow: hidden;margin-right: 15px;">
                      <img src="<?=IMG_PATH?>115451-photo.jpg">
                    </div>
                    <div class="user-info" style="">                  
                        <h2>Steffi Rakotozafy</h2>
                        <p class="line-extra-info">
                          <span><i class="icon-map-marker"></i> Paris</span> 
                          <span><i class="icon-envelope"></i> <a href="">steffi.rakotozafy@supinfo.com</a></span> 
                          <span><i class="icon-user"></i>115451</span>
                        </p>
                        <div class="follow">
                          <button id="follow" class="btn ">S'abonner</button>
                          <button id="unfollow" class="btn btn-danger" style="display: none;">Se désabonner</button>
                          <button id="following" class="btn btn-primary" style="display: none;">Abonné</button>
                        </div>
                    </div>
                    <div class="user-stats" style="overflow: hidden;">
                      <div class="row-fluid text-center">
                        <div class="span3"><a class="stat" href=""><p>120</p><h6>publications</h6></a></div>
                        <div class="span3"><a class="stat" href=""><p>32</p><h6>photos</h6></a></div>
                        <div class="span3"><a class="stat" href=""><p>4</p><h6>projets</h6></a></div>
                        <div class="span3"><a class="stat" href=""><p>150</p><h6>abonnés</h6></a></div>
                      </div>
                    </div>
                  </div>
                 </div>
              </div>
              
              <div class="row-fluid">
                <div id="user-menu" class="span4">
                    <ul class="nav nav-tabs nav-stacked">
                      <li class="active"><a href="">Fil d'actualité <i class="icon-chevron-right"></i></a></li>
                      <li><a href="">Messages <span class="notifications-simple">(2)</span> <i class="icon-chevron-right"></i></a></li>
                      <li><a href="">Activités <i class="icon-chevron-right"></i></a></li>
                      <li><a href="">Abonnements <i class="icon-chevron-right"></i></a></li>
                      <li><a href="">Photos <i class="icon-chevron-right"></i></a></li>
                    </ul>  
                </div>
                <div class="span8">
                  <div class="box padding30">
                    <p>
                      <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
                      <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
                    </p>
                  </div>                 
                </div>                
              </div>
            </div>
<?=$widget->load("talk")?>