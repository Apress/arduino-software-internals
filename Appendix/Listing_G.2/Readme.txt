Title: Listing G.2 - Smallest Blink Sketch
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Uses an assembly language program to blink an LED on D9. There is no C++ involved.

The code in the main() function initialises Timer/counter 1 in CTC mode
with a prescaler of 256. COM1A0 is set to toggle pin D9 when the TCNT1 counter
reaches the value in OCR1A (31249) which gives a flash rate of 1 per second so the
timer/counter is running at 0.5 Hz (because it takes two toggles to flash once).

The frequency is calculated as:

    F = F_CPU / ((2 * prescaler) * (1 + OCR1A))

And OCR1A is calculated as:

    OCR1A = ((F_CPU / (2 * prescaler)) / Frequency) - 1

The timer/counter is doing all the hard work. The loop is doing nothing except 
wasting CPU cycles. :o)


PLATFORMIO:

This code can be compiled in the PlatformIO environment as follows:

* mkdir SmallestBlink
* cd SmallestBlink
* pio init --board YOUR_BOARD

I used my Uno, so replace "YOUR_BOARD" with whatever you have.

* Copy the file I've supplied, SmallestBlink.S into the src directory.
* Edit the platformio.ini file and remove the line "framework = arduino".

* To compile/verify, execute the command "pio run".
* To upload (using the bootloader) execute "pio run --target upload".

If you have problem uploading, add the line "upload_port = /dev/ttyUSB0" (or 
as appropriate for your system) to platformio.ini and try uploading again.

The Arduino IDE needs a *.ino file in order to compile. So, sadly, it appears - at
least at version 1.6.5, that a fully assembly language sketch cannot be created. Easily.

:o(
    
