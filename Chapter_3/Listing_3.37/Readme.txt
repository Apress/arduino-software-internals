Title: Listing 3.37 - Example sketch using attachInterrupt() to light an LED.
Author: Arduino.cc
URL: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
Circuit: Layout.png

Purpose: A simple light switch!

The LED on pin D13 will be lit or extinguished based on 
the on or off state of a switch. In the book, and in the
layout image, there is a debounce IC (MC14490 Hex Contact 
Bounce Eliminator) to debounce "noisy" switches which can
lead to the code, which is an example from the Arduino.cc
web site, not working as expected.

Other debouncing techniques are available using the delay()
function etc.
