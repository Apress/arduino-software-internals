// This function sets up the comparator to fire an interrupt
// each time the ACO bit toggles. It uses D6 as the reference
// voltage and D7 as the voltage to be compared.
void setupComparator() {

  	// Disable AC interrupts.
  	ACSR &= ~(1 << ACIE);

  	// Enable AC by disabling the AC Disable bit!
  	ACSR &= ~(1 << ACD);

  	// Disable digital I/O on D6 and D7.
  	DIDR1 |= ((1 << AIN0D) | (1 << AIN1D));

  	// D6 will be the reference voltage.
  	ACSR &= ~(1 << ACBG);

  	// D7 to compare with D6.
  	ADCSRB &= ~(1 << ACME);

  	// Fire AC interrupt on ACO toggle.
  	ACSR |= ((0 << ACIS1) | (0 << ACIS0));

  	// Enable AC Interrupt.
  	ACSR |= (1 << ACIE);

  	// Enable Global Interrupts.
  	sei();
}


void setup() {
	// You can still use Arduino code as well -
	// but I'm not!
	DDRB |= (1 << DDB5);  //pinMode(LED_BUILTIN, OUTPUT);
	setupComparator();
}


void loop() {
  	// You could do something meaningful here ....
    ;	// I'm doing nothing, just looping.
}


// Analogue Comparator Interrupt Handler.Reads the ACSR
// register and sets the LED to the state of the ACO bit.
ISR(ANALOG_COMP_vect) {
  	if (ACSR & (1 << ACO)) {
        PORTB |= (1 << PORTB5);   // digitalWrite(LED_BUILTIN, HIGH);
  	} else {
        PORTB &= ~(1 << PORTB5);  // digitalWrite(LED_BUILTIN, LOW);
  	}
	
}
