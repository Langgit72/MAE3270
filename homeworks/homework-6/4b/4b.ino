/*
Objective 4b
① The motor spins "forward" for one second (the RPM value when running the TinkerCad
simulation should be positive)
② The motor pauses for one second
③ The motor spins "backward" for one second
④ The motor pauses for one second
⑤ Repeat the steps ① ~ ④ infinitely
*/

//Input 1A - PD6
//Input 2A - PD7

int main(void)
  {
  DDRD = 0b11000000; //bits 6 and 7 in port D is an output, the rest are inputs
  _delay_ms(1000);
  while (1)
  {
    PORTD = 0b10000000;
 	_delay_ms(1000);
    PORTD = 0b00000000;
   	_delay_ms(1000);
    PORTD = 0b01000000;
     _delay_ms(1000);
    PORTD = 0b00000000;
    _delay_ms(1000);
  }
}