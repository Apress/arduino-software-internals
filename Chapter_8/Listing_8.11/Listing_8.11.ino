#define PWM_A_LOW (~(1 << PORTD5))
#define PWM_A_HIGH ((1 << PORTD5))
#define PWM_B_LOW (~(1 << PORTD6))
#define PWM_B_HIGH ((1 << PORTD6))


void setup() {
	// Set Timer 0 into Fast PWM mode 3
    // with OC0A and OC0B toggling on match
    // and TOP = 255.
	TCCR0A = ((1 << WGM01) | (1 << WGM00) | (1 << COM0A1) | (1 << COM0B1));
	
	// Timer 0 prescaler = 1,024.
	TCCR0B = ((1 << CS02) | (1 << CS00));
	
	// Need to set the pins to output.
	// Using AVR speak here.
	DDRD = ((1<< DDD5) | (1 << DDD6));
}


void loop() {
    // Current PWM duty cycle and increments.
    static uint8_t a = 0;
    static uint8_t b = 255;
    uint8_t increment = 1;

    if ((a != 0) && (a != 255)) {
        OCR0A = a;
        OCR0B = b;
    } else {
        if (a == 255) {     // then b == 0
            PORTD |= PWM_A_HIGH;
            PORTD |= PWM_B_LOW;
        } else {            // then b == 255
            PORTD |= PWM_A_LOW;
            PORTD |= PWM_B_HIGH;
        }
    }

        a += increment;
        b -= increment;
 
     // Even at 1,024 prescaling, it's too quick!
    delay(1);
}

