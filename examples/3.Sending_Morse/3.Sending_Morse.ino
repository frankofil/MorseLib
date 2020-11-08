#include <MorseLib.h>

// define pin of digital output
#define LED_PIN 10

//define pin of analog output
#define MONO_JACK A2

// defining personal transmition speed
int speed = 300;

// crating digital sender with default speed
Sender digitalSender = Sender(LED_PIN);
// crating digital sender with personal speed
Sender fastDigitalSender = Sender(LED_PIN, speed);
// crating analog sender with default speed
Sender analogSender = Sender(MONO_JACK);
// crating analog sender with personal speed
Sender fastAnalogSender = Sender(MONO_JACK, speed);

void setup() {
  // Message that will be sent
  String message = "Hello World";

  // Send your message to digital pin with default speed (500 miliseconds)
  digitalSender.send_morse_digital(message);

  // Send your message to digital pin with preferable speed
  fastDigitalSender.send_morse_digital(message);

  // Send your message to analog pin with default speed (500 miliseconds)
  analogSender.send_morse_analog(message);

  // Send your message to analog pin with preferable speed
  fastAnalogSender.send_morse_analog(message);
}

void loop() {}
