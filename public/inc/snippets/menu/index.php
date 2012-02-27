<div class="menu box">
  <ul class="nav nav-pills">
    <li <?=stripos($_SERVER['SCRIPT_NAME'], "accueil") ? 'class="selected"' : '' ?>><a href="<?=$res->asLink("accueil") ?>" class="nodeco">Accueil</a></li>
    <li <?=stripos($_SERVER['SCRIPT_NAME'], "profil") ? 'class="selected"' : '' ?>><a href="<?=$res->asLink("profil") ?>" class="nodeco">Profil</a></li>
    <li <?=stripos($_SERVER['SCRIPT_NAME'], "activities") ? 'class="selected"' : '' ?>><a href="<?=$res->asLink("activities") ?>" class="nodeco">Activités</a></li>
    <li <?=stripos($_SERVER['SCRIPT_NAME'], "membres") ? 'class="selected"' : '' ?>><a href="<?=$res->asLink("membres") ?>" class="nodeco">Membres</a></li>
    <li <?=stripos($_SERVER['SCRIPT_NAME'], "questions") ? 'class="selected"' : '' ?>><a href="<?=$res->asLink("questions") ?>" class="nodeco">Questions</a></li>
  </ul>
</div>