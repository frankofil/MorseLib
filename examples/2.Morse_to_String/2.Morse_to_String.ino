#include <MorseLib.h>

void setup() {
  // Message coded in morse
  String message = "...././.-../.-../--- .--/---/.-./.-../-.. ../-. ..---/-----/..---/-----";

  // Setup Serial communication to print result on Serial Monitor
  Serial.begin(9600);

  // Translate morse coded message to text
  String morseResult = morse2string(message);

  // Translate morse coded character to capital ASCII character
  char morseResult2 = morse2char(".--.");

  // Check the result
  Serial.println(morseResult);
  Serial.println(morseResult2);
}

void loop() {}
