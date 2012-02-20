<!-- INSCRIPTION -->
            <div class="span4">&nbsp;</div>
            <div class="span4">
              <div class="wear form-login form-register box rounded-border row show-grid">
                <div class="title"><i class="icon-lock"></i> <strong>Inscrivez-vous</strong> au Laboratoire Cisco !</div>
                <form class="form-search nomargin">
                  <input type="text" class="input-small" name="id" placeholder="ID Booster">
                  <input type="password" class="input-small" name="password" placeholder="Mot de passe">
                  <input class="input" type="text" size="20" name="captcha" placeholder="Combien font <?php echo $nb1; ?>+<?php echo $nb2; ?>?"/>
                    <?php if (isset($result))
                  print $result; ?>
                <input type="hidden" name="vcaptcha" value="<?php echo $captcha_crypted; ?>"/>
                <div class="actions">
                    <input type="submit" class="btn large success" value="S'inscrire">
                </div>
                  <button type="submit" class="btn btn-success">Crée mon compte</button>
                </form>           
              </div>  
            </div>
            <div class="span4">&nbsp;</div>
            <!-- FIN INSCRIPTION -->