#include <MorseLib.h>

void setup() {
  // Setup Serial communication to print result on Serial Monitor
  Serial.begin(9600);

  // Translate text "Hello World in 2020" to morse code
  String morseResult = string2morse("Hello World in 2020");

  // Translate one character to morse code
  String morseResult2 = char2morse('p');

  // Check the result
  Serial.println(morseResult);
  Serial.println(morseResult2);
}

void loop() {}
