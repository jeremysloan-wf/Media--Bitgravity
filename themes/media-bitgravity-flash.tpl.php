<?php
// $Id$
/**
 * @file media_bitgravity/themes/media-bitgravity-flash.tpl.php
 *
 * The template file for theme('media_bitgravity_flash').
 *
 * This will display an JavaScript embedded Flash player for the video.
 *
 * Available variables:
 *  $api_functions_js => The URL for the api functions javascript file (default: http://bitcast-b.bitgravity.com/player/6/functions.js).
 *  $files => array of arrays holding file information for each bitrate desired.
 *    Each array should be keyed with each of these parameters: file, filequality, filelabel, filebitrate
 *  $mode => The mode of the video playback (One of [ondemand|live|stream]. Use "ondemand" for static video files, "live" for BitGravity's BGLiveBroadcast™ streams and "stream" for RTMP streaming.).
 *  $autoplay => If set to false, the video will not begin until the user clicks the play button.
 *  $scrubmode => One of [simple|advanced]. Advanced mode makes use of BitGravity's Advanced Progressive™ technology to allow instant scrubbing to any point in a video by making advanced requests to the server. FLV video requires pre-processing with FLVMDU. Note: Without advanced mode set, bit rate adjustments will restart the video.
 *  $flash_player_version => as of now using 9.0.115
 *  $defaultlevel => The file index on which to begin playback. 1 will start with File, 2 will start with FileQuality2, etc.
 *  $streamingserver => The URL of the RTMP streaming server.
 *  $preroll => The URL of the video file played before the main video. Playback controls are hidden.
 *  $postroll => The URL of the video file played after the main video. Playback controls are hidden.
 *  $buffertime => When video buffer empties, at least this much video will load before the player continues playing. Increase this number for fewer (though longer) download waits.
 *  $volume => A number between 0 and 1, with 0 representing mute and 1 representing full volume. This will set the initial volume, but the user will be able to adjust it in the player.
 *  $logoimage => The URL of the image displayed one of the player's corners.
 *  $logolink => Clicking the logo will take you to this URL.
 *  $logoposition => One of [topleft|topright|bottomleft|bottomright]
 *  $thumbnail => The URL of the image displayed until the video starts playing.
 *  $colorbase => The color of the control bar.
 *  $colorcontrol => The color of the controls.
 *  $colorhighlight => The color of the controls, on mouse-over.
 *  $colorfeature => The color of the scrubber and other features.
 *  $expressinstallswfurl => http://bitcast-b.bitgravity.com/player/expressInstall.swf
 *  $background => The URL of the image displayed on behind the video. Mainly visible only when the video is of unequal aspect ratio to the player.
 *  $defaultratio => The video dimensions will be set to use this ratio ONLY if the video meta data does not have built-in dimensions OR ForceRatio is set to true.
 *  $forceratio => Set to true if you want the value set in DefaultRatio to be preferred to built-in video meta data dimensions.
 *  $videofit => One of [automatic|stretch|fill]. If the video dimensions differ from that of the player, the video will be stretched according to this mode. "automatic" will proportionally stretch the video as large as is possible without hiding any part of the video. "stretch" will stretch the video to fill the player. "fill" will proportionally stretch the video to just large enough to fill the player. i.e. video may be cropped.
 *  $crossfading => Enabling cross fading will crossfade video when switching bit rates. Not recommended for HD video, or older computers.
 *  $autobitrate => One of [on|off|disabled]. Player will drop or jump to streams based on periodic connection measurements. Unless set to "disabled" this is toggleable by the user during runtime, and defaults to the value of this parameter.
 *  $allowdebug => When focus is on the player, pressing "d" will bring up a debug overlay. To disable this functionality, set AllowDebug to false.
 *  $allowinfo => When focus is on the player, pressing the "i" key will bring up some information on the player state.To disable this functionality, set AllowInfo to false.
 *  $allowgpuscaling => If system capabilities allow for hardware scaling of video, this method will be used when entering full screen mode if this parameter is set to true.
 *  $forcereconnect => Some internet browsers have difficulty storing a very long contiguous video file in memory, so setting this parameter to # will force a reconnect to the stream every # seconds. This can be set to 0 to disable the function.
 *  $disablelivecontrols => Setting this parameter to true will hide all controls (except playhead time) when viewing a BitGravity LiveBroadcast stream.
 *  $versionwarnings => Certain video features, such as h.264 support, are only available for sufficiently recent versions of Adobe Flash Player. The player will alert the end user to any version shortcomings. Set this parameter to false if you would like these warnings to be disabled.
 *  $notext => Messages such as "Buffering", "Paused", etc. can be hidden by setting this parameter to true. The buffering / connecting animation will continue to appear.
 *  $audiochannel => One of [both|left|right]. The specified channel will be duplicated to both speakers and the opposite channel will be muted. e.g. setting this to "left" will cause the left audio channel to be played in both speakers, and the right channel to be muted.
 *  $replaythumbnail => One of [on|off|url]. "on" will display the same thumbnail behind the replay button as behind the play button. "off" will display no image behind the replay button. This parameter may also be set to the URL of an alternate image.
 *  $transparentplaybutton => When AutoPlay is disabled, setting this to true will cause the full area of the player to assume the role of the large circular centered play button (which will itself be hidden). Set the Thumbnail parameter to display an image containing a play button or some other indication to click the image to start the video.
 *  $transparentreplaybutton => Setting this to true will cause the full area of the player to assume the role of the large circular centered replay button (which will itself be hidden). Set the ReplayThumbnail parameter to display an image containing a replay button or similar indication.
 *  $width => The width of the video display.
 *  $height => The height of the video display.
 *  $allowfullscreen => Enables JavaScript communication with the player.
 *  $allowscriptaccess => Enables JavaScript communication with the player.
 *  $selected_bitrate => For a multi-bitrate implementation this is an indicator of which bitrate has been selected by the user.
 */
?>
  <div id="bg_player_location">
  <a href="http://www.adobe.com/go/getflashplayer">
  <img src="http://www.adobe.com/images/shared/download_buttons/get_flash_player.gif" alt="Get Adobe Flash player" />
  </a>
  </div>
  <script type="text/javascript" src="<?php print $api_functions_js; ?>"></script>
  <script type="text/javascript">
  var flashvars = {};
  flashvars.File = "<?php print $file; ?>";
  <?php if(count($files)>1): ?>
    <?php $file_conter = 1; ?>
    <?php foreach($files as $file): ?>
      <?php if($selected_bitrate == $file['filebitrate']): ?>
        flashvars.File = "<?php print $file['file']; ?>";
        flashvars.FileBitrate = "<?php print $file['filebitrate']; ?>";
      <?php elseif: ?>
        <?php if($file_counter == 1); ?>
          flashvars.File = "<?php print $file['file']; ?>";
          flashvars.FileQuality = "<?php print $file['filequality']; ?>";
          flashvars.FileLabel = "<?php print $file['filelabel']; ?>";
          flashvars.FileBitrate = "<?php print $file['filebitrate']; ?>";
          <?php $file_counter++; ?>
        <?php elseif: ?>
          flashvars.FileQuality<?php print $file_counter; ?> = "<?php print $file['filequality']; ?>";
          flashvars.FileQuality<?php print $file_counter; ?>Label = "<?php print $file['filelabel']; ?>";
          flashvars.FileQuality<?php print $file_counter; ?>Bitrate = "<?php print $file['filebitrate']; ?>";
        <?php endif; ?>
  			flashvars.AutoBitrate = "<?php print $autobitrate; ?>";
      <?php endif; ?>
    <?php endforeach; ?>
  <?php elseif: ?>
    flashvars.File = "<?php print $files[0]['file']; ?>";
  <?php endif; ?>
  <?php if($mode): ?>
    flashvars.Mode = "<?php print $mode; ?>";
  <?php endif; ?>
  <?php if($autoplay): ?>
    flashvars.AutoPlay = "<?php print $autoplay; ?>";
  <?php endif; ?>
  <?php if($scrubmode): ?>
    flashvars.ScrubMode = "<?php print $scrubmode; ?>";
  <?php endif; ?>
  <?php if($buffertime): ?>
    flashvars.BufferTime = "<?php print $buffertime; ?>";
  <?php endif; ?>
  <?php if($videofit): ?>
    flashvars.VideoFit = "<?php print $videofit; ?>";
  <?php endif; ?>
  <?php if($crossfading): ?>
    flashvars.CrossFading = "<?php print $crossfading; ?>";
  <?php endif; ?>
  <?php if($autobitrate): ?>
    flashvars.AutoBitrate = "<?php print $autobitrate; ?>";
  <?php endif; ?>
  <?php if($allowdebug): ?>
    flashvars.AllowDebug = "<?php print $allowdebug; ?>";
  <?php endif; ?>
  <?php if($allowinfo): ?>
    flashvars.AllowInfo = "<?php print $allowinfo; ?>";
  <?php endif; ?>
  <?php if($allowgpuscaling): ?>
    flashvars.AllowGPUScaling = "<?php print $allowgpuscaling; ?>";
  <?php endif; ?>
  <?php if($forcereconnect): ?>
    flashvars.ForceReconnect = "<?php print $forcereconnect; ?>";
  <?php endif; ?>
  <?php if($disablelivecontrols): ?>
    flashvars.DisableLiveControls = "<?php print $disablelivecontrols; ?>";
  <?php endif; ?>
  <?php if($versionwarnings): ?>
    flashvars.VersionWarnings = "<?php print $versionwarnings; ?>";
  <?php endif; ?>
  <?php if($notext): ?>
    flashvars.NoText = "<?php print $notext; ?>";
  <?php endif; ?>
  <?php if($audiochannel): ?>
    flashvars.AudioChannel = "<?php print $audiochannel; ?>";
  <?php endif; ?>
  <?php if($replaythumbnail): ?>
    flashvars.ReplayThumbnail = "<?php print $replaythumbnail; ?>";
  <?php endif; ?>
  <?php if($transparentplaybutton): ?>
    flashvars.TransparentPlayButton = "<?php print $transparentplaybutton; ?>";
  <?php endif; ?>
  <?php if($transparentreplaybutton): ?>
    flashvars.TransparentReplayButton = "<?php print $transparentreplaybutton; ?>";
  <?php endif; ?>
  <?php if($defaultratio): ?>
    flashvars.DefaultRatio = "<?php print $defaultratio; ?>";
  <?php endif; ?>
  <?php if($forceratio): ?>
    flashvars.ForceRatio = "<?php print $forceratio; ?>";
  <?php endif; ?>
  <?php if($logoimage): ?>
    flashvars.LogoImage = "<?php print $logoimage; ?>";
  <?php endif; ?>
  <?php if($logolink): ?>
    flashvars.LogoLink = "<?php print $logolink; ?>";
  <?php endif; ?>
  <?php if($logoposition): ?>
    flashvars.LogoPosition = "<?php print $logoposition; ?>";
  <?php endif; ?>
  <?php if($thumbnail): ?>
    flashvars.Thumbnail = "<?php print $thumbnail; ?>";
  <?php endif; ?>
  <?php if($colorbase): ?>
    flashvars.ColorBase = "<?php print $colorbase; ?>";
  <?php endif; ?>
  <?php if($colorcontrol): ?>
    flashvars.ColorControl = "<?php print $colorcontrol; ?>";
  <?php endif; ?>
  <?php if($colorhighlight): ?>
    flashvars.ColorHighlight = "<?php print $colorhighlight; ?>";
  <?php endif; ?>
  <?php if($colorfeature): ?>
    flashvars.ColorFeature = "<?php print $colorfeature; ?>";
  <?php endif; ?>
  <?php if($background): ?>
    flashvars.Background = "<?php print $background; ?>";
  <?php endif; ?>
  <?php if($preroll): ?>
    flashvars.PreRoll = "<?php print $preroll; ?>";
  <?php endif; ?>
  <?php if($postroll): ?>
    flashvars.PostRoll = "<?php print $postroll; ?>";
  <?php endif; ?>
  <?php if($volume): ?>
    flashvars.Volume = "<?php print $volume; ?>";
  <?php endif; ?>
  var params = {};
  params.allowFullScreen = "<?php print $allowfullscreen; ?>";
  params.allowScriptAccess = "<?php print $allowscriptaccess; ?>";
  var attributes = {};
  attributes.id = "<?php print $bitgravity_player_version; ?>";
  swfobject.embedSWF(stablerelease, "bg_player_location", "<?php print $width; ?>", "<?php print $height; ?>", "<?php print $flash_player_version; ?>", "<?php print $expressinstallswfurl; ?>", flashvars, params, attributes);
  </script>
