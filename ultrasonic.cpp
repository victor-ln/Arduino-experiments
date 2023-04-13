/*
 * The Ultrasonic code was created by Rui Santos,
 * https://randomnerdtutorials.com
 */

int trigPin = 11; // Trigger
int echoPin = 12; // Echo
long duration, cm, inches;

int speakerPin = 7;

void setup() {
    // Serial Port begin
    Serial.begin(9600);
    // Define inputs and outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

  	pinMode(speakerPin, OUTPUT);
}

void loop() {
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);

    // Convert the time into a distance
    cm = (duration / 2) / 29.1;    // Divide by 29.1 or multiply by 0.0343
    Serial.print(cm);
    Serial.println("cm");

    if (cm < 30) {
        playTone(1250, cm * 15);
    }
    delay(250);
}

void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(tone);
    }
}
