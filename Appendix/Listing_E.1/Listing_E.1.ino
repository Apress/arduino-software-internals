/*
 * ARDIUNO - measure the internal temperature of the 
 * AVR ATmega328P using the ADC internal temperature 
 * input. See the data sheet for details.
 * 
 * (C) Norman Dunbar, July 21 2018.
 *
 * This code is in the public domain - use it and abuse
 * it as you wish! It is based, but not copied, from
 * an Atmel example found at:
 *
 * https://microchipdeveloper.com/8avr:avradc
 *
 */

void setup() {
    // Initialise the ADC to use the
    // internal 1.1V reference voltage. 
    ADMUX = (1 << REFS0) | (1 << REFS1);
    
    // Use the ADC multiplexer input
    // number 8, the temperature sensor.
    ADMUX |= (1 << MUX3);
    
    // Slow the ADC clock down to 125 KHz
    // by dividing by 128. Assumes that the
    // standard Arduino 16 MHz clock is in use.
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    // Non-standard 8MHz clock in use.
    //ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
    
    // Enable the ADC and discard the first reading as
    // it is always 351 on my device.
    ADCSRA |= (1 << ADEN) | (1 << ADSC);
    (void)readADC();
    
    // Use the Serial monitor for output.
    Serial.begin(9600);
    Serial.println("Arduino Internal Temperature");
}


// Read the ADC result from the most recent conversion and
// start another before ruturning the current reading.
uint16_t readADC() {
    // Make sure the most recent ADC read is complete.
    while ((ADCSRA & (1<<ADSC))) {
        ; // Just wait for ADC to finish.
    }
    
    uint16_t result = ADCW;

    // Initiate another reading.
    ADCSRA |= (1 << ADSC);

    return result;
}


//-----------------------------------------------------------------
// There are many ways, it seems, to calculate the degrees C from
// the ADC. Read the chapter on the ADC to find out where they come
// from. Here are some:
//
// ADC - some random offset;
// (ADC - 247)/1.22;
// ADC - 273;
// (((ADC - (273 - 100 - TS_OFFSET)) * 128) / TS_GAIN) + 25.
// (ADC - 324.31) / 1.22
//
// I'm using the last one, as it's the one closest to my actual
// temperature measurements.
//-----------------------------------------------------------------


void loop() {

    // Running average of the ADC Readings for
    // better accuracy.
    uint32_t ADCTotal = 0;
    float ADCAverage = 0.0;
    uint16_t ADCReading = readADC();

    for (uint8_t x = 1; x < 101; x++) {
        ADCTotal += ADCReading;
        ADCAverage = (float)ADCTotal / (float)x;

        // Uncomment if you want a running commentary!
        /*
        Serial.print("ADC = ");
        Serial.print(ADCReading);
        Serial.print(" ");
        Serial.print("ADCTotal = ");
        Serial.print(ADCTotal);
        Serial.print(" ");
        Serial.print("ADCAverage = ");
        Serial.println(ADCAverage);
        */

        ADCReading = readADC();
    }
    
    // Print the ADC temperature.    
    float degreesC = (ADCAverage - 324.31) / 1.22;
    Serial.print(degreesC);
    Serial.print("C, ");
    
    // Convert to Fahrenheit. C * 1.8 + 32.
    Serial.print(degreesC * 1.8 + 32);
    Serial.println("F.");
    
    // Delay a second more between readings.
    delay(1000);
}
