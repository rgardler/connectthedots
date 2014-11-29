// A sound level monitor using a Sunfounder Microsophone Sensor Module
// See http://www.sunfounder.com/index.php?c=case_in&a=detail_&id=139&name=
//
const int SOUND_PIN = A0;  
const int SAMPLE_FREQUENCY = 500;
int high = 0;
int hightime = millis();
int sequenceNumber = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(SOUND_PIN);
  if(high < value) {
    high = value;
  }
  if(millis() - hightime >= SAMPLE_FREQUENCY) {
    Serial.print("{");
    Serial.print('"millis":');
    Serial.print(millis());
    Serial.print(',"seqno":');
    Serial.print(sequenceNumber++);
    Serial.print(',"soundLvl:"');
    Serial.print(high);
    Serial.println("}");
    
    high = 0;
    hightime = millis();
  }
}
