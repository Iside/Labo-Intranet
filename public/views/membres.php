<div class="span9">
<?$res->get('menu')?>
<div class="box padding15">
                <div class="row-fluid">
                    <form class="form-search nomargin">
                      <input type="text" placeholder="Rechercher un membre" class="input-medium search-query" style="width: 50%; margin-right: 10px">   
                      <label class="checkbox inline">
                        <input type="checkbox" id="inlineCheckbox1" value="option1"> Pays
                      </label>
                      <label class="checkbox inline">
                        <input type="checkbox" id="inlineCheckbox2" value="option1"> Ville
                      </label>
                      <label class="checkbox inline">
                        <input type="checkbox" id="inlineCheckbox3" value="option1"> Promotion
                      </label> 
                      <button type="submit" class="btn" style="margin-left: 10px"><i class="icon-search"></i> Rechercher</button>
                    </form>
                 </div>
              </div> 
              <div class="box padding30">
                <div class="row-fluid">
                  <div class="span12">
                    <h2 class="lighter"><?=User::count()?>&nbsp;Membres dans <?php print Company::first()->sexe > 0 ? 'la' : 'le' ?>&nbsp;<?=Company::first()->name?> </h2>
                    <p></p>
                    <table id="members" class="table">
                      
                      <thead>
                        <tr>
                          <th class="image"></th>
                          <th class="members">Membres</th>
                          <th class="suscribed_at">Inscrit depuis...</th>
                          <th class="status">Rang</th>
                          <th class="activity">En ce moment...</th>
                        </tr>
                      </thead>
                      
                      <tbody>
                        <?foreach (User::all() as $membre):?>
                        <tr>
                          <td class="image"><img src="http://dummyimage.com/32x32/3a6dc4/ffffff.jpg" width="32" height="32" /></td>
                          <td class="members"><a href="profil.html"><?=$membre->id?></a></td>
                          <td class="suscribed_at"><?=$membre->created_at->format('d - m - Y'); ?></td>
                          <td class="points">100</td>
                          <td class="projets">Projet d'excellence</td>
                          <td class="link"><a href="profil.html">Voir</a></td>
                        </tr>
                        <?endforeach;?>
                      </tbody>
                    </table>
                    <?$res->get("pagination")?>
                  </div>
                </div>
              </div>
</div>
<?=$widget->load("talk")?>