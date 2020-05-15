Title: Listing E.1 - ADC Temperature Monitor
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Shows how the ADC can be used internally to measure the ATmega328P's temperature.

The setup() function initialises the ADC to use the internal 1.1V bandgap reference voltage
and selects ADC input 8 - which is connected to the temperature sensor in the microcontroller.

The loop() measures the internal temperature and reports it back to the serial monitor in degrees
Centigrade and Fahrenheit. 

Wait for it to settle, and then place your finger on the ATmega328P on your Arduino board. Watch
as the temperature goes up. Remove your finger, wait a bit, and it will come back down.

NOTE: The data sheet indicates that ADC8 should not be used as an input to the ADc as it 
is "reserved". This is probably a bug as the input is the internal temperature sensor, and 
can be safely used.

Converting from the reading to the actual temperature, if fraught with fun and games. See the book
for details.
