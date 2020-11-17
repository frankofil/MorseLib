#include  "../MorseLib.h"

// creating Sender Object
Sender::Sender(int pin, int dotSpeed){
  this->outputPin = pin;
  this->dotRate = dotSpeed;

  pinMode(outputPin, OUTPUT);
}

// send normal string through digital output
void Sender::send_morse_digital(String message){
  String morseMsg = string2morse(message);

  int len = morseMsg.length();
  for(int i = 0; i < len; i++){
    switch (morseMsg[i]){
      case '.':
        digitalWrite(outputPin, HIGH);
        delay(dotRate);
        digitalWrite(outputPin, LOW);
        break;
      case '-':
        digitalWrite(outputPin, HIGH);
        delay(3 * dotRate);
        digitalWrite(outputPin, LOW);
        break;
      case '/':
        digitalWrite(outputPin, LOW);
        delay(3 * dotRate);
        break;
      case ' ':
        digitalWrite(outputPin, LOW);
        delay(7 * dotRate);
        break;
      default: // ERROR
        for(int i = 0; i < 20; i++){
            digitalWrite(outputPin, HIGH);
            delay(dotRate / 3);
            digitalWrite(outputPin, LOW);
            delay(dotRate / 3);
        }
    }
    delay(dotRate);
  }
  ifDone = true;
}

// send normal string through analog output (Mono Jack)
void Sender::send_morse_analog(String message){
  int freq = 440;

  String morseMsg = string2morse(message);

  int len = morseMsg.length();
  for(int i = 0; i < len; i++){
    switch (morseMsg[i]){
      case '.':
        tone(outputPin, freq);
        delay(dotRate);
        noTone(outputPin);
        break;
      case '-':
        tone(outputPin, freq);
        delay(3 * dotRate);
        noTone(outputPin);
        break;
      case '/':
        noTone(outputPin);
        delay(3 * dotRate);
        break;
      case ' ':
        noTone(outputPin);
        delay(7 * dotRate);
        break;
      default: // ERROR
        for(int i = 0; i < 20; i++){
            tone(outputPin, freq);
            delay(dotRate / 3);
            noTone(outputPin);
            delay(dotRate / 3);
        }
    }
    delay(dotRate);
  }
  ifDone = true;
}

// send normal string digitally but in loop function to
// be able to do other tasks in parallel
void Sender::send_morse_digital_parallel(String message){
  message = string2morse(message);

  if(msgPointer != message.length()){
    if(msgPointer == message.length() - 1 && lastState == LOW) // end of message
      ifDone = true;

    if(if_should_sent_impuls())
      send_morse_d(message);
    }
}

// checking function if should sent impuls ON / OFF
boolean Sender::if_should_sent_impuls(){
  currentMilis = millis();

  if(currentMilis - lastSendMilis < waitingTime){
    return false;
  }
  else{
    if(lastState == LOW)
      msgPointer++;
    lastState = !lastState;
    return true;
  }
}

// checks how long should waiting time be before changing state
void Sender::setWaitingTime(char msg){
  if(lastState == HIGH){
    switch (msg){
      case '.':
        waitingTime = dotRate;
        break;
      case '-':
        waitingTime = 3 * dotRate;
        break;
      case ' ':
        waitingTime = 7 * dotRate;
        break;
      case '/':
        waitingTime = 3 * dotRate;
        break;
    }
  }
  else
    waitingTime = dotRate;
}

// functon handling changing digital output
void Sender::send_morse_d(String msg){
  if(msg[msgPointer] == '.' || msg[msgPointer] == '-'){
    digitalWrite(outputPin, lastState);
  }
  else
    digitalWrite(outputPin, LOW);

  lastSendMilis = millis();
  setWaitingTime(msg[msgPointer]);
}
