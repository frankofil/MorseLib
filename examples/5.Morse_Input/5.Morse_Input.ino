#include <MorseLib.h>

// define input button pin
#define BUTTON 3

//create digital receiver
Receiver r = Receiver(BUTTON);

void setup() {
  // set button pin as input
  pinMode(BUTTON, INPUT);

  // Setup serial communication to see the result
  Serial.begin(9600);

  char last = 0; // last added morse character to input string
  int lastSpace = 0; // last / or space that we have seen
  int pos = -1; // current end of morse input string

  while(!r.get_morse_input_digital()){ // keeps running if the message is not over
    last = r.msg[r.msg.length() - 1]; //updating last
    pos = r.msg.length() - 1; // updating pos

    // checking if the last input character was a space or /
    if((last == ' ' || last == '/') && (lastSpace < pos)){
      lastSpace = pos; // updating lastSpace
      //printing translated message that we have so far
      Serial.println(morse2string(r.msg));
    }
  }
  // after end of connection shows full received message
  Serial.print("Final result is: ");
  Serial.println(morse2string(r.msg));

  // kill the program
  delay(200);
  exit(0);
}

void loop() {}
