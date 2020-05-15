// LISTING_7.4

// Add the next line to the top of your sketch.
#include <avr/wdt.h>


// Add the wdt_interrupts function code to your sketch.
void wdt_interrupts(uint8_t value) {
 
    // Save existing interrupt state. 
    uint8_t oldSREG = SREG;
 
    // Set the WDP3-WDP0 bits for the prescaler.
    uint8_t wdt_setting;
    value = (value > 9) ? 9 : value;
    wdt_setting = (value > 7) ? (1 << WDP3) : 0;
    wdt_setting |= (value & 7);
 
 
    // Disable interrupts and reset WDT.
    //noInterrupts();
    wdt_reset();
 
    // Clear WDT restarted flag.
    MCUSR &= ~(1 << WDRF);
 
    // Do the timed sequence next.
    #if defined WDTCSR
        // ATmega168/328/2560 etc
        WDTCSR |= ((1 << WDCE) | (1 << WDE));
        WDTCSR = (wdt_setting | (1 << WDIE));
 
    #elif defined WDTCR
        // ATtiny25/45/85 etc
        WDTCR |= ((1 << WDCE) | (1 << WDE));
        WDTCR = (wdt_setting | (1 << WDIE));
    #else
        #error "Unknown WDT Control Register on your AVR."
    #endif
 
    // Put interrupts back as they were previously.
    SREG = oldSREG;
}