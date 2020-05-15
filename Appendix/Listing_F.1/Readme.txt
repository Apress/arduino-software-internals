Title: Listing F.1 - Arduino BlinkASM sketch
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Uses an assembly module to blink an LED on D13.

The code in the main loop() calls out to an assembly language module
which does the blinking part of the code.

This demonstrates that even the standard Arduino, can, if necessary, use code
written in Assembly Language, and, compiled from within the IDE itself.

No need for special assemblers etc, the IDE has it covered. At least in version 1.6.x onwards.

Previous versions did not allow assembly language modules to be assembled without a modification 
to the IDE source code and a recompile.

