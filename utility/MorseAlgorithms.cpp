#include  "../MorseLib.h"


const int alphaLen = 54; // length of alphabet
const int numStart = 26; // start of numbers in a table
const int specialStart = 35;
// Morse Alphabet
const String morseTable[alphaLen] =
  {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
   "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
   "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-",
   "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...",
   "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.",
   "...-..-", ".--.-."};
// English Alphabet
const char letterTable[alphaLen] =
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
   'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
   '4', '5', '6', '7', '8', '9', '.', ',', '?', 39, '!', '/', '(', ')', '&',
   ':', ';', '=', '+', '-', '_', '"', '$', '@'};


// lowercase letters to uppercase
char upper(char letter){
 if (letter > 96 && letter < 123)
   return letter - 32;
 return letter;
}

// turn a character into morse equivalent
String char2morse(char character){
  character = upper(character);

  if(character == ' ') // space
    return " ";
  else if(character >= 'A' && character <= 'Z') // capital letters
    return morseTable[character - 65];
  else if(character >= '0' && character <= '9')
    return morseTable[numStart + character - '0'];
  else{
    for(int i = specialStart - 1; i < alphaLen; i++)
      if(character == letterTable[i])
        return morseTable[i];
  }
  return "........";
}

// turn morse character into letter equivalent
char morse2char(String morseChar){
  if(morseChar == "........")
    return '*';
  else if(morseChar == " ")
    return ' ';

  int i = 0;
  while(morseTable[i] != morseChar && i < alphaLen - 1){
    i++;
    if(i == alphaLen - 1 && morseTable[i] != morseChar)
      return '*';
  }

  return letterTable[i];
}

//turn string into morse string
String string2morse(String s){
  String morseS = "";

  int len = s.length();
  for(int i = 0; i < len; i++){
    if(morseS != "")
      if(morseS[morseS.length() - 1] != ' ' && s[i] != ' ')
        morseS += "/";
    morseS += char2morse(s[i]);
  }

  return morseS;
}

//turn morse message into letters
String morse2string(String s){
  int sLen = s.length();
  String character = "";
  String words = "";

  for (int i = 0; i < sLen; i++){
    if(s[i] == ' '){
      words += morse2char(character);
      words += " ";
      character = "";
    }
    else if(s[i] == '/'){
      words += morse2char(character);
      character = "";
    }
    else if(i == sLen - 1){
      character += s[i];
      words += morse2char(character);
      character = "";
    }
    else
      character += s[i];
  }
  return words;
}
