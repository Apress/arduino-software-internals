#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // D13 is actually PortB Pin 5. Configure
    // that pin as an output.
    // This equates to the Arduino setup() function.
    DDRB = (1 << DDB5);

    // This equates to the Arduino loop() function.
    while (1)
    {
        _delay_ms(1000);

        // Toggle the LED by writing to PINB.
        PINB = (1 << PINB5);
    }

    return 0;
}