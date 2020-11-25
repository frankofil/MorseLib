#include  "../MorseLib.h"

Receiver::Receiver(port p, int speed){
  this->inputPin = p.pin;
  this->source = p.source;
  this->state = p.state;
  this->frequency = p.frequency;

  this->timeUnit = speed;
  this->msg = "";
}

bool Receiver::get_message(){
  if (this->source == "DIGITAL")
    return get_morse_input_digital();
  else if (this->source == "SERIAL")
    get_morse_serial();
  return false;
}

void Receiver::get_morse_serial(){
  while(!Serial.available()){;}
  String tempMsg = Serial.readString();
  bool morse = true;

  for(int i = 0; i < tempMsg.length(); i++)
      if(!(tempMsg[i] == '.' || tempMsg[i] == '-'
          || tempMsg[i] == ' ' || tempMsg[i] == '/'))
            morse = false;


  if(this->msg.length() != 0)
    this->msg += " ";
  if(morse)
    this->msg += tempMsg;
}

bool Receiver::get_morse_input_digital(){
  currentState = digitalRead(inputPin);

  // wait for the first input
  if(currentState == HIGH && started == 0){
    lastMilis = millis();
    lastState = HIGH;
    started++;
  }
  else if(lastState != currentState){ // change of state appeared
    currentMilis = millis();
    duration = currentMilis - lastMilis;
    if(duration > 25){ // Hardware errors
      if(currentState == HIGH)
        duration = -duration;

      char ch = translate_input_to_morse(duration);
      if(ch != 0)
        msg += ch;
    }

    lastState = currentState;
    lastMilis = currentMilis;
  }
  if(millis() - lastMilis >= 10 * DEFAULTSPEED && started != 0)
    return true;
  return false;
}

// translating input durations into morse code
char Receiver::translate_input_to_morse(int signalDuration){
  float unitLength = (float)signalDuration / (float)DEFAULTSPEED;

  if(signalDuration > 0){
    if(unitLength >= 0.3 && unitLength <= 1.5){
      return '.';
    }
    else if(unitLength > 1.5){
      return '-';
    }
  }
  else{
    if(unitLength <= -0.3 && unitLength >= -1.5){
      return 0;
    }
    else if(unitLength < -1.5 && unitLength >= -4){
      return '/';
    }
    else if(unitLength < -4){
      return ' ';
    }
  }
}
