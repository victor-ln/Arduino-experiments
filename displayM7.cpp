// C++ code
//

const char pinA = 13;
const char pinB = 12;
const char pinC = 11;
const char pinD = 10;
const char pinE = 9;
const char pinF = 8;
const char pinG = 7;

void setup(void) {
    Serial.begin(9600);
    for (int i = 6; i < 14; i++) {
        pinMode(i, OUTPUT);
    }
}

void printNumber(char nbr) {
    for (int i = 6; i < 14; i++) {
        digitalWrite(i, LOW);
    }
    if (nbr != 1 && nbr != 4) {
        digitalWrite(pinA, HIGH);
    }
    if (nbr >= 0 && nbr <= 9 && nbr != 5 && nbr != 6) {
        digitalWrite(pinB, HIGH);
    }
    if (nbr >= 0 && nbr <= 9 && nbr != 2) {
        digitalWrite(pinC, HIGH);
    }
    if (nbr != 1 && nbr != 4 && nbr != 7) {
        digitalWrite(pinD, HIGH);
    }
    if (nbr < 0 || nbr > 9 || (nbr % 2 == 0 && nbr != 4)) {
        digitalWrite(pinE, HIGH);
    }
    if (nbr <= 0 || (nbr >= 4 && nbr != 7)) {
        digitalWrite(pinF, HIGH);
    }
    if (nbr < 0 || nbr >= 8 || (nbr <= 6 && nbr >= 2)) {
        digitalWrite(pinG, HIGH);
    }
}

void loop(void) {
    for (int nbr = 0; nbr <= 10; nbr++) {
        printNumber(nbr);
        delay(1000);
    }
}
