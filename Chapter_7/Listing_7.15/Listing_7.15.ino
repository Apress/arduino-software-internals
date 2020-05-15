#include <avr/power.h>

void disable(bool ADCdisable, bool USARTdisable, bool SPIdisable,
             bool TIMER0disable, bool TIMER1disable, bool TIMER2disable,
             bool TWIdisable, bool ACdisable) 
{
    // Disable ADC.
    if (ADCdisable)
        ADCSRA &= ~(1 << ADEN);

    // Disable USART0 RX and TX.
    if (USARTdisable)
        UCSR0B &= ~((1 << RXEN0) | (1 << TXEN0));

    // Disable SPI.
    if (SPIdisable)
        SPCR &= ~(1 << SPE);

    // Disable Timer/Counter 0
    if (TIMER0disable)
        TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));

    // Disable Timer/Counter 1.
    if (TIMER1disable)
        TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));

    // Disable Timer/Counter 2.
    if (TIMER2disable)
        TCCR2B &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));

    // Disable TWI.
    if (TWIdisable)
        TWCR &= ~(1 << TWEN);

    // Disable Analog comparator.
    if (ACdisable)
        ACSR &= ~(1 << ACD);
}

void setup() {
    // Disable the peripherals we don't want.
    disable(
    /* ADCdisable = */ true,
    /* USARTdisable = */ true,
    /* SPIdisable = */ true,
    /* TIMER0disable = */ false,
    /* TIMER1disable = */ true,
    /* TIMER2disable = */ true,
    /* TWIdisable = */ true,
    /* ACdisable = */ true);

    // Power down everything except Timer/Counter 0.
    // It's quicker this way, and less code bloat!

    __power_all_disable();
    power_timer0_enable();

    // Finally, do the sketch stuff.
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
