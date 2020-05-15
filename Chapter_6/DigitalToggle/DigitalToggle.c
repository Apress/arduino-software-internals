void digitalToggle(uint8_t pin)
{
	uint8_t timer = digitalPinToTimer(pin);                                 <1>
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *in;

	if (port == NOT_A_PIN) return;

	// If the pin supports PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	in = portInputRegister(port);                                           <2>
    
	uint8_t oldSREG = SREG;                                                 <3>
	cli();  
    *in |= bit;                                                             <4>
	SREG = oldSREG;                                                         <5>
}
