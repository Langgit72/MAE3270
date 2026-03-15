#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    // ----- Configure LEDs as outputs -----
    DDRB |= (1 << DDB5) | (1 << DDB4);

    // ----- Configure buttons as inputs -----
    DDRD &= ~((1 << DDD2) | (1 << DDD3));

    // ----- Configure INT1 (PD3 / pin 3) for rising edge -----
    EICRA |= (1 << ISC11) | (1 << ISC10);

    // Enable INT1 interrupt
    EIMSK |= (1 << INT1);

    // Enable global interrupts
    sei();

    while (1)
    {
        // Poll Button1 (PD2)
        if (PIND & (1 << PIND2))
        {
            PORTB |= (1 << PORTB5);   // LED1 ON
        }
        else
        {
            PORTB &= ~(1 << PORTB5);  // LED1 OFF
        }
    }
}

// Interrupt for Button2
ISR(INT1_vect)
{
    // Toggle LED2
    PORTB ^= (1 << PORTB4);
}