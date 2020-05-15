void digitalToggle(uint8_t pin)
{
    uint8_t timer = digitalPinToTimer(pin);
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *in;

    if (port == NOT_A_PIN) return;

    // If the pin supports PWM output, we need to turn it off
    // before doing a digital write.
    if (timer != NOT_ON_TIMER) 
        turnOffPWM(timer);

    in = portInputRegister(port);
    uint8_t oldSREG = SREG;
    cli();
    *in |= bit;
    SREG = oldSREG; 
}