Title: Listing 9.1 Analogue Comparator.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Shows how the analogue comparator can be used.

The function setupComparator() is called from setup() to initialise the
AC so that it reads a refernce voltage on pin D6 and compares it with a 
variable voltage on pin D7.

When D6 is higher than D7, the LED will light.

When D6 is lower than D7, the LED will extinguish.

The sketch could be slightly amended to use a light dependent resistor to determine 
how dark it is, based on a preset voltage on D6, and to turn on or off a "night light".
