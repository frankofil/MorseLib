#ifndef MorseInput_h
#define MorseInput_h

#define DEFAULTSPEED 230
#define DURATIONS_SIZE 15

class Receiver{
  private:
    int inputPin;
    String source;
    bool state;
    int frequency;

    int timeUnit;
    int started = 0;

    boolean lastState = LOW;
    boolean currentState;
    unsigned long lastMilis = 0;
    unsigned long currentMilis = 0;
    int duration = 0;

    char translate_input_to_morse(int signalDuration);

    // get one morse character at a time - '.' or '-'or ' ' or '/'
    bool get_morse_input_digital();

    // get morse string from serial port
    void get_morse_serial();
  public:
    String msg;

    // creating Receiver Object
    Receiver(port p, int speed = DEFAULTSPEED);

    // get message from given port
    bool get_message();
};

#endif
