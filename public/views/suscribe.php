<div class="row">
    <div class="span4">&nbsp;</div>
    <div class="span8">
        <form action="" method="POST" enctype="multipart/form-data">
            <fieldset>
                <legend>Inscription - Tout les champs sont requis</legend>
                <div class="clearfix">
                    <label>Prenom</label>
                        <div class="input"><input type="text" name="firstname"/></div>
                </div>
                <div class="clearfix">
                    <label>Nom</label>
                    <div class="input"><input type="text" name="lastname"/></div>
                </div>
                <div class="clearfix">
                    <label>Email</label>
                    <div class="input"><input type="text" name="email"/></div>
                </div>
                <div class="clearfix">
                    <label>ID Booster</label>
                    <div class="input"><input type="text" name="id"/></div>
                </div>
                <div class="clearfix">
                    <label>Campus</label>
                    <div class="input">
                        <select name="campus" id="Select">
                            <option value="">--------</option>
                            <?php foreach ($campuses as $campus):?>
                            <option value="<?php print $campus->id?>"><?php print $campus->name?></option>
                            <?php endforeach;?>
                        </select>
                    </div>
                </div>
                <div class="clearfix">
                    <label>Departement Souhaite</label>
                    <div class="input">
                        <select name="dpt" id="mediumSelect">
                            <option value="0">Robotique</option>
                            <option value="1">Intelligence Artificielle</option>
                            <option value="2">Competition</option>
                        </select>
                    </div>
                </div>
                <div class="clearfix">
                    <label>Promotion Supinfo</label>
                    <div class="input"><input type="text" name="promotion"/></div>
                </div>
                <div class="clearfix">
                    <label>Mot de passe</label>
                    <div class="input"><input type="password" name="password"/></div>
                </div>
                <div class="clearfix">
                    <label>Photo de Profil</label>
                    <div class="input-file"><input type="file" name="picture"/></div>
                </div>
                <div class="clearfix">
                    <label>Un petit message pour vous décrire?</label>
                    <div class="input">
                        <textarea r ows="2" cols="20" name="description">
                        </textarea> 
                    </div>
                </div>
                <div>
                    <b>Combien font <?php echo $nb1; ?>+<?php echo $nb2; ?>?</b>
                    <div class="input">
                        <input class="input" type="text" size="20" name="captcha" style="width: 30px; margin-right: 10px;"/>
                    </div>
                </div>
                <?php if (isset($result))
                    print $result; ?>
                <input type="hidden" name="vcaptcha" value="<?php echo $captcha_crypted; ?>"/>
                <div class="actions">
                    <input type="submit" class="btn large success" value="S'inscrire">
                </div>
            </fieldset>
        </form>
    </div>
    <div class="span4">&nbsp;</div>
</div>
</form>
</div>