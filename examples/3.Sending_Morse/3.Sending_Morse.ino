#include <MorseLib.h>

// define pin of digital output
#define LED_PIN 10

//define pin of analog output
#define MONO_JACK A2

#define NDEVICES 2

port devices[NDEVICES] ={
  {"Blue_LED", LED_PIN, OUTPUT, "DIGITAL", true, HIGH, 0},
  {"Jack", MONO_JACK, OUTPUT, "ANALOG", true, HIGH, 0},
};

// defining personal transmition speed
int speed = 300;

// crating digital sender with default speed
Sender digitalSender = Sender(devices[0]);
// crating digital sender with personal speed
Sender fastDigitalSender = Sender(devices[0], speed);
// crating analog sender with default speed
Sender analogSender = Sender(devices[1]);
// crating analog sender with personal speed
Sender fastAnalogSender = Sender(devices[1], speed);

void setup() {
  // Message that will be sent
  String message = "Hello World";

  // Send your message to digital pin with default speed (500 miliseconds)
  digitalSender.send_message(message);

  // Send your message to digital pin with preferable speed
  fastDigitalSender.send_message(message);

  // Send your message to analog pin with default speed (500 miliseconds)
  analogSender.send_message(message);

  // Send your message to analog pin with preferable speed
  fastAnalogSender.send_message(message);
}

void loop() {}
