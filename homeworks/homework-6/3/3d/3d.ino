#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    // LED (PB5 / Pin 13) as output
    DDRB |= (1 << DDB5);

    // Button (PD2 / Pin 2) as input
    DDRD &= ~(1 << DDD2);

    // Configure INT0 to trigger on rising edge (button press)
    EICRA |= (1 << ISC01) | (1 << ISC00);

    // Enable external interrupt INT0
    EIMSK |= (1 << INT0);

    // Enable global interrupts
    sei();

    while (1)
    {
        // main loop does nothing
    }
}

// Interrupt Service Routine
ISR(INT0_vect)
{
    // Toggle LED
    PORTB ^= (1 << PORTB5);
}