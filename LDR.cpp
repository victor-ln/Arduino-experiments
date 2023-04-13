// C++ code
//

void setup(void) {
 	Serial.begin(9600);
    pinMode(3, OUTPUT);
}

void loop(void) {
    int luz = analogRead(0);
    Serial.println(luz);
    analogWrite(3, map(luz, 61, 979, 0, 255));
    delay(500);
}
