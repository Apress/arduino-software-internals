Title: Listing 7.15 Power Off Blink.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Shows how the unwanted ATmega328P features are disabled in the blink sketch.

Function disable() is called from setup() to disable all the unwanted timers, the ADC, etc
so that the blink sketch is running with the ATmega328P configured to use minimal power. 

Yes, I know, there are always on power indicator LEDs etc, but you get my drift!

Timer/counter 0 is left running as we use it in the delay() function, everything else is disabled.
Disabling leaves the hardware features powered up though, so setup() next powers everything off using 
code from the AVRLib. It then repoweres Timer/counter 0 - we need the delay().

The loop() function is just the standard blink sketch's loop(0 function. In this version, however,
it's running with the rest of the ATmega328P disabled and powered down.

