#include <Arduino.h>
#include "motores.h"
#include "radar.h"

void esquivarHacia(void (*giro)()) {
  centerRadar();
  giro();
  setSpeed(100);
  delay(200);
  advance();
  setSpeed(100);
}

void setup() {
  initMotors();
  initRadar();
}

void loop() {
  float distanciaFrente = checkDistance();

  if (distanciaFrente < 20) {
    stopp();
    setSpeed(0);
    delay(1000);

    int DL = 0, DR = 0;
    detectObstacleDistance(DL, DR);

    if (DL < 50 || DR < 50) {
      if (DL > DR) {
        esquivarHacia(turnL);
      } else {
        esquivarHacia(turnR);
      }
    } else {
      if (random(1, 10) > 5) {
        esquivarHacia(turnL);
      } else {
        esquivarHacia(turnR);
      }
    }
  } else {
    // Camino libre: avanzar continuo
    advance();
    setSpeed(100);
  }
}
