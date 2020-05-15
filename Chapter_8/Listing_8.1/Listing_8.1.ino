
void setup() {
    // D11, D12 and D13 are outputs. (Using Arduino
    // Language constructs here.)
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    
    // Initialise Timer/counter 2 in normal mode
    // with prescaler of 1024.
    TCCR2A = 0;

    // Enable overflow interrupt (on D13 = PB5),
    // OCR0A match interrupt (on D12 = PB4) and
    // OCR0B match interrupt (on D11 = PB3).
    TIMSK2 = ((1 << OCIE2B) | (1 << OCIE2A) | (1 << TOIE2));

    // Set up the compare values.
    OCR2A = 8;
    OCR2B = 172;

    // Prescale by 1024, and start the timer.
    TCCR2B = ((1 << CS22) | (1 << CS21) | (1 << CS20));

    // D11, D12 and D13 are outputs. (Using Arduino
    // Language constructs here.)
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
}


void loop() {
    // Nothing happening here, move along now!
}


// Toggle pin D13 which is PortB pin 5. I'm using
// AVR speak here.
ISR(TIMER2_OVF_vect) {
    // Fast pin toggle.
    PINB |= (1 << PINB5);
}

// Toggle pin D12 which is PortB pin 4. I'm using
// AVR speak here.
ISR(TIMER2_COMPA_vect) {
    // Fast pin toggle.
    PINB |= (1 << PINB4);
}

// Toggle pin D13 which is PortB pin 3. I'm using
// AVR speak here.
ISR(TIMER2_COMPB_vect) {
    // Fast pin toggle.
    PINB |= (1 << PINB3);
}


