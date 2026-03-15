#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    // LED pin (PB5 / Pin 13) as output
    DDRB |= (1 << DDB5);

    // Button pin (PD2 / Pin 2) as input
    DDRD &= ~(1 << DDD2);

    // Configure external interrupt INT0 to trigger on any change
    EICRA |= (1 << ISC00);   // trigger on logical change
    EICRA &= ~(1 << ISC01);

    // Enable INT0 interrupt
    EIMSK |= (1 << INT0);

    // Enable global interrupts
    sei();

    while (1)
    {
        // main loop does nothing
    }
}

// Interrupt Service Routine for INT0
ISR(INT0_vect)
{
    if (PIND & (1 << PIND2))
    {
        PORTB |= (1 << PORTB5);   // LED ON
    }
    else
    {
        PORTB &= ~(1 << PORTB5);  // LED OFF
    }
}