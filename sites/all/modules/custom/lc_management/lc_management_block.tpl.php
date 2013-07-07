<div id="lcChooser">
    <div class="btn-group">
        <a class="btn dropdown-toggle" data-toggle="dropdown" href="#">
            Choose Your LC
            <span class="caret"></span>
        </a>
        <ul class="dropdown-menu">
            <?php foreach($variables['items'] as $single): ?>
            <li><a href="<?php global $base_url; echo $base_url;?>/lc/<?php echo $single['id']; ?>"> <?php echo $single['name']; ?></a></li>
            <?php endforeach; ?>        
        </ul>
    </div>
</div>