//========================================================
//                                          TimerCTCToggle
//========================================================
// This sketch uses the Timer/Counter 2 in CTC mode 2 as 
// follows:
//
// OC2A to toggle D11 when TCNT2 matches OCR2A.
// OC2B to toggle D3 when TCNT2 matches OCR2B.
//
// Frequency = F_CPU / (2 * prescaler * (OCR2A + 1)
//
// Author: Norman Dunbar
// Date:   21 March 2019
//
// For the Arduino Software Internals book.
//
// This code is in the public domain.
//========================================================

void setup() {
    // Initialise Timer/counter 2 in CTC mode. (Mode 2)
    // with OC2A (D11) and OC2B (D3) toggling on match.
    TCCR2A = ((1 << WGM21) | (1 << COM2A0) | (1 << COM2B0));

    // Disable interrupts on Timer 2.
    TIMSK2 = 0;

    // Set up the compare values. OCR2A defines the frequency of both.
    OCR2A = 200;
    OCR2B = 86;

    // Prescale by 1024, and start the timer.
    TCCR2B = ((1 << CS22) | (1 << CS21) | (1 << CS20));

    // D11 and D12 are outputs. (Using Arduino
    // Language constructs here.)
    pinMode(11, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(13, OUTPUT);
}


void loop() {
    // Nothing happening here, move along now!
}


