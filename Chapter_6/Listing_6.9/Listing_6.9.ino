void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    for (short x = 0; x < 4; x++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(150);
        digitalWrite(LED_BUILTIN, LOW);
        delay(150);
    }

    delay(500);
}