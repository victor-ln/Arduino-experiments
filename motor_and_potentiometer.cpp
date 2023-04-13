// C++ code
//

const char base = 3;
const char potentiometer = A0;

void setup(void) {
  	Serial.begin(9600);
    pinMode(base, OUTPUT);
}

void loop(void) {
    int potValue = analogRead(potentiometer);
    analogWrite(base, map(potValue, 0, 1024, 0, 255));
    delay(1000);
}
