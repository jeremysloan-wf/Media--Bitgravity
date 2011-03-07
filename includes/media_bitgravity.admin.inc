<?php
// $Id:$

/**
 * @file media_bitgravity/includes/media_bitgravity.admin.inc
 * Administrative functions for Media: Bitgravity.
 */

/**
 * The administrative settings form for Media: Bitgravity.
 */
function media_bitgravity_settings() {
  $form = media_bitgravity_admin_form();
  $form['settings_info'] = array(
    '#type' => 'item',
    '#value' => t('These settings specifically affect videos displayed from !bitgravity. You can also read more about its !api.', array('!bitgravity' => l(t('Bitgravity.com'), MEDIA_BITGRAVITY_MAIN_URL, array('attributes' => array('target' => '_blank'))), '!api' => l(t("developer's API"), MEDIA_BITGRAVITY_API_INFO, array('attributes' => array('target' => '_blank'))))),
    '#weight' => -10,
  );
  return system_settings_form($form);
}

/**
 * This form will be displayed both at /admin/settings/media_bitgravity and
 * admin/content/emfield.
 */
function media_bitgravity_admin_form() {
  $form['video_source'] = array(
    '#type' => 'fieldset',
    '#title' => t('Video Source'),
    '#description' => t('Set file information for each file you want to play.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['video_source']['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#multiple' => FALSE,
    '#description' => t('Use \"ondemand\" for static video files, \"live\" for BitGravity\'s BGLiveBroadcast™ streams and \"stream\" for RTMP streaming.'),
    '#options' => array("ondemand", "live", "stream"),
    '#default_value' => "ondemand",
  );
  $form['video_source']['file'] = array(
    '#type' => 'textfield',
    '#title' => t('File'),
    '#description' => t('The URL of the video file you wish to play. If you have multiple streams the highest quality bitrate stream should be the first one you enter.'),
  );
  $form['video_source']['file_label'] = array(
    '#type' => 'textfield',
    '#title' => t('File Label'),
    '#description' => t('When connecting to multiple streams, a label should be set for each to appear in the player\'s bit rate menu. Example: High Banwidth'),
  );
  $form['video_source']['file_bit_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('File Bit Rate'),
    '#description' => t('When connecting to multiple streams, a bit rate in Kbps should be set for each. Example: 400'),
  );
  $form['video_source']['default_file'] = array(
    '#type' => 'textfield',
    '#title' => t('Default File'),
    '#description' => t('Enter the URL of the file you want to be the default to begin playback. Will Default to the first one if you do not enter one here.'),
  );
  $form['video_source']['streaming_server'] = array(
    '#type' => 'textfield',
    '#title' => t('RTMP Streaming Server URL'),
    '#description' => t('The URL of the RTMP streaming server.'),
  );
  
  $form['playback_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Playback Options'),
    '#description' => t(''),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['playback_options']['auto_play'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto Play'),
    '#description' => t('Begin playback automatically. If not checked, the video will not begin until the user clicks the play button.'),
    '#default_value' => 0,
  );
  $form['playback_options']['buffer_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Buffer Time'),
    '#description' => t('When video buffer empties, at least this many seconds of video will load before the player continues playing. Increase this number for fewer (though longer) download waits.'),
    '#default_value' => '1.5',
    '#prefix' => 'Preload (buffer) up to '
    '#suffix' => 'seconds of video.'
  );
  $form['playback_options']['scrub_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Scrub Mode'),
    '#description' => t('Advanced mode makes use of BitGravity\'s Advanced Progressive™ technology to allow instant scrubbing to any point in a video by making advanced requests to the server. FLV video requires pre-processing with FLVMDU. <strong>Note: Without advanced mode set, bit rate adjustments will restart the video.</strong>'),
    '#options' => array("simple", "advanced"),
    '#default_value' => "simple",
  );
  $form['playback_options']['cross_fading'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cross Fading'),
    '#description' => t('Enabling cross fading will crossfade video when switching bit rates. <strong>Not recommended for HD video, or older computers.</strong>'),
    '#default_value' => 0,
  );
  $form['playback_options']['auto_bit_rate'] = array(
    '#type' => 'radios',
    '#title' => t('Auto Bit Rate'),
    '#description' => t('Player will drop or jump to streams based on periodic connection measurements. Unless set to "disabled" this is toggleable by the user during runtime, and defaults to the value of this parameter.'),
    '#options' => array("on", "off", "disabled"),
    '#default_value' => "disabled",
  );
  $form['playback_options']['allow_gpu_scaling'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow GPU Scaling'),
    '#description' => t('If system capabilities allow for hardware scaling of video, this method will be used when entering full screen mode if this parameter is set to true.'),
    '#default_value' => 0,
  );
  $form['playback_options']['force_reconnect'] = array(
    '#type' => 'textfield',
    '#title' => t('Force Reconnect'),
    '#description' => t('Some internet browsers have difficulty storing a very long contiguous video file in memory, so setting this parameter to a number of seconds will force a reconnect to the stream every X number of seconds. This can be set to 0 to disable the function.'),
    '#default_value' => 1800,
  );
  $form['playback_options']['audio_channel'] = array(
    '#type' => 'radios',
    '#title' => t('Audio Channel'),
    '#description' => t('The specified channel will be duplicated to both speakers and the opposite channel will be muted. e.g. setting this to "left" will cause the left audio channel to be played in both speakers, and the right channel to be muted.'),
    '#options' => array("both", "left", "right"),
    '#default_value' => "both",
  );
  
  $form['player_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Player Configuration'),
    '#description' => t('Player height should allow 20 for control bar'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['player_configuration']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('The width of the player.'),
    '#size' => 7,
    '#maxlength' => 255,
  );
  $form['player_configuration']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Allow 20 extra pixels for the control bar.'),
    '#size' => 7,
    '#maxlength' => 255,
  );
  $form['player_configuration']['force_ratio'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use my video\'s built in aspect ratio'),
    '#default_value' => 1,
  );
  $form['player_configuration']['dimensions'] = array(
    '#type' => 'select',
    '#title' => t('Dimensions'),
    '#description' => t('Specify a fixed aspect ratio if you are not using the default aspect ratio.'),
    '#options' => array("16/9", "4/3"),
    '#default_value' => "16/9",
  );
  $form['player_configuration']['default_scale_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Default Scale Mode'),
    '#description' => t('If the video dimensions differ from that of the player, the video will be stretched according to this mode. "automatic" will proportionally stretch the video as large as is possible without hiding any part of the video. "stretch" will stretch the video to fill the player. "fill" will proportionally stretch the video to just large enough to fill the player. i.e. video may be cropped. Viewers may switch between these during playback. Choose the default below.'),
    '#options' => array("automatic", "stretch", "fill"),
    '#default_value' => "automatic",
  );
  $form['player_configuration']['volume'] = array(
    '#type' => 'select',
    '#title' => t('Volume'),
    '#multiple' => TRUE,
    '#description' => t('A number between 0 and 1, with 0 representing mute and 1 representing full volume. This will set the initial volume, but the user will be able to adjust it in the player.'),
    '#options' => array("0", "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9", "1"),
    '#default_value' => "1",
  );
  $form['player_configuration']['background'] = array(
    '#type' => 'textfield',
    '#title' => t('Background'),
    '#description' => t('The URL of the image displayed on behind the video. Mainly visible only when the video is of unequal aspect ratio to the player.'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['player_configuration']['disable_live_controls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Live Controls'),
    '#default_value' => 0,
    '#description' => t('Setting this parameter to true will hide all controls (except playhead time) when viewing a BitGravity LiveBroadcast stream.'),
  );
  $form['player_configuration']['version_warnings'] = array(
    '#type' => 'checkbox',
    '#title' => t('Version Warnings'),
    '#default_value' => 0,
    '#description' => t('Certain video features, such as h.264 support, are only available for sufficiently recent versions of Adobe Flash Player. The player will alert the end user to any version shortcomings. Set this parameter to false if you would like these warnings to be disabled.'),
  );
  $form['player_configuration']['no_text'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide Message Text'),
    '#default_value' => 0,
    '#description' => t('Messages such as "Buffering", "Paused", etc. can be hidden by setting this parameter to true. The buffering / connecting animation will continue to appear.'),
  );
  
  
  
  $form['player_theme'] = array(
    '#type' => 'fieldset',
    '#title' => t('Player Theme'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['player_theme']['color_base'] = array(
    '#type' => 'textfield',
    '#title' => t('Control Bar'),
    '#size' => 7,
    '#maxlength' => 255,
  );
  $form['player_theme']['color_control'] = array(
    '#type' => 'textfield',
    '#title' => t('Color of Controls'),
    '#size' => 7,
    '#maxlength' => 255,
  );
  $form['player_theme']['color_highlight'] = array(
    '#type' => 'textfield',
    '#title' => t('Color of Controls on Mouse-over'),
    '#size' => 7,
    '#maxlength' => 255,
  );
  $form['player_theme']['color_feature'] = array(
    '#type' => 'textfield',
    '#title' => t('Color of Scrubber & Other Features'),
    '#size' => 7,
    '#maxlength' => 255,
  );
  $form['player_theme']['logo_image'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo Image'),
    '#description' => t('The URL of the image displayed one of the player\'s corners.'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['player_theme']['logo_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo Link'),
    '#description' => t('Clicking the logo will take you to this URL.'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['player_theme']['logo_position'] = array(
    '#type' => 'select',
    '#title' => t('Logo Position'),
    '#multiple' => FALSE,
    '#description' => t('The position of the logo in the video window.'),
    '#options' => array("Top Left"=>"topleft", "Top Right"=>"topright", "Bottom Left"=>"bottomleft", "Bottom Right"=>"bottomright"),
    '#default_value' => "topleft",
  );
  $form['player_theme']['thumbnail'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail'),
    '#description' => t('The URL of the image displayed until the video starts playing.'),
  );
  $form['player_theme']['replay_thumbnail'] = array(
    '#type' => 'textfield',
    '#title' => t('Replay Thumbnail'),
    '#description' => t('One of [on|off|url]. "on" will display the same thumbnail behind the replay button as behind the play button. Entering "off" will display no image behind the replay button. If you know the URL of the image you want to use, enter it in the field.'),
    '#default_value' => "on",
  );
  //TODO: Check the current value of Auto Play and indicate it here in the description.
  $form['player_theme']['transparent_play_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Transparent Play Button'),
    '#description' => t('When AutoPlay is disabled, setting this to true will cause the full area of the player to assume the role of the large circular centered play button (which will itself be hidden). Set the Thumbnail parameter to display an image containing a play button or some other indication to click the image to start the video.'),
    '#default_value' => 0,
  );
  $form['player_theme']['transparent_replay_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Transparent Replay Button'),
    '#description' => t('Setting this to true will cause the full area of the player to assume the role of the large circular centered replay button (which will itself be hidden). Set the Replay Thumbnail parameter to display an image containing a replay button or similar indication.'),
    '#default_value' => 0,
  );
  
  $form['advertising'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advertising'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['advertising']['preroll'] = array(
    '#type' => 'textfield',
    '#title' => t('Preroll'),
    '#description' => t('The URL of the video file played before the main video. Playback controls are hidden.'),
  );
  $form['advertising']['postroll'] = array(
    '#type' => 'textfield',
    '#title' => t('Postroll'),
    '#description' => t('The URL of the video file played after the main video. Playback controls are hidden.'),
  );
  
  $form['development_testing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development & Testing'),
    '#description' => t('These tools are meant for development and testing purposes only. Do not use on Production sites.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['development_testing']['allow_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow Debug'),
    '#description' => t('When focus is on the player, pressing "d" will bring up a debug overlay. To disable this functionality, set AllowDebug to false.'),
    '#default_value' => 0,
  );
  $form['development_testing']['open_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open Debug on Start'),
    '#description' => t('Opens the debug window by default on player start.'),
    '#default_value' => 0,
  );
  $form['development_testing']['allow_info'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow Info'),
    '#description' => t('When focus is on the player, pressing the "i" key will bring up some information on the player state. To disable this functionality, set Allow Info to false.'),
    '#default_value' => 1,
  );
  
  return $form;
}
