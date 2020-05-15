Title: Listing 8.1 - Normal timer/counter mode.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Uses Timer/counter 2 to toggle LEDs on D11 and D12 while the an LED
         on D13 is toggled by the same timer/counter's overflow interrupt. D12
         is toggled by an interrupt when Timer/counter 2 matches OCR2A and D11
         is toggled by another interrupt when Timer/counter 2 matches OCR2B. 

         All three LEDs are toggled by interrupt routines. The main loop() does
         next to nothing.

         The sketch demonstrates that, in normal mode, whatever the timer is doing 
         on its output pin(s), all happens at the same frequency. We cannot have 
         different pins running at different (timer/counter) frequencies.

         It also demonstrates that there is a lot that timer/counter can do that the 
         main CPU doesn't have to bother itself with! In this case, interrupts handle 
         the flashing of all three LEDs.

         See also Listing_8.4 for even more "getting timers to do the work!".

