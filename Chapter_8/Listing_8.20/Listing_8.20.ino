//========================================================
//                                            inputCapture
//========================================================
// This sketch uses the Timer/Counter 1 input capture 
// unit to "timestamp" the arrival of a rising edge on 
// Arduino pin D8, AVR pin ICP1/PB0, physical pin 14 on 
// the ATmega328P.                                            
//
// Author: Norman Dunbar
// Date:   21 March 2019
//
// For the Arduino Software Internals book.
//
// This code is in the public domain.
//========================================================
//
// The builtin LED will appear to be on, but it's flashing 
// every time loop() gets called. If you put a jumper wire
// in D8 and with the serial monitor open, touch it to GND
// (yes, GND) then lift it off again. You'll see:
//
// A few numbers scroll up - that's "key" bounce happening
// before your very eyes;
//
// The numbers will stop when it settles. Plug it back in 
// again - more numbers scroll up. That's key bounce!
//
// At a certain point, the numbers will rollover and become
// smaller.
//=========================================================



void setup() {
    // Initialise the LED pin (D13) as OUTPUT and
    // pin D8/PB8/ICP1 as INPUT_PULLUP.
    DDRB = (1 << DDB5);         // D13/PB5 as output.
    PORTB = (1 << PORTB0);      // PB0/ICP1 as input pullup.

    // Initialise the ICU to no scaler, no noise cancel,
    // and rising edge detection.
    TCCR1A = 0;                 // Normal mode.
    TCCR1B = ((1 << ICES1) | (1 << CS10));

    Serial.begin(9600);      
}


void loop() {
    // This is a polled wait, so inefficient!
    // Wait for ICF1 to be set in TIFR1 then send
    // ICR1 to the serial port. Toggle the built
    // in LED while we wait. (Very quickly!)
    while (!(TIFR1 & (1 << ICF1)))
        PINB |= (1 << PINB5);

      // Clear the ICF1 bit (no interrupts running you see)
      // Yes, write a 1 to clear a bit - who would have thought!
      TIFR1 &= (1 << ICF1);

      // Grab the timestamp.
      Serial.println(ICR1);
}
