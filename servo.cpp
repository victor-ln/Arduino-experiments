// C++ code
//

#include <Servo.h>

#define SERVO_PORT 3

Servo myServo;

void setup(void) {
    Serial.begin(9600);
    myServo.attach(SERVO_PORT, 500, 2500);
}

void loop(void) {
    int val = analogRead(0);
    int x = map(val, 0, 1023, 0, 180);

    Serial.print(val);
    Serial.print(" - ");
    Serial.println(x);
    myServo.write(x);
    delay(10);
}
