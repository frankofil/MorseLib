/*
  MorseLib version 1.2.4

  Author: Franciszek Myslek [frm20]
  Module: CS12020 - Introduction to Programming

  This library helps you with morse code decoding and encoding
  as well as with sending morse code without blocking other processes.

  For usage instructions please see the built-in examples.
*/

#ifndef MORSELIBC_H
#define MORSELIBC_H

// main Arduino library
#include <Arduino.h>

// every port info
struct port {
  String name; // name of the port
  int pin;
  bool mode; // INPUT / OUTPUT
  String source; // "DIGITAL", "ANALOG", "SERIAL"
  bool handleMorse; // handle signal input (true) or String text(false)
  bool state; // if should send
  int frequency; // frequency for analog signals
};

// code that decodes and endcodes strings and characters from and to morse code
#include "utility/MorseAlgorithms.h"
// code that handles digital and analog sending as well as non-blocking digital
// sending
#include "utility/MorseOutput.h"
// code that handles morse code input from digital pin (button, etc)
#include "utility/MorseInput.h"

#endif
