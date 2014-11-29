// A sound level monitor using a Sunfounder Microsophone Sensor Module
// See http://www.sunfounder.com/index.php?c=case_in&a=detail_&id=139&name=
//
const int LED_PIN = 13; //the led attach to 
const int SOUND_PIN = A0;  
const int SAMPLE_FREQUENCY = 500;
int high = 0;
int hightime;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(SOUND_PIN);
  if(high < value) {
    high = value;
    hightime = millis();
  }
  if(millis() - hightime >= SAMPLE_FREQUENCY) {
    Serial.println(high);
    high = 0;
  }
}
