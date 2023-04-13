// C++ code
//

void setup(void) {
    Serial.begin(9600);
    pinMode(2, INPUT);
    pinMode(13, OUTPUT);
}

void loop(void) {
    int sensorValue = digitalRead(2);
    Serial.println(sensorValue);
    if (sensorValue == 1) {
       digitalWrite(13, HIGH);
    } else {
       digitalWrite(13, LOW);
    }
    delay(100);
}
