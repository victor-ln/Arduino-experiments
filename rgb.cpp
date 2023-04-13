// C++ code
//

char redPin      = 9;
char bluePin     = 10;
char greenPin    = 11;

enum e_nomes {
    RED, GREEN, BLUE,           // Primárias
    YELLOW, CYAN, MAGENTA,      // Secundárias
    ORANGE, PURPLE, LIME_GREEN  // Terciárias
};

struct s_RGB {
    char r, g, b;
};

struct s_colors {
    int     colorName; 
    s_RGB   colorCode;
};

s_colors RGB[9] = {
    {RED,           {255, 0, 0}},
    {GREEN,         {0, 255, 0}},
    {BLUE,          {0, 0, 255}},
    {YELLOW,        {255, 255, 0}},
    {CYAN,          {0, 255, 255}},
    {MAGENTA,       {255, 0, 255}},
    {ORANGE,        {255, 165, 0}},
    {PURPLE,        {128, 0, 128}},
    {LIME_GREEN,    {0, 255, 127}}
};

void customColor(int colorCode) {
    analogWrite(redPin, colorCode >> 16 & 0XFF);
    analogWrite(greenPin, colorCode >> 8 & 0XFF);
    analogWrite(bluePin, colorCode & 0XFF);
    delay(1000);
}

void turnOnRGB(int colorName) {
    analogWrite(redPin, RGB[colorName].colorCode.r);
    analogWrite(greenPin, RGB[colorName].colorCode.g);
    analogWrite(bluePin, RGB[colorName].colorCode.b);
    delay(1000);
}

void turnOffRGB(void) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(1000);
}

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
    turnOnRGB(RED);
    turnOnRGB(GREEN);
    turnOnRGB(BLUE);
    turnOnRGB(YELLOW);
    turnOnRGB(CYAN);
    turnOnRGB(MAGENTA);
    turnOnRGB(ORANGE);
    turnOnRGB(PURPLE);
    turnOnRGB(LIME_GREEN);
  	customColor(0X191970); // Midnight blue
}
