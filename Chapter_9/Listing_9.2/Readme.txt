Title: Listing 9.1 Analogue Digital Converter.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Shows how the ADC can be used.

The function setupADC()) is called from setup() to initialise the
ADC so that it runs at the correct frequency for 10 bit accuracy, and 
to use the internal 5V reference voltage. Pin A0 will be used as the input voltage
source.

Whatever voltage is read on A0 is passed to the PWM pin D9 so that an LED attached
to D9 will fade up and down as the voltage on A0 varies. This varying is done using 
a potentiometer attached to VCC and GNG with  the slider attached to A0.

The serial monitor will display details of the changes in the voltage on A0.
