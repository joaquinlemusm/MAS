const int ldrPin = A0;
const int ledPin = 13;
unsigned long startMillis;
unsigned long currentMillis;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  startMillis = millis();
}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  if (ldrStatus <= 300) {
    digitalWrite(ledPin, HIGH);
    if (currentMillis - startMillis > 0) {
      Serial.println("Tiempo: ");
      Serial.println(currentMillis - startMillis);
    }
    startMillis = currentMillis;
  } else {
    digitalWrite(ledPin, LOW);
    currentMillis = millis();
  } 
}
