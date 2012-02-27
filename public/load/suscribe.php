<?php
include '../inc/init.inc';
$result = "Veuillez remplir toutes les informations demandées";
if (isset($_POST['captcha']) && isset($_POST['vcaptcha'])) {
    if (md5($_POST['captcha']) == $_POST['vcaptcha']) {
        if ($_POST['id'] != "" && $_POST['password'] != "" && $_POST['re-password']) {
          if ($_POST['password'] != $_POST['re-password']) {
            $result = "Les mots de passe ne concordent pas";
          }else{
                $user = User::create(array(
                            'id' => $_POST['id'],
                            'password' => sha1($_POST['password']."h@Ck")
                        ));
                $result = "user crée";
                $res->load("index");
          }
        }
        else
            $result = "Formulaire incomplet";
    } else {
        $result = "Erreurs captcha";
    }
}
$res->campuses = Campus::find('all');
$res->nb1 = rand(1, 5);
$res->nb2 = rand(1, 5);
$res->somme = $res->nb1 + $res->nb2;
$res->captcha_crypted = md5($res->somme); 
$res->useTemplate(array('Inscription', true, false, $result), array(false));
?>