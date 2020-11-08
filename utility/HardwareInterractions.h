#ifndef HardwareInterractions_h
#define HardwareInterractions_h

// check state of the potentiometer (and mapping scale)
int check_pot_state(int pin, int scaleStart, int scaleEnd);

// wait for pressed button to get speed from potentiometer
void wait_for_button(int pin);

#endif