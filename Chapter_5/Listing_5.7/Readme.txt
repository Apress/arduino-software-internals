Title: Listing 5.7 - The digitalToggle() function
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Adding "digitalToggle()" to the Arduino Language.

Given how popular the various "blink" sketches appear to be, why
not add a new "digitalToggle()" function to the language? This is 
a slightly silly example - it will be overwritten when the IDE is
next updated - but shows how "easy" it can be to add new stuff to
the Arduino Language.

1. Close the Arduino IDE.
2. Add the following line to $ARDINC/Arduino.h:

void digitalToggle(uint8_t);

3. Add the digitalToggle.c code to $ARDINC/wiring_digital.c.
4. Test with Listing_5.9.

WARNING: This will of course be overwritten if and when you update the
         Arduino IDE. It really needs to be added as an enhancement
         request to the Arduino GitHub page.

$ARDINC? - What's that then? It's shorthand for the location where the
           Arduino finds its software. If you, like me, downloaded the
           IDE as a zip file, and unzipped it, you might expect to run
           the code then where you unzipped it? I'm afraid not.

           On Linux, ARDINC is:
           "/home/YOUR_NAME/.arduino15/packages/arduino/hardware/avr/n.n.n/cores/arduino".
           
           On Windows it is:
           "C:\Users\YOUR_NAME\AppData\Local\Arduino15a\packages\arduino\hardware\avr\n.n.n\cores/arduino".

           "n.n.n" is a version number and "YOUR_NAME" is, well, your name!

           You need to change the files in those locations and not where you 
           downloaded and unziped originally. (Ask me how I know?)
