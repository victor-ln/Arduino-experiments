// C++ code
//

#define PED_TIME 6000
#define CAR_TIME 10000

const char      g_carLeds[3] = {11, 12, 13};
const char      g_pedLeds[2] = {8, 9};
const char      g_buttonPin = 2;
volatile int    g_speedUp = 0;
volatile bool   g_carTurn = true;

void handleInterrupt() {
    g_speedUp = 1500;
}

void setup() {
    pinMode(g_pedLeds[0], OUTPUT);
    pinMode(g_pedLeds[1], OUTPUT);
    pinMode(g_carLeds[0], OUTPUT);
    pinMode(g_carLeds[1], OUTPUT);
    pinMode(g_carLeds[2], OUTPUT);
    pinMode(g_buttonPin, INPUT_PULLUP);
    digitalWrite(g_pedLeds[1], HIGH);
}

void loop() {
    changeCarLeds();
    changeCarLeds();
    changePedLeds();
}

void changeCarLeds(void) {
    int time;

    time = CAR_TIME;
    if (g_carTurn) {
        enableButton();
        digitalWrite(g_carLeds[2], LOW);
        digitalWrite(g_carLeds[0], HIGH);
        g_speedUp = 0;
      	while (time > 0) {
            delay(500);
            time -= 500 + g_speedUp;
        }
        disableButton();
    } else {
        for (int i = 0; i < 2; i++) {
            digitalWrite(g_carLeds[i], LOW);
            digitalWrite(g_carLeds[i + 1], HIGH);
            delay(1500);
        }
    }
    g_carTurn = false;
}

/**
 * It turns on the first LED, waits 4.5 seconds, turns off the first LED, and then
 * blinks the second LED for the remaining time
 */
void changePedLeds(void) {
    int time = PED_TIME;

    digitalWrite(g_pedLeds[1], LOW);
    digitalWrite(g_pedLeds[0], HIGH);
    delay(4500);
    time -= 4500;
    digitalWrite(g_pedLeds[0], LOW);
    byte state = HIGH;
    while (time > 0) {
        digitalWrite(g_pedLeds[1], state);
        state = !state;
        delay(250);
        time -= 250;
    }
    digitalWrite(g_pedLeds[1], HIGH);
    g_carTurn = true;
}

inline void enableButton(void) {
    attachInterrupt(digitalPinToInterrupt(g_buttonPin), handleInterrupt, FALLING);
}

inline void disableButton(void) {
    detachInterrupt(digitalPinToInterrupt(g_buttonPin));
}
