void setup() {   
    // Initialise Timer/counter 2 in normal mode
    // with OC2A (D11) and OC2B (D3) toggling on match.
    TCCR2A = ((1 << COM2A0) | (1 << COM2B0));

    // Enable overflow interrupt (on D13 = PB5),
    TIMSK2 = (1 << TOIE2);

    // Set up the compare values.
    OCR2A = 8;
    OCR2B = 172;

    // Prescale by 1024, and start the timer.
    TCCR2B = ((1 << CS22) | (1 << CS21) | (1 << CS20));
	
    // D11, D12 and D13 are outputs. (Using Arduino
    // Language constructs here.)
    pinMode(13, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(3, OUTPUT);
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


