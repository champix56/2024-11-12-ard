/**
* valeur volatile pour access par interruption
*/
volatile bool isClicked=false; 
/**
* fonction pour interruption materielle
*/
void InterruptFunction(){
  noInterrupts();
  isClicked=true;
  Serial.println("ISR");
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
  Serial.println("DEMAT BREIZH");
  attachInterrupt(digitalPinToInterrupt(3), InterruptFunction, RISING);
}

// the loop function runs over and over again forever
void loop() {

  if (isClicked) {
    uint16_t value = analogRead(A0);
    uint16_t delayTime = map(value, 0, 1023, 250, 4000);
    Serial.print("temps d'attente entre les changements:");
    Serial.print(delayTime);
    Serial.println("ms");
    blink(LED_BUILTIN, delayTime);
    isClicked=false;
    interrupts();
  }
  delay(5000);
}

void blink(int pin, uint8_t delayTime) {
  digitalWrite(pin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(delayTime);         // wait for a second
  digitalWrite(pin, LOW);   // turn the LED off by making the voltage LOW
  delay(delayTime);         // wait for a second
}
