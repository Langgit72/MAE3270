#include <avr/io.h>

int main(void)
{
    // Configure LED pin (PB5 / Pin 13) as OUTPUT
    DDRB |= (1 << DDB5);

    // Configure button pin (PD2 / Pin 2) as INPUT
    DDRD &= ~(1 << DDD2);

    while (1)
    {
        // Poll button state
        if (PIND & (1 << PIND2))   // button HIGH
        {
            PORTB |= (1 << PORTB5);   // LED ON
        }
        else
        {
            PORTB &= ~(1 << PORTB5);  // LED OFF
        }
    }
}