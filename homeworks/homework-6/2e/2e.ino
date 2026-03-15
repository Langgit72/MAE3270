/*
Add a second LED and a second button to pins of your choice. Write a program
that turns one LED on only while the first button is held down (same behavior as
parts a-b) and toggles the other LED when the second button is pressed and released
(same behavior as part c-d). It is your choice whether to use polling, interrupts, or a
combination. Don’t forget to use masking when appropriate.
*/
// PD4 - Red Control
// PD5 - Green Control
// PD6 6 - Red LED
// PD7 7 = Green LED

int main(){
  DDRD = 0b11000000; //Pins 6 and 7 are output
  int wasPressed;
  int ledOn;
    while (1)
    {
      if(PIND & 0b00100000){ //if bit 5 in pin D is HIGH
        //light up the LED
        PORTD = PIND | 0b10000000; //setting bit 7 in port D to 1
      }
      else{
        //turn off the LED
        PORTD = PIND & 0b01111111; //setting bit 7 in port D to 0
      }
      if(wasPressed && !(PIND & 0b00010000)){
        if(ledOn){
          PORTD = PIND | 0b01000000; //setting bit 6 in port D to 1
          ledOn = 0;
        }
        else{
          PORTD = PIND & 0b10111111; //setting bit 6 in port D to 0
          ledOn = 1;
        }
      }
    wasPressed = PIND & 0b00010000;
    _delay_ms(100);
  }
}