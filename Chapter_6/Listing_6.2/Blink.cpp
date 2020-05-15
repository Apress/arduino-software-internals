#include "Arduino.h"

// Is the built in LED already named?
#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif


// This runs once, in the usual Arduino manner.
void setup()
{
    // Make sure the LED is an output pin.
    pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
    // LED on, then wait 1,000 milliSeconds.
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);

    // LED off, then wait another 1,000 milliSeconds.
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}