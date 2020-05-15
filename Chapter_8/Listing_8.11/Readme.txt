Title: Listing 8.11 - Fast PWM timer/counter mode.
Author: Norman Dunbar
URL: 
Circuit: Layout.png

Purpose: Uses Timer/counter 0 in Fast PWM mode to fade up an LED on pin D5 while
         fading down another LED on pin D6.
         
         D5 and D6 fade up and down very very very quickly indeed! There is a need 
         for a slight delay() in the loop() to keep things from running to quickly.

         Timer/counter 0 is initialised with a prescaler of 1024. But it's still quick.

         As the D5 LED fades up to maximum, it immediately goes out and fades up again. 
         
         As the D6 LED fades down to minimum, it immediately turns full on and fades 
         down again.

