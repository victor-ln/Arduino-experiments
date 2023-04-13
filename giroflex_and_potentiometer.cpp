// C++ code
//

#define POTENTIOMETER_PORT A0

const char  firstPin    = 0;
const char  lastPin     = 9;
const char	pins[]		= {3, 5, 6, 7, 12, 13, 8, 9, 10, 11};
const int   delayTime	= 100;
int         counter, direction, potValue;

/**
 *  For each pin in the range of pins, set the pin to be an output.
 */
void setup(void) {
    for (counter = firstPin; counter < 10; counter++) {
        pinMode(pins[counter], OUTPUT);
    }
}

void loop(void) {

    potValue = map(analogRead(POTENTIOMETER_PORT), 0, 1024, 0, 255);
    if (!potValue) {
        return;
    }

    turnOnInRange(lastPin, firstPin - 1);
    turnOffInRange(firstPin, lastPin + 1);
    turnOnInRange(firstPin, lastPin + 1);
    turnOffInRange(lastPin, firstPin - 1);

    /*  Turning on the LEDs from the middle of the strip. */
    for (counter = 0; counter < 5; counter++) {
        analogWrite(pins[4 - counter], isDigitalPin(4 - counter) ? 255 : potValue);
        analogWrite(pins[5 + counter], isDigitalPin(5 + counter) ? 255 : potValue);
        delay(delayTime);
    }

    /*  Turning off the LEDs to the middle of the strip. */
    for (counter = 0; counter < 5; counter++) {
        digitalWrite(pins[lastPin - counter], LOW);
        digitalWrite(pins[firstPin + counter], LOW);
        delay(delayTime);
    }
}

/**
 *  Turn on all the LEDs in the range of first to last, with a delay of delayTime
 *  between each LED.
 * 
 * @param first the first pin to turn on
 * @param last the last LED to turn on
 */
void turnOnInRange(int first, int last) {
    direction = first < last ? 1 : -1;

    for (; first != last; first += direction) {
        analogWrite(pins[first], isDigitalPin(first) ? 255 : potValue);
        delay(delayTime);
    }
}

/**
 *  Turn on all the LEDs in the range of first to last, with a delay of delayTime
 *  between each LED.
 * 
 * @param first the first pin to turn on
 * @param last the last LED to turn on
 */
void turnOffInRange(int first, int last) {
    direction = first < last ? 1 : -1;

    for (; first != last; first += direction) {
        digitalWrite(pins[first], LOW);
        delay(delayTime);
    }
}

inline bool isDigitalPin(char pin) {
    return pin >= 3 && pin <= 6;
}
