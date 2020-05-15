//=======================================================
// The purpose of the sketch is to test the various sleep
// modes and to see if the AC will wake the Arduino.
//=======================================================

#include <avr/sleep.h>
#include <avr/interrupt.h>

// This function sets up the comparator to fire an interrupt
// each time the ACO bit TOGGLES. It uses D6 as the reference
// voltage and D7 as the voltage to be compared.
void setupComparator() {
    ACSR &= ~(1 << ACIE);
    ACSR &= ~(1 << ACD);
    DIDR1 |= ((1 << AIN0D) | (1 << AIN1D));
    ACSR &= ~(1 << ACBG);
    ADCSRB &= ~(1 << ACME);
    ACSR |= ((1 << ACIS1) | (1 << ACIS0));
    ACSR |= (1 << ACIE);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    setupComparator();
    // Here is where I set the various sleep modes.
    set_sleep_mode(SLEEP_MODE_IDLE);
}

// Analogue Comparator Interrupt Handler. Simply used to
// wake up the device, so no code required.
EMPTY_INTERRUPT(ANALOG_COMP_vect);

void loop() {
    noInterrupts();
    sleep_enable();
    sleep_bod_disable();

    // Kill timer 0 and its overflow interrupt otherwise
    // it will wake the AVR from SLEEP_MODE_IDLE thus
    // negating the test. I need the AC to do the wake
    // up call!
    TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));

    interrupts();

    // Go to sleep now.
    sleep_cpu();
    sleep_disable();

    // Reset Timer 0 to divide by 64 or delay() doesn't!
    TCCR0B |= ((1 << CS01) | (1 << CS00));
    // Flash the LED on wake up.
    for (short x = 0; x < 4; x++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(250);
        digitalWrite(LED_BUILTIN, LOW);
        delay(250);
    }
}