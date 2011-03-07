<?php
// $Id:$

/**
 * @file media_bitgravity/includes/providers/bitgravity.inc
 *   Provide support for the Bitgravity provider to the emfield.module.
 */

/**
 * hook emvideo_PROVIDER_info
 * this returns information relevant to a specific 3rd party video provider
 * @return
 *   an array of strings requested by various admin and other forms
 *   'name' => the translated name of the provider
 *   'url' => the url to the main page for the provider
 *   'settings_description' => a description of the provider that will be posted in the admin settings form
 *   'supported_features' => an array of rows describing the state of certain supported features by the provider.
 *      These will be rendered in a table, with the columns being 'Feature', 'Supported', 'Notes'.
 */
function emvideo_bitgravity_info() {
  $features = array(
    array(t('Custom player color'), t('Yes'), t("You may customize the player's skin by choosing your own color.")),
    array(t('Thumbnails'), t('Yes'), t('You may set the URL of an image file to be used as the thumbnail for this video. Thumbnails are not provided by Bitgravity.')),
    array(t('Full screen mode'), t('Yes'), t('You may customize the player to enable or disable full screen playback. Full screen mode is enabled by default.')),
    array(t('Multiple Bitrate Live Stream Playback'), t('Yes'), t("You may set multiple files for each bit rate you wish to offer. If you supply more than one file the player will provide a way to select between the given streams. You may also set the default bitrate to start with.")),
    array(t('Auto Bitrate'), t('Yes'), t("One of [on|off|disabled]. Player will drop or jump to streams based on periodic connection measurements. Unless set to \"disabled\" this is toggleable by the user during runtime, and defaults to the value of this parameter.")),
    array(t('RTMP Streaming Server Support'), t('Yes'), t("Support for RTMP streaming server streams.")),
    array(t('Pre Roll and Post Roll'), t('Yes'), t("You can provide URL's for the video file played before and after the main video. Playback controls are hidden.")),
    array(t('Selectable video type modes'), t('Yes'), t("Supports on demand, live streaming and RTMP streaming.")),
    array(t('Autoplay'), t('Yes'), t("Supports turning on and off automatic playback of video.")),
    array(t('Set Buffer Time'), t('Yes'), t("The amount of buffer time before the video starts playing can be set.")),
    array(t('Set Initial Volume'), t('Yes'), t("The initial volume of the player can be set. A value between 0 (mute) and 1 (cranked up!).")),
    array(t('Select Scrub Mode'), t('Yes'), t("One of [simple|advanced]. Advanced mode makes use of BitGravity's Advanced Progressive™ technology to allow instant scrubbing to any point in a video by making advanced requests to the server. FLV video requires pre-processing with FLVMDU. Note: Without advanced mode set, bit rate adjustments will restart the video.")),
    array(t('Set Logo Image'), t('Yes'), t("The URL of the image displayed one of the player's corners.")),
    array(t('Set Logo Link'), t('Yes'), t("Clicking the logo will take you to this URL.")),
    array(t('Set Logo Position'), t('Yes'), t("Positions the logo in one of [topleft|topright|bottomleft|bottomright] positions.")),
    array(t('Background'), t('Yes'), t("The URL of the image displayed on behind the video. Mainly visible only when the video is of unequal aspect ratio to the player.")),
    array(t('Video Ratios'), t('Yes'), t("The video dimensions can be set (ex.: 16/9 or 4/3) and can set one of those dimensions to be the default ratio.")),
    array(t('Video Fit'), t('Yes'), t("One of [automatic|stretch|fill]. If the video dimensions differ from that of the player, the video will be stretched according to this mode. \"automatic\" will proportionally stretch the video as large as is possible without hiding any part of the video. \"stretch\" will stretch the video to fill the player. \"fill\" will proportionally stretch the video to just large enough to fill the player. i.e. video may be cropped.")),
    array(t('Cross Fading'), t('Yes'), t("Enabling cross fading will crossfade video when switching bit rates. Not recommended for HD video, or older computers.")),
    array(t('Debugging'), t('Yes'), t("When focus is on the player, pressing \"d\" will bring up a debug overlay. This can be turned on and off.")),
    array(t('Information Window'), t('Yes'), t("When focus is on the player, pressing the \"i\" key will bring up some information on the player state. You can turn this on and off")),
    array(t('Allow GPU Scaling'), t('Yes'), t("If system capabilities allow for hardware scaling of video, this method will be used when entering full screen mode if this parameter is set to true.")),
    array(t('Force Reconnect'), t('Yes'), t("Some internet browsers have difficulty storing a very long contiguous video file in memory, so setting this parameter to a number will force a reconnect to the stream every number of seconds. This can be disabled.")),
    array(t('Disable Live Controls'), t('Yes'), t("Setting this parameter to true will hide all controls (except playhead time) when viewing a BitGravity LiveBroadcast stream.")),
    array(t('Version Warnings'), t('Yes'), t("Certain video features, such as h.264 support, are only available for sufficiently recent versions of Adobe Flash Player. The player will alert the end user to any version shortcomings. Set this parameter to false if you would like these warnings to be disabled.")),
    array(t('Version Warnings'), t('Yes'), t("Certain video features, such as h.264 support, are only available for sufficiently recent versions of Adobe Flash Player. The player will alert the end user to any version shortcomings. Set this parameter to false if you would like these warnings to be disabled.")),
    array(t('Do Not Show Text Messages'), t('Yes'), t("Messages such as "Buffering", "Paused", etc. can be hidden by setting this parameter to true. The buffering / connecting animation will continue to appear.")),
    array(t('Set Audio Channel'), t('Yes'), t("One of [both|left|right]. The specified channel will be duplicated to both speakers and the opposite channel will be muted. e.g. setting this to \"left\" will cause the left audio channel to be played in both speakers, and the right channel to be muted.")),
    array(t('Replay Thumbnail'), t('Yes'), t("One of [on|off|url]. "on" will display the same thumbnail behind the replay button as behind the play button. "off" will display no image behind the replay button. This parameter may also be set to the URL of an alternate image.")),
    array(t('Transparent Play Button'), t('Yes'), t("When AutoPlay is disabled, setting this to true will cause the full area of the player to assume the role of the large circular centered play button (which will itself be hidden). Set the Thumbnail parameter to display an image containing a play button or some other indication to click the image to start the video.")),
    array(t('Transparent Replay Button'), t('Yes'), t("Setting this to true will cause the full area of the player to assume the role of the large circular centered replay button (which will itself be hidden). Set the ReplayThumbnail parameter to display an image containing a replay button or similar indication.")),
  );
  return array(
    'provider' => 'bitgravity',
    'name' => t('Bitgravity'),
    'url' => MEDIA_BITGRAVITY_MAIN_URL,
    'settings_description' => t('These settings specifically affect videos displayed from <a href="@provider" target="_blank">Bitgravity</a>. You can learn more about its <a href="@api" target="_blank">API</a> here. (You will need a key for any current supported features.)', array('@provider' => MEDIA_BITGRAVITY_MAIN_URL, '@api' => MEDIA_BITGRAVITY_API_INFO)),
    'supported_features' => $features,
  );
}

/**
 * hook emvideo_PROVIDER_settings
 * this should return a subform to be added to the emvideo_settings() admin settings page.
 * note that a form field will already be provided, at $form['PROVIDER'] (such as $form['bitgravity'])
 * so if you want specific provider settings within that field, you can add the elements to that form field.
 */
function emvideo_bitgravity_settings() {
  module_load_include('inc', 'media_bitgravity', 'includes/media_bitgravity.admin');
  return media_bitgravity_admin_form();
}


/**
 * hook emvideo_PROVIDER_video
 * this actually displays the full/normal-sized video we want, usually on the default page view
 *  @param $video_code
 *    the video code for the video to embed
 *  @param $width
 *    the width to display the video
 *  @param $height
 *    the height to display the video
 *  @param $field
 *    the field info from the requesting node
 *  @param $item
 *    the actual content from the field
 *  @return
 *    the html of the embedded video
 */
function emvideo_bitgravity_video($video_code, $width, $height, $field, $item, $node, $autoplay, $options = array()) {
  $options['width'] = isset($options['width']) ? $options['width'] : $width;
  $options['height'] = isset($options['height']) ? $options['height'] : $height;
  $options['autoplay'] = isset($options['autoplay']) ? $options['autoplay'] : $autoplay;
  return theme('media_bitgravity', $video_code, $options);
}

/**
 * hook emvideo_PROVIDER_video
 * this actually displays the preview-sized video we want, commonly for the teaser
 *  @param $video_code
 *    the video code for the video to embed
 *  @param $width
 *    the width to display the video
 *  @param $height
 *    the height to display the video
 *  @param $field
 *    the field info from the requesting node
 *  @param $item
 *    the actual content from the field
 *  @return
 *    the html of the embedded video
 */
function emvideo_bitgravity_preview($video_code, $width, $height, $field, $item, $node, $autoplay, $options = array()) {
  $options['width'] = isset($options['width']) ? $options['width'] : $width;
  $options['height'] = isset($options['height']) ? $options['height'] : $height;
  $options['autoplay'] = isset($options['autoplay']) ? $options['autoplay'] : $autoplay;
  return theme('media_bitgravity', $video_code, $options);
}

/**
 *  Implement hook emvideo_PROVIDER_data_version().
 */
function emvideo_bitgravity_data_version() {
  return MEDIA_BITGRAVITY_DATA_VERSION;
}

/**
 * Implement hook_emvideo_PROVIDER_data().
 */
function emvideo_bitgravity_data($field, $item) {
  return media_bitgravity_data($item['value']);
}

/**
 * hook emvideo_PROVIDER_duration($item)
 * Returns the duration of the video in seconds.
 *  @param $item
 *    The video item itself, which needs the $data array.
 *  @return
 *    The duration of the video in seconds.
 */
function emvideo_bitgravity_duration($item) {
  return media_bitgravity_duration($item['value']);
}
