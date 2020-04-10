

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
  //Serial.println("Hello World...");
  delay(2000);  // do not print too fast!
//Keyboard.print("Hello World");
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("powershell\n");
  //Keyboard.press(KEY_LEFT_CTRL);
  // Keyboard.press(KEY_LEFT_SHIFT);
  //Keyboard.print("\n");//faire ctrl+shift +entre
  delay(1000);
  digitalWrite(ledPin, LOW);
  //count = count +1;
  delay(3000);
  Keyboard.print(file_to_light);
  digitalWrite(ledPin, LOW);
  delay(10000000);
}

// the loop() methor runs over and over again,
// as long as the board has power
//int number = 1234;
/*void loop() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second
  //Serial.println("string");     // string
  //Serial.println('a');          // single character
  //Serial.println(number);       // number (base 10 if 16 or 32 bit)
  Serial.write('a');
}
*/
