void setup(void) {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop(void) {
    int pot = analogRead(0);

    Serial.println(pot);
    digitalWrite(13, HIGH);
    delay(pot);
    digitalWrite(13, LOW);
    delay(pot);
}
