/*Toggle the LED when the button is pressed (using polling)
i.e. turn the LED on when the button is pressed and released once, the LED should
stay on, then turn the LED off when the button is pressed and released again*/ 

int main(void)
{
  DDRD = 0b01000000; //bit 6 in port D is an output the rest are inputs
  int wasPressed;
  int ledOn;
  while (1)
  {
    if(wasPressed && !(PIND & 0b10000000)){
      if(ledOn){
         PORTD = 0b00000000; //setting bit 6 in port D to 0
         ledOn = 0;
      }
      else{
         PORTD = 0b01000000; //setting bit 6 in port D to 1
         ledOn = 1;
      }
    }
    wasPressed = PIND & 0b10000000;
    _delay_ms(100);
  }
}
