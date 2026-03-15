// Objective 2d - Repeat part 2c using interrupts (your choice of external or pin change interrupts)
int ledOn;
ISR(INT0_vect){ //write ISR
  if(ledOn){
     PORTD = 0b00000000; //setting bit 6 in port D to 0
     ledOn = 0;
  }
  else{
     PORTD = 0b01000000; //setting bit 6 in port D to 1
     ledOn = 1;
  }
  _delay_ms(100);
}

int main(void)
{
  // set I/O
  DDRD = DDRD | 0b01000000; // bit 6 in port D is an output
  DDRD = DDRD & 0b11111011; // bit 2 in port D is an input
  // configure the interrupt (set registers)
  EICRA = 0b00000011; //interrupt on any change
  EIMSK = 0b00000001; // enable INT0

  sei();
  while (1){
  }
}