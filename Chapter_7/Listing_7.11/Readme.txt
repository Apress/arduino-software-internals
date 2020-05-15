Title: Listing 7.11 Analogue Comparator Wake up Call.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Shows how the Analogue Comparator can wake the Arduino from an IDLE sleep.

Function setupComparator() is used to initialise the internal analogue comparator of
the ATmega328P, so that it fires an interrupt each time that the output bit (ACO) toggles
from LOW to HIGH or HIGH to LOW.

The setup() function initialises the comparator, and sets the sleep mode to IDLE Sleep.

The loop() function turns off interrupts, enables sleep modes and disabled the brown out detector.
It also needs to disable Timer/counter 0 as it has an overflow interrupt that will fire every 1024 
uSeconds to increments the millis() counter. We don;t need that here as it will bring us out of sleep
and the function here is to see if the AC will wake us up. We already know that Timer/counter 0 
Overflow Interrups wake us up.

After disabling the timer/counter, loop() puts interrupts back on - otherwise we won't wake up - and
puts the Arduino to sleep.

If you watch closely, nothing will happen. However, turn the potentiometer and if you make the analogue 
comparator toggle it's output bit, the loop() function will continue and disable sleep modes while it "does some work".

The work, in this case is to re-enable Timer/counter 0 to allow delay() to function, and flash the LED a few times. 

After flashing the LED, loop() heads back to the top to put everything to sleep again. The AC will wake us up again if you turn the potentiometer in the other direction.

