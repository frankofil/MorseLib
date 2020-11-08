#include  "../MorseLib.h"

// check state of the potentiometer
int check_pot_state(int pin, int scaleStart, int scaleEnd){
  int analogValue = analogRead(pin);
  int range = map(analogValue, 0, 1023, scaleStart, scaleEnd);
  return range;
}

// wait for pressed button to get speed from potentiometer
void wait_for_button(int pin){
    while (digitalRead(pin) == LOW){ ; }
}
