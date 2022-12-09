#pragma once

#include <Arduino.h>

class PIDController {
private:
    float Kp, Ki, Kd;

    float currError = 0;
    float prevError = 0;
    float sumError = 0;
    float errorBound = 0;
    
    float currEffort = 0;

public:
    static volatile uint8_t readyToPID;

public:
    PIDController(float p, float i = 0, float d = 0, float bound = 0) : Kp(p), Ki(i), Kd(d), errorBound(bound) {}
    float ComputeEffort(float error);
    float computeEffort(float error) {return ComputeEffort(error);}

    float setKp(float k) {return Kp = k;}
    float setKi(float k) {return Ki = k;}
    float setKd(float k) {return Kd = k;}
    float setCap(float cap) {return errorBound = cap;}
};