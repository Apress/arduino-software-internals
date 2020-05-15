Title: Listing 6.4 - AVR blink sketch.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Example of compiling an AVR program using PlatformIO.

This is a simple "blink" example which does not use the Arduino language. It
uses plain AVR C++ code in the PlatformIO environment. This makes it:

* Slightly less readable than the Arduino code would be;
* Much smaller in size.

Steps to recreate for your PlatformIO environment:

1. Change to your PlatformIO source directory.
2. mkdir Listing_6.4
3. cd Listing_6.4
4. pio init --board YOUR_BOARD
5. Copy the file "Blink.cpp" into the newly created src directory. You can call the file anything you wish.
6. Edit the file "platformio.ini" and remove the "framework = arduino" line.
7. pio run
8. pio run --target upload

Your built in LED should now be flashing.

In the above, YOUR_BOARD is a valid board name, uno for example.

