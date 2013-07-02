<?php

/**
 * @file
 * flippy.tpl.php
 *
 * Theme implementation to display a simple pager.
 *
 * Default variables:
 * - $first_link: A formatted <A> link to the first item.
 * - $previous_link: A formatted <A> link to the previous item.
 * - $next_link: A formatted <A> link to the next item.
 * - $last_link: A formatted <A> link to the last item.
 *
 * Other variables:
 * - $current['nid']: The Node ID of the current node.
 * - $first['nid']: The Node ID of the first node.
 * - $prev['nid']: The Node ID of the previous node.
 * - $next['nid']: The Node ID of the next node.
 * - $last['nid']: The Node ID of the last node.
 *
 * - $current['title']: The Node title of the current node.
 * - $first['title']: The Node title of the first node.
 * - $prev['title']: The Node title of the previous node.
 * - $next['title']: The Node title of the next node.
 * - $last['title']: The Node title of the last node.
 *
 * @see template_preprocess_flippy()
 */
?>
<ul class="flippy">
	<?php if (empty($previous_link)): ?><li class="first"><?php print '<a href="'.$first_url.'">‹</a>'; ?></li><?php endif; ?>
	<?php if (!empty($previous_link)): ?><li class="previous"><?php print '<a href="'.$prev_url.'">‹</a>'; ?></li><?php endif; ?>
	<?php if (!empty($portfolio)): ?><li class="home"><?php print '<a href="'.$portfolio.'"></a></li>'; ?><?php endif; ?>
	<?php if (!empty($next_link)): ?><li class="next"><?php print '<a href="'.$next_url.'">›</a>'; ?></li><?php endif; ?>
	<?php if (empty($next_link)): ?><li class="last"><?php print '<a href="'.$last_url.'">›</a>'; ?></li><?php endif; ?>
</ul>
