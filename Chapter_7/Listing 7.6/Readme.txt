Title: Listing 7.6 Using WDT in the Blink sketch.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Example blink sketch the Watchdog timer to do the blinking,

This is another simple "blink" example which uses the ATmega328P's Watchdog Timer
to flash the LED every second. (Other times are available - see the text for details.)

Function wdt_interrupts() takes care of initialising the WDT. It can be called with a valid
timeout parameter as per the limited WDT timeouts that are available.

The setup() function initialises the WDT with a one second timeout and uses AVR C++ to do the
equivalent of a pinMOde() call on D13. (The built in LED.)

The loop() function does absolutely nothing.

All the hard work of flashing the LED takes place in the WDT interrupt handler. In here we again use AVR C++ to toggle the LED on pin D13, but writing a one (binary) to it's bit, PINB5, in the PINB register.

Every time the WDT times out, it fires the WDT interrupt. The ISR catches that and toggles the LEDT. Control then returns to the loop() function, which in this demonstration, is doing nothing of any use whatsoever. In a proper sketch, it would be doing something, and letting the WDT worry about falshing LEDs.

