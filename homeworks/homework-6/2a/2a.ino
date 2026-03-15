// Objective 2a - Turn on LED while button is held down using polling

int main(void)
{
  DDRD = 0b01000000; //bit 6 in port D is an output the rest are inputs
    while (1)
    {
      if(PIND & 0b10000000){ //if bit 7 in pin D is HIGH
      //light up the LED
      PORTD = 0b01000000; //setting bit 6 in port D to 1
    }
    else{
      //turn off the LED
      PORTD = 0b00000000; //setting all bits in port D to 0
      }
      _delay_ms(10);
    }
}
