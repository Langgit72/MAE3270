////////////// Lec 13 - output
int main(void)
  {
  DDRD = 0b01000000; //bit 6 in port D is an output, the rest are inputs
  //light up the LED
  PORTD = 0b01000000; //setting bit 6 in port D to 1
  //PORTD = 0x40;
  _delay_ms(1000);
  while (1)
  {
    //turn off the LED
    PORTD = 0b00000000; //setting all bits in port D to 0
    _delay_ms(1000);
    //light up the LED
    PORTD = 0b01000000; //setting bit 6 in port D to 1
    _delay_ms(1000);
  }
}