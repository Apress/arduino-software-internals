#define SET_UBRR0(x) ((F_CPU) / (16 * (x))) - 1

void setupUSART(unsigned long baudRate) {
    // Sets up the USART to send and receive at a given baud,
    // 8 data bits, one stop bit, no parity. It doesn't use
    // interrupts or double speed.

    // Ensure we have power/clock.
    PRR &= ~(1 << PRUSART0);

    // calculate the baud rate setting.
    UBRR0 = SET_UBRR0(baudRate);

    // Initialise registers, then set TX and RX on,
    // 8 data plus one stop bit. The others default appropriately.
    UCSR0A = UCSR0B = UCSR0C = 0;
    UCSR0B |= ((1 << TXEN0) | (1 << RXEN0));
    UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00));    
}

uint8_t receiveByte() {
    // Wait for bit RXC0 to be set in UCSR0A.
    loop_until_bit_is_set(UCSR0A, RXC0);
    
    return UDR0;    
}

uint8_t receiveText(char *buffer, uint8_t howMany) {
    // Receive a string of text up to howMany characters
    // or until a terminating linefeed is received.
    //
    // MAKE SURE that the serial monitor is set to send a
    // NEWLINE or this code will fail to return until the buffer 
    // fills.
    //
    // Assumes the caller knows what s/he is doing! The
    // buffer should be one more than howMany in length.
    uint8_t i = 0;
    while (i < howMany) {
        uint8_t c = receiveByte();
        if (c == '\n') {
            buffer[i] = '\0';
            return i;
        }
        
        buffer[i++] = c;
        
    }

    // We have received howMany characters.
    buffer[i] = '\0';
    return howMany;
}


void sendByte(uint8_t c) {
    // Wait for bit UDRE0 to be set in UCSR0A then
    // buffer up the data byte.
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;    
}


void sendText(const uint8_t *text) {
    // Transmit a string of text. One byte
    // at a time.
    uint8_t *i = text;
    while (*i) 
        sendByte(*i++);    
}


void sendNumber(const long x, const uint8_t r = 10) {
    // Transmit a long integer to the USART. Only 32 bits
    // can be sent.
    char buffer[40];
    ltoa(x, buffer, r);
    sendText(buffer);    
}


void communicate() {
    const long number = 4294967295;
    
    sendText("Number = 2^32 -1 in HEX: ");
    sendNumber(number, 16);
    sendByte('\n');

    sendText("Number = 2^32 -1 in DEC: ");
    sendNumber(number, 10);
    sendByte('\n');

    sendText("Number = 2^32 -1 in OCT: ");
    sendNumber(number, 8);
    sendByte('\n');
    
    sendText("Number = 2^32 -1 in BIN: ");
    sendNumber(number, 2);
    sendByte('\n');

    sendText("\n\n");
    sendText("Type some text or numbers ... \n");
}


void setup() {
    // Initialise the USART without needing Serial.
    setupUSART(9600);

    // Play with the USART.
    communicate();
}


void loop() {
    uint8_t howManyChars;
    char buffer[101];

    // Buffer is one more than we want to receive.
    // Beware of buffer overruns, the code will lose
    // characters as the USART can only store two characters.
    howManyChars = receiveText(buffer, 100);
    sendNumber(howManyChars);
    sendByte('=');    
    sendByte('>');
    sendText(buffer);
    sendByte('\n');
}
