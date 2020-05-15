#include <avr/io.h>      

.section .text

.global main

#define FLASH_RATE 31249


main:
 	ldi r18, (1 << DDB1)	; R18 = 00000010 = PB1 = Arduino D9
   	out _SFR_IO_ADDR(DDRB), r18			; Sets PB1 as OUTPUT. (D9)

    ; Set up Timer 1:
    ldi r18, (1 << COM1A0)
    sts TCCR1A, r18         ; CTC channel A = toggle mode 

	; Set up OCR1A for 1 Hz at 8 MHz.
	ldi r18, hi8(FLASH_RATE)
	sts OCR1AH, r18

	ldi r18,lo8(FLASH_RATE)
	sts OCR1AL, r18

	; Finish setup of Timer 1.
    ldi r18, ((1 << WGM12)|(1 << CS12))     ; Timer 1 = CTC, prescaler = 256  
    sts TCCR1B, r18

loop:
	rjmp loop

