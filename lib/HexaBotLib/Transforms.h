#ifndef HEXAPOGBOT_TRANSFORMS_H
#define HEXAPOGBOT_TRANSFORMS_H

#include "Adafruit_PWMServoDriver.h"
#include "Parameters.h"
#include "InverseKinematics.h"

using namespace BLA;

// Two PWM chips on the board. pwm1 will be 1-16, pwm2 will be 17-32.
// May need I2C initialization with custom pins??
static Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
static Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

/// Defines a movement
struct Transformation {
    Point bodyPosition;
    EulerRotation bodyOrientation;
    Point *startPosition;
    Point *endPosition;
};

void servoSetup();
void setServoAngle(const uint8_t &servoNum, float &angle);
void moveLegs(const Transformation &ts, const int &duration, const int &steps);

#endif //HEXAPOGBOT_TRANSFORMS_H
