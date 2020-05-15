void setupADC() {
    // Ensure ADC is powered.
    PRR &= ~(1 << PRADC);
    
    // Slow the ADC clock down to 125 KHz
    // by dividing by 128 or 64. 128 is for a 16MHz Arduino
    // 64 for an 8MHz NormDuino. Does not cater for other
    // clock speeds here. BEWARE.
   #if F_CPU == 16000000
        ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
   #else
        // Non-standard 8MHz clock in use.
        ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
   #endif
    

    // Initialise the ADC to use the
    // internal AVCC 5V reference voltage. 
    ADMUX = (0 << REFS1) | (1 << REFS0);

    // Ensure result is right aligned.
    ADMUX &= ~(1 << ADLAR);
    
    // Use the ADC multiplexer input
    // ADC0 = Arduino pin A0.
    ADMUX |= (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (0 << MUX0);

    // Disable ADC0 Digital input buffer.
    DIDR0 |= (1 << ADC0D);

    // Use the interrupt to advise when a result is available.
    ADCSRA |= (1 << ADIE);

    // Set auto-trigger on, and choose Free Running mode. As we
    // are not using the Analogue Comparator, we don't care about 
    // the ACME bit in ADCSRB.
    ADCSRA |= (1 << ADATE);
    ADCSRB = 0;
    
    // Enable the ADC and wait for the voltages to settle. 
    ADCSRA |= (1 << ADEN);
    delay(20);
}


void startADC() {
    ADCSRA |= (1 << ADSC);
}


// Somewhere for the ADC Interrupt to store the result.
volatile uint16_t ADCReading = 0;


// The interrupt handler.
ISR(ADC_vect) {
    ADCReading = ADCW;
}


void setup() {
    setupADC();
    
    // Use the Serial monitor for output.
    Serial.begin(9600);
    Serial.println("Arduino Direct ADC Testing");

    pinMode(9, OUTPUT);

    // Now, fire up the ADC.
    startADC();
}


void loop() { 

    Serial.print("ADC = ");
    Serial.print(ADCReading);

    // The voltage is ADCReading * (5V/1024)
    Serial.print(", Voltage = ");
    Serial.println((float)(ADCReading * 5.0 / 1024.0));

    analogWrite(9, map(ADCReading, 0, 1023, 0, 255));
    delay(500);
}
