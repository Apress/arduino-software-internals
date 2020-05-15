Title: Listing 8.10 - CTC timer/counter mode.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Uses Timer/counter 2 to toggle LEDs on D11 and D3. D11
         is toggled by the timer/counter hardware when TCNT2 matches OCR2A and D3
         is toggled by the timer/counter hardware when TCNT2 matches OCR2B. The loop
         function has been added back to toddle the built in LED on D13.

         The sketch demonstrates that, in CTC mode, whatever the timer is doing 
         on its output pin(s), all happens at the same frequency. We cannot have 
         different pins running at different (timer/counter) frequencies.

         It also demonstrates that there is a lot that timer/counter can do that the 
         main CPU doesn't have to bother itself with! In this case, the timer/counter
         itself handles the flashing of two LEDs while the loop() does the third.

         The timer hardware does the toggling here but, we are restricted to pins D11 
         and D3 - we have no choice in the matter - they are the timer's pins.

         It need not always be an LED on the pins of course, LEDs are easy to demonstrate,
         but other electronics could be attached instead. Sirens, buzzers, etc.

         Because the timer's OCR2A register determined when the counter (TCNT2) clears back
         to zero, the frequency of the LEDs is F_CPU / (2 * prescaler * (OCR2A + 1).

         If OCR2B is greater than OCR2A, the LED on D3 will never toggle. (Try it!)

         D3 and D11 flash very very very quickly indeed!

