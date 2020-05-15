// Apparently, a hack! But this makes sure we get the correct
// offset for the PINB and PORTB names used below. AVRs are
// weird and these things have two addresses in memory. 
// (Technically incorrect, but pretty much accurate!)
#define __SFR_OFFSET 0

// We need this for the PORTB5 and PINB definitions for
// whichever AVR we have out the board.
#include <avr/io.h>         

// The text section is where (most) code lives, so we need our
// code to live there too.
.section .text

// Making the 'blink' label global allows it to be seen/called 
// from other parts of the sketch - ie loop().
.global blink

// This is the label we use and defines the 'function' name
// and is callable, if made global.
blink:
    // digitalWrite(13, !(digitalRead(13)));
	ldi r18, (1 << PORTB5)	; R18 = 00100000 = PB5 = Arduino D13
   	out PINB, r18			; Toggle bit PB5 = D13
	ret
