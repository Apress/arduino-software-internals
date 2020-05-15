Title: Listing 6.9 - MyFirstSketch.ino.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Example blink sketch using Arduino-cli.

This is a simple "blink" example which uses the new, but alpha, utility
named "arduino-cli". The Arduino Command Line utility. Sketches are
created using the usual Arduino Language.

Steps to recreate for your arduino-cli environment:

1. Change to your source directory.
2. arduino-cli sketch new Listing_6.9
3. cd Listing_6.9
4. Open the sketch in the Arduino IDE as normal or your favourite editor.
5. Copy my file "Listing_6.9.ino" into the newly created but blank sketch file.
6. Save and exit.
7. arduino-cli compile --fqbn arduino:avr:uno 

Your built in LED should now be flashing.

In the above the uno is used for an example board. You might have to change this to suit your board.

