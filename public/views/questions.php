<div class="span9">
              <?=$widget->load("menu")?>
              
              <div id="question" class="row-fluid">

                <div class="alert alert-block">
                  <a class="close"  data-dismiss="alert">A—</a>
                  <h4 class="alert-heading">Comment poser une question </h4>
                  Est-ce une question Ã  propos de l'informatique ? Dans ce cas...
                </div>

                <form class="form-horizontal">                  
                  <div class="box padding10">
                    <div class="control-group nomarginbottom">
                      <label class="control-label" for="textarea">Sujet</label>
                      <div class="controls">
                        <input type="text" class="nomargin" id="">
                      </div>
                    </div>
                  </div>
                  <div class="box padding10">
                    <div class="control-group nomarginbottom">
                      <label class="control-label" for="textarea"></label>
                      <div class="controls">
                        <textarea class="input-xlarge" id="textarea" rows="3" style="height: 200px;"></textarea>
                      </div>
                    </div>
                    <div class="form-actions nomarginbottom" style="margin-top: 10px">
                      <button type="submit" class="btn btn-primary">Poster ma question</button>
                    </div>
                  </div>                   
                </form>
                
              </div>

              
              
            </div>
<?=$widget->load("talk")?>