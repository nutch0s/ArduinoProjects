/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>


RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
Servo myServo;
boolean buttonState = 0;

void setup() {
  int servoOn = 0;
  int motorOn = 0;
  pinMode(3, OUTPUT);
  myServo.attach(5);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
  return 0;
}

void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      int servoOn = 0;
      int motorOn = 0;
      radio.read(motorOn, servoOn);
      if (servoOn == 1){
        return 180;
        delay(500);
        return 0;
      }
      if (motorOn == 1){
        digitalWrite(3, HIGH);
        Serial.println("plz work");
    }
    delay(5);
    // radio.stopListening();
    // buttonState = digitalRead(button);
    // radio.write(&buttonState, sizeof(buttonState));
  }
}}