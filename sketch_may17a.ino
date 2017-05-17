const int analogPin =A0;
const int ledCount = 10;
int ledPins[] = {2,3,4,5,6,7,8,9,10,11};

void setup() {
  // put your setup code here, to run once:
  for(int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins[thisLed], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int f = 500;
  int sensorReading = analogRead(analogPin);
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
  for(int thisLed = ledLevel; thisLed < 10-ledLevel; thisLed++){
    digitalWrite(ledPins[thisLed], HIGH);
    delay(15);
    Serial.println(ledLevel);
    delay(1);
  }
  for(int thisLed = ledLevel; thisLed < 10-ledLevel; thisLed++){
    digitalWrite(ledPins[thisLed], LOW);
    delay(15);
  }
}
