#include "MagicRC.h"

MagicRC::MagicRC(uint8_t receivePin, uint8_t transmitPin, uint8_t ia1,uint8_t ib1,uint8_t ia2,uint8_t ib2) {
  btSerial = new SoftwareSerial(receivePin, transmitPin);
  leftSpeed = ia1;
  leftWheel = ib1;
  rightSpeed = ia2;
  rightWheel = ib2;
  pinMode(leftSpeed, OUTPUT);
  pinMode(leftWheel, OUTPUT);
  pinMode(rightSpeed, OUTPUT);
  pinMode(rightWheel, OUTPUT);
  setSpeed(255);
}

void MagicRC::begin(long baudrate) {
  btSerial->begin(baudrate);
}

void MagicRC::setSpeed(uint8_t speed_) {
  speed = speed_;
}

void MagicRC::run() {
  if (btSerial->available()) {
    char c = btSerial->read();

    switch (c) {
      case 'S':
        stop();
        break;
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case '0':
        setSpeed(0);
        break;
      case '1':
        setSpeed(25);
        break;
      case '2':
        setSpeed(50);
        break;
      case '3':
        setSpeed(75);
        break;
      case '4':
        setSpeed(100);
        break;
      case '5':
        setSpeed(125);
        break;
      case '6':
        setSpeed(150);
        break;
      case '7':
        setSpeed(175);
        break;
      case '8':
        setSpeed(200);
        break;
      case '9':
        setSpeed(225);
        break;
      case 'q':
        setSpeed(255);
        break;
      
    }
  }
}

void MagicRC::forward() {
  digitalWrite(leftWheel, LOW);
  analogWrite(leftSpeed, speed);
  digitalWrite(rightWheel, LOW);
analogWrite(rightSpeed, speed);
}

void MagicRC::backward() {
  digitalWrite(leftWheel, HIGH);
  analogWrite(leftSpeed, 255-speed);
  digitalWrite(rightWheel, HIGH);
  analogWrite(rightSpeed, 255-speed);
}

void MagicRC::turnLeft() {
  digitalWrite(leftWheel, LOW);
  analogWrite(leftSpeed, speed);
  digitalWrite(rightWheel, HIGH);
  analogWrite(rightSpeed, 255-speed);
}

void MagicRC::turnRight() {
  digitalWrite(leftWheel, HIGH);
  analogWrite(leftSpeed, 255-speed);
  digitalWrite(rightWheel, LOW);
  analogWrite(rightSpeed, speed);
}

void MagicRC::stop() {
  digitalWrite(leftWheel, LOW);
  digitalWrite(rightWheel, LOW);
  analogWrite(leftSpeed,0);
  analogWrite(rightSpeed,0);
}