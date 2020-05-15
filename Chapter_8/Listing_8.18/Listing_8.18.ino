//========================================================
//                                           CounterBounce
//========================================================
// This sketch uses the Timer/Counter 1 in counter mode,
// fired by a rising edge on pin T1 = D5 = PD5. This is
// connected to a switch and will display the number of
// times the timer increments whenever the switch is 
// pressed.
//========================================================

void setup() {
    // Serial monitor is required.
    Serial.begin(9600);
    
    // Initialise Timer/counter 1 to be triggered externally
    // by a rising edge on pin D5. The timer runs in normal
    // mode as we don't need waveforms.
    TCCR1A = 0;     // Sets WGM11 and WGM10 to zero.

    // Disable interrupts on Timer 1.
    TIMSK1 = 0;

    // Clocked on a rising edge, and start the timer.
    TCCR1B = ((1 << CS12) | (1 << CS11) | (1 << CS10));

    // Make sure everything is reset.
    TCNT1 = 0;
    
    // T1=PD5=D5 is an input. PB5=D13 an Output.
    DDRB |= (1 << DDB5);
    DDRD |= (1 << DDD5);
}


void loop() {
    // Save the previous value of TCNT1.
    static uint16_t lastTCNT1 = 0;
    uint16_t thisTCNT1 = TCNT1;

    if (thisTCNT1 != lastTCNT1) {
        Serial.print("TCNT1 = ");
        Serial.println(thisTCNT1);
        lastTCNT1 = thisTCNT1;
    }

    // Flash the LED and delay ...
    // ... to show that the timer still works.
    PINB |= (1 << PINB5);
    delay(2000);    
}
