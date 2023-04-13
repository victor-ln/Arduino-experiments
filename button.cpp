// C++ code
//

const char led		= 2;
const char button	= 3;

void setup(void) {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
}

void loop(void) {
    if (digitalRead(button) == 1) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }
    delay(500);
}
