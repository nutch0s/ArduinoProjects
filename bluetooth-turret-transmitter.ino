/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;


const int buttonPin = 2;
int motorSwitch = 0;
int servoButton = 0;
int servoOn = 0;
int motorOn = 0;


void setup() {

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
// // int motorSwitch = 0;
// int servoButton = 0;
// int servoOn = 0;
// int motorOn = 0;
digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  motorSwitch = digitalRead(buttonPin);
  // motorSwitch == digitalRead(2);
  // servoButton == digitalRead(3);
  delay(5);
    // radio.write(motorOn, servoOn);

  // radio.stopListening();

if (motorSwitch == HIGH){
  int motorOn = 1;
  Serial.print("big men");
  radio.write(&motorOn, sizeof(motorOn));

  }

  if (servoButton == HIGH){
    int servoOn = 1;}


  //  radio.write(&angleValue, sizeof(angleValue));

  delay(5);
}
