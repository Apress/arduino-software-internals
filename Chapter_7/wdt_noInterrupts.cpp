// LISTING_7.5

// Add the next line to the top of your sketch.
// If not already there of course!
#include "avr/wdt.h"

// Add the wdt_noInterrupts function code to your sketch.
void wdt_noInterrupts() {
    // Disable WDT interrupts leaving
    // everything else untouched.
    #if defined WDTCSR
        // ATmega328 etc
        WDTCSR &= ~(1 << WDIE);
    #elif defined WDTCR
        // ATtiny85 etc
        WDTCR &= ~(1 << WDIE);
    #else
        #error "Unknown WDT Control Register on your AVR."
    #endif
}