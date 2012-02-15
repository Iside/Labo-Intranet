<style type="text/css">
      .error-div { padding: 10px; margin-bottom: 50px; background: #ffdfdf; border-bottom: 1px solid #ee9d9d; font-size: 13px; font-weight:bold; color:red; }
</style>

<?php if (isset($_GET['failed'])) : ?>
  <div class="error-div">Verifier les informations que vous avez entr�s</div>
<?php endif; ?>


<form action="../load/signin.php" id="auth_form" method="post">
    <div class="row">
        <div class="span4">&nbsp;</div>
        <div class="span8">
            <fieldset>
              <div class="clearfix">
                <label>ID Booster</label>
                <div class="input"><input type="text" name="login" id="login" class="text" value=""/></div>
              </div>
              <div class="clearfix">
                <label>Mot de passe</label>
                <div class="input"><input type="password" name="password" id="password" class="text" value=""/></div>
              </div>
              <div class="actions">
                <input type="submit" class="btn btn-primary" value="Connexion" />
              </div>
                <p class="help-block"> J'ai <code>oublié</code> mon mot de passe.</p>
            </fieldset>
                            

      </div>
    </div>
 </form>