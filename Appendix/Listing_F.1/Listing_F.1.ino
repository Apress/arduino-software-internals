//=======================================================
// Yet another Blink sketch!                   (BlinkASM)
//=======================================================
// This sketch replaces some Arduino code with AVR
// assembly code and reduces the size of the finished
// sketch.
//
// Author: Norman Dunbar
// Date:   28 February 2019
// For the Arduino Software Internals book.
//
// This code is in the public domain.
//=======================================================

// Make sure the compiler can find 'blink' which is 
// written elsewhere in assembly language.
extern "C" void blink();

void setup() {
	pinMode(13, OUTPUT);
}

void loop() {
    blink();
    delay(1000);
}
