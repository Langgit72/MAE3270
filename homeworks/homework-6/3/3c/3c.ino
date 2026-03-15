#include <avr/io.h>

int main(void)
{
    // LED (PB5 / Pin 13) as output
    DDRB |= (1 << DDB5);

    // Button (PD2 / Pin 2) as input
    DDRD &= ~(1 << DDD2);

    uint8_t led_state = 0;

    while (1)
    {
        // Check if button is pressed
        if (PIND & (1 << PIND2))
        {
            // Toggle LED state
            led_state ^= 1;

            if (led_state)
                PORTB |= (1 << PORTB5);   // LED ON
            else
                PORTB &= ~(1 << PORTB5);  // LED OFF

            // Wait until button is released
            while (PIND & (1 << PIND2));
        }
    }
}