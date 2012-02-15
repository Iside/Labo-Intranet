<table class="table table-striped table-bordered table-condensed">
  <thead>
    <tr>
      <th>ID Booster</th>
      <th>Firstname</th>
      <th>Lastname</th>
      <th>Campus</th>
      <th>Promotion</th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($users as $key => $user): ?>
      <tr>
        <td><?php print $user->id ?></td>
        <td><?php print $user->firstname ?></td>
        <td><?php print $user->lastname ?></td>
        <td><?php print Campus::find($user->campus_id)->name ?></td>
        <td><?php print $user->promotion ?></td>
      </tr>
    <?php endforeach; ?>
  </tbody>