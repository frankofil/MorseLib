#include <MorseLib.h>

// define pin of digital output
#define LED_PIN 10
#define LED_PIN2 11

// speed of transfer in miliseconds (OPTIONAL)
int speed = 250;

// crating digital sender with default speed
Sender digitalSender = Sender(LED_PIN);
// crating digital sender with personal speed
Sender fastDigitalSender = Sender(LED_PIN2, speed);

// Message that will be sent
String message = "Hello";

void setup() {
  // Setup Serial communication to print result on Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // send morse using digital output without blocking other processes
  if(!digitalSender.fully_send())
    digitalSender.send_morse_digital_parallel(message);
  else
    Serial.println("1st process done");

  if(!fastDigitalSender.fully_send())
    fastDigitalSender.send_morse_digital_parallel(message);
  else
    Serial.println("2nd process done");

  // you can still do other stuff (print something, react to input, etc.)
  Serial.println("3rd process is still running");
}
