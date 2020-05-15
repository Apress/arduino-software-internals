void setup() {
    // Initialise Timer/counter 2 in CTC mode. (Mode 2)
    // with OC2A (D11) and OC2B (D3) toggling on match.
    TCCR2A = ((1 << WGM21) | (1 << COM2A0) | (1 << COM2B0));

    // Disable interrupts on Timer 2.
    TIMSK2 = 0;

    // Set up the compare values. OCR2A defines the frequncy of both.
    OCR2A = 200;
    OCR2B = 86;

    // Prescale by 1024, and start the timer.
    TCCR2B = ((1 << CS22) | (1 << CS21) | (1 << CS20));

    // D11 and D12 are outputs. (Using Arduino
    // Language constructs here.)
    pinMode(11, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
    // Toggle D13 and use a delay().
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
}


