int main(void)
{
  DDRD = 0b01000000; // bit 6 in port D is an output, the rest are inputs
  DDRB = 0b00000000; // all pins in port B are inputs
  //light up the LED
  //PORTD = 0b01000000; //setting bit 6 in port D to 1
  //_delay_ms(1000);
  while (1)
  {
    if(PINB & 0b00001000){
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