#ifndef MorseInput_h
#define MorseInput_h

#define DEFAULTSPEED 230
#define DURATIONS_SIZE 15

class Receiver{
  private:
    int inputPin;
    int timeUnit;
    int started = 0;

    boolean lastState = LOW;
    boolean currentState;
    unsigned long lastMilis = 0;
    unsigned long currentMilis = 0;
    int duration = 0;

    char translate_input_to_morse(int signalDuration);
  public:
    String msg;

    // creating Receiver Object
    Receiver(int pin, int speed = DEFAULTSPEED);

    // get one morse character at a time - '.' or '-'or ' ' or '/'
    bool get_morse_input_digital();
};

#endif
