Title: Listing 9.7 - USART.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: Shows how the USART can be used without involving all the Serial code.

The function setupUSART()) is called from setup() to initialise the
USARt at 9600 baud. The sketch uses the serial monitor to send and receive text or numbers
without needing all the baggage of the Serial interface.

This is a decent enough communications package and lighter in weight than the standard
Arduino code. Admittedly, it's not interrupt driven - but that would basically just
have replicated the Serial stuff already there and we wouldn't have learned much!

Try typing up to 100 characters, then 102, then 103 or more. Notice what happens?
