/*
  MorseLib version 1.2.1

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

// code that decodes and endcodes strings and characters from and to morse code
#include "utility/MorseAlgorithms.h"
// code that handles digital and analog sending as well as non-blocking digital
// sending
#include "utility/MorseOutput.h"

#endif
