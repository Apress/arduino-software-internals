Title: Listing 8.20 - Input Capture Unit Example
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Uses Timer/counter 1's Input Capture Unit. It will print the current count (TCNT1) to
the serial monitor whenever it notices pin D8 falling to GND potential.

It demonstrates that the use of the ICU is problematical in that at 16 MHz, it rolls over far too frequently for comfort, and better ways of time-stamping events has to be found.
         
This is the result of pulling the D8 wire out of GND:

4223
36284
38526
41826
49911
51621
56923
61917
62191
4032

You can see the "bounciness" of the removal, plus, it rolled over during the removal.

It's far too fast in its "standard" setup. We need to use a better system. This is probably 
why there are no example sketches on the Arduino.cc web site!

