<div class="container">
    <div class="hero-unit">
        <img src="<?php print IMG_PATH ?>banniere.jpg"/>
        <input type="button" onclick="document.location = 'suscribe.php'" class="btn btn-primary btn-large" style="padding: 20px; font-size: 20px;" value="Inscrivez-vous !">
    </div>
    <div class="row">
        <div class="span4">
            <h2>Talk</h2>
            Essaies en cours....
            <div class="span4">
                <h2>Talk</h2>
                <!--<iframe src="../common/inc/snippets/chat" width="280px" height="440px"></iframe>-->
            </div>
        </div>
        <div class="span4">
            <h2>Les membres</h2>
            <p>Ici, vous pouvez consulter la liste des membres. Actuellement nous comptons <?php print User::count() ?> membres. </p>
            <p><a href="<?php echo Template::asLink('membres')?>" class="btn">Liste des membres</a></p>
        </div>
        <div class="span4">
            <h2>Les activites</h2>
            <p>Ici, vous pouvez consulter la liste des activites disponibles. Actuellement nous comptons <?php /* print Activitiy::count() */ ?> activites. </p>
            <p><a href="#" class="btn">Voir les activites</a></p>
        </div>
    </div>
</div>