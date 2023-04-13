void setup(void) {
    Serial.begin(9600);  // inicia comunicação com computador​
}

void loop(void) {
    int t = analogRead(0);

    Serial.print("Temperatura: ");
    Serial.print(map(t, 20, 358, -40, 125));
    Serial.println(" graus celsius");
    delay(1000);
};
