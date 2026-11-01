#include "radar.h"
#include <Servo.h>

const int PIN_TRIG = A1;
const int PIN_ECHO = A0;
const int PIN_SERVO = A2;

static Servo srv;

void initRadar() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  srv.attach(PIN_SERVO);
  centerRadar();
}

void centerRadar() {
  srv.write(90);
}

float checkDistance() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  float distance = pulseIn(PIN_ECHO, HIGH) / 58.00;
  delay(10);
  return distance;
}

void detectObstacleDistance(int &distanciaIzq, int &distanciaDer) {

  srv.write(160);
  for (int i = 0; i < 3; i++) {
    distanciaIzq = checkDistance();
    delay(100);
  }


  srv.write(20);
  for (int i = 0; i < 3; i++) {
    distanciaDer = checkDistance();
    delay(100);
  }
}
