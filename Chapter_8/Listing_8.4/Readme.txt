Title: Listing 8.4 - Normal timer/counter mode.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Uses Timer/counter 2 to toggle LEDs on D11 and D3 while the an LED
         on D13 is toggled by the same timer/counter's overflow interrupt. D11
         is toggled by the timer/counter hardware when TCNT2 matches OCR2A and D3
         is toggled by the timer/counter hardware when TCNT2 matches OCR2B. 

         Only D13 is toggled by an interrupt routines. The main loop() still does
         next to nothing. (See also Listing_8.1.)

         The sketch again demonstrates that, in normal mode, whatever the timer is doing 
         on its output pin(s), all happens at the same frequency. We cannot have 
         different pins running at different (timer/counter) frequencies.

         It also demonstrates that there is a lot that timer/counter can do that the 
         main CPU doesn't have to bother itself with! In this case, the timer/counter
         itself handles the flashing of two of the  three LEDs.

         In a proper sketch, where the loop() was doing work, the use of the timer to
         replace two of the interrupts used in Listing_8.1, means that the loop() is not
         being interrupted as often. The timer hardware does the toggling here but, we are
         restricted to pins D11 and D3 - we have no choice in the matter - they are the
         timer's pins.

         See also Listing_8.1 for even more "getting timers to do the work!".

