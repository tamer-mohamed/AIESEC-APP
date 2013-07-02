<?php 
$imgpath = file_load($information['bg_img'])->uri;
$imgpath = file_create_url($imgpath);
$logo = file_load($information['logo'])->uri;
$logo = file_create_url($logo);
?>
<div style="background:url('<?php echo $imgpath ?>');padding:10px">
    <div>
        <img src="<?php echo $logo ?>" height="50"/>
    </div>
    <div>
        Facebook : <a href="<?php echo $information['facebook'];?>"><?php echo $information['facebook'];?></a> <br/>
         Twitter : <a href="<?php echo $information['twitter'];?>"><?php echo $information['twitter'];?></a> <br/>
         Youtube : <a href="<?php echo $information['youtube'];?>"><?php echo $information['youtube'];?></a> <br/>
        <br/><br/>
        Desc:<br /><br /><?php echo $information['description'];?> <br/>
    </div>
</div>