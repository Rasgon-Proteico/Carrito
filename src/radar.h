#pragma once
#include <Arduino.h>

void initRadar();
float checkDistance();
void detectObstacleDistance(int &distanciaIzq, int &distanciaDer);
void centerRadar();
