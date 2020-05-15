Title: Listing 6.2 - Arduino blink sketch.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Example of compiling an Arduino sketch using PlatformIO.

This is a simple ino file being used in the PlatformIO environment almost
unchanged. All that is required is to add the "#include Arduino.h" line at
the top, and your sketch is usable in a PlatformIO environment.

Steps to recreate for your PlatformIO environment:

1. Change to your PlatformIO source directory.
2. mkdir Listing_6.2
3. cd Listing_6.2
4. pio init --board YOUR_BOARD
5. Copy the file "Blink.cpp" into the newly created src directory. You can call the file anything you wish.
6. pio run
7. pio run --target upload

Your builtin LED should now be flashing.

In the above, YOUR_BOARD is a valid board name, uno for example.

