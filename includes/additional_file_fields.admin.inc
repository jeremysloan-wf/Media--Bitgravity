$form['file(s)']['file'] = array(
    '#type' => 'textfield',
    '#title' => t('File'),
    '#description' => t('The URL of the video file you wish to play. If you have multiple streams the highest quality bitrate stream should be the first one you enter.'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['file(s)']['file_label'] = array(
    '#type' => 'textfield',
    '#title' => t('File Label'),
    '#description' => t('When connecting to multiple streams, a label should be set for each to appear in the player\'s bit rate menu. Example: High Banwidth'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['file(s)']['file_bit_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('File Bit Rate'),
    '#description' => t('When connecting to multiple streams, a bit rate in Kbps should be set for each. Example: 400'),
    '#size' => 40,
    '#maxlength' => 255,
  );