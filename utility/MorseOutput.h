#ifndef MorseOutput_h
#define MorseOutput_h

// default time of sending a dot in miliseconds
#define  DOTRATE 500

class Sender {
private:
  // PARELLEL OUTPUT
  int outputPin;
  int dotRate; // speed of sending

  unsigned long currentMilis = 0; // time from booting arduino at the moment
  unsigned long lastSendMilis = 0; // to check how long should we wait to send next char
  unsigned long waitingTime = 0; // how long should wait to next sent
  unsigned long msgPointer = -1; // which character should be sent
  boolean lastState = LOW; // state of last signal
  boolean ifDone = false; // if done sending the message

  // checking function if should sent impuls ON / OFF
  boolean if_should_sent_impuls();

  // checks how long should waiting time be before changing state
  void setWaitingTime(char msg);

  // functon handling changing digital output
  void send_morse_d(String msg);
public:
  // creating Sender Object
  Sender(int pin, int dotSpeed = DOTRATE);

  // give info if message was fully send or not
  boolean fully_send() {return ifDone;}

  // send normal string through digital output
  void send_morse_digital(String message);

  // send normal string through analog output (Mono Jack)
  void send_morse_analog(String message);

  // send normal string digitally but in loop function to
  // be able to do other tasks in parallel
  void send_morse_digital_parallel(String message);
};

#endif
