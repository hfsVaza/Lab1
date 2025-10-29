const int ledPin = LED_BUILTIN;
const int potPin = A1; // potentiometer
void setup () {
pinMode(LedPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalwrite(ledPin, HIGH); // LED on 
delay (500) ;
digitalwrite(ledPin, LOW); // LED off 
delay (500);

int potValue = analogRead(potPin); // 0-4095
Serial.print( "Potentiometer value: ");
Serial.println(potValue) ;
delay(500); // cycles around 1 second
