// C++ code
//

const char  firstPin    = 0;
const char  lastPin     = 9;
const int   delayTime   = 100;
int         counter, direction;

/**
 *  For each pin in the range of pins, set the pin to be an output.
 */
void setup(void) {
    for (counter = firstPin; counter != lastPin + 1; counter++) {
        pinMode(counter, OUTPUT);
    }
}

void loop(void) {

    turnOnInRange(lastPin, firstPin - 1);
    turnOffInRange(firstPin, lastPin + 1);
    turnOnInRange(firstPin, lastPin + 1);
    turnOffInRange(lastPin, firstPin - 1);

    /*  Turning on the LEDs from the middle of the strip. */
    for (counter = 0; counter < 5; counter++) {
        digitalWrite(4 - counter, HIGH);
        digitalWrite(5 + counter, HIGH);
        delay(delayTime);
    }

    /*  Turning off the LEDs to the middle of the strip. */
    for (counter = 0; counter < 5; counter++) {
        digitalWrite(lastPin - counter, LOW);
        digitalWrite(firstPin + counter, LOW);
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
        digitalWrite(first, HIGH);
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
        digitalWrite(first, LOW);
        delay(delayTime);
    }
}
