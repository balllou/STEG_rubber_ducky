/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html
 
   This example code is in the public domain.
*/
#include <Keyboard.h>

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int ledPin = 13;

// the setup() method runs once, when the sketch starts
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
void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // USB is always 12 Mbit/sec
  Keyboard.begin();
}
//int count = 0;

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
  Keyboard.print(fr2en("cmd"));
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.print("\n");//faire ctrl+shift +entre
  Keyboard.releaseAll();
  delay(1000);
  digitalWrite(ledPin, LOW);
  //count = count +1;
  delay(3000);
//  Keyboard.print("Simulation deuxxième envoie mot de passe");
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
