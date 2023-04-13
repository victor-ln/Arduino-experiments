void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop() {
    int x = Serial.available();
    Serial.println(x);
    if (x > 0) {
        int dado = Serial.read();
        if (dado == '1') {
            digitalWrite(13, HIGH);
        }
        if (dado == '2') {
            digitalWrite(12, HIGH);
        }
        if (dado == '3') {
            digitalWrite(11, HIGH);
        }
        if (dado == 'A') {
            digitalWrite(13, LOW);
        }
        if (dado == 'B') {
            digitalWrite(12, LOW);
        }
        if (dado == 'C') {
            digitalWrite(11, LOW);
        }
    }
    delay(500);
}
