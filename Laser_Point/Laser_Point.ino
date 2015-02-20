void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(7, OUTPUT);     
}

void loop() {
  digitalWrite(7, HIGH);   // set the LED on
  delay(5000);              // wait for a second
  digitalWrite(7, LOW);    // set the LED off
  delay(1000);              // wait for a second
}
