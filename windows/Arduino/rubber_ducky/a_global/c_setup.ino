// the setup() method runs once, when the sketch starts

void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // USB is always 12 Mbit/sec
  Keyboard.begin();
}
