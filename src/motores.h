#pragma once
#include <Arduino.h>


void initMotors();
void setSpeed(unsigned char pwm);
void advance();
void back();
void turnL();
void turnR();
void stopp();
