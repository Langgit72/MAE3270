///////////// Lec 15
ISR(INT0_vect){
  if(PIND & 0b00000100){
    //light up the LED
    PORTD = 0b01000000; //setting bit 6 in port D to 1
  }
  else{
    //turn off the LED
    PORTD = 0b00000000; //setting all bits in port D to 0
  }
}

int main(void)
{
  // set I/O
  DDRD = DDRD | 0b01000000; // bit 6 in port D is an output
  DDRD = DDRD & 0b11111011; // bit 2 in port D is an input
  // configure the interrupt
  EICRA = 0b00000001;
  EIMSK = 0b00000001;
  sei();
  while (1){
  }
}
