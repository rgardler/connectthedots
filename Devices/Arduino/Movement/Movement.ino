// Detect movement using a PIR detector.
// Send a "movement: 1" message when movement starts and "movement: 0" when it stops
//
const int PIR_PIN = 7;
const int SAMPLE_FREQUENCY = 250;
boolean moving;
int sequenceNumber = 0;
  
void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  long now = millis();
  if (digitalRead(PIR_PIN) == HIGH) {
    if (!moving) {
      moving = true;
      Serial.print("{");
      Serial.print("\"millis\":");
      Serial.print(millis());
      Serial.print(",\"seqno\":");
      Serial.print(sequenceNumber++);
      Serial.print(",\"movement\":");
      Serial.print(true);
      Serial.println("}");
    }
  } else {
    if (moving) {
      moving = false;
      
      Serial.print("{");
      Serial.print("\"millis\":");
      Serial.print(millis());
      Serial.print(",\"seqno\":");
      Serial.print(sequenceNumber++);
      Serial.print(",\"movement\":");
      Serial.print(false);
      Serial.println("}");
    }
  }
  delay(SAMPLE_FREQUENCY);
}

