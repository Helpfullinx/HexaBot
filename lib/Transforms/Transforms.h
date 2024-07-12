#ifndef HEXAPOGBOT_TRANSFORMS_H
#define HEXAPOGBOT_TRANSFORMS_H

#include "Adafruit_PWMServoDriver.h"
#include "BasicLinearAlgebra.h"
#include "InverseKinematics.h"

using namespace BLA;

// HEXAPOD BABY!!
#define LEG_COUNT 6

// Length of each segment of the leg in millimeters
#define L_COXA  48.73
#define L_FEMUR 82.25
#define L_TIBIA 189.18

// Tune the values below to suit the servos we have. We want maximum travel without hitting the end stops!
#define SERVO_MIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVO_MAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define ANGLE_MIN  0 // Minimum angle for the servo
#define ANGLE_MAX  180 // Maximum angle for the servo



// Struct for desired locations in xyz coords
//struct Point {
//    float x, y, z;
//};

// Where each leg attaches to the body in respect to the center point of the body.
// First leg is top right, then clockwise after.
//Point attachmentPoints[LEG_COUNT] = {
//        {66.16, 79.71, 0},   // Front Right (Index 0)
//        {103.59, 0, 0},      // Middle Right (Index 1)
//        {66.16, -79.71, 0},  // Rear Right (Index 2)
//        {-66.16, -79.71, 0}, // Rear Left (Index 3)
//        {-103.59, 0, 0},     // Middle Left (Index 4)
//        {-66.16, 79.71, 0}   // Front Left (Index 5)
//};

class Transforms {
public:
    typedef BLA::Matrix<3> Point;
    typedef BLA::Matrix<3> EulerRotation;

    // Two PWM chips on the board. pwm1 will be 1-16, pwm2 will be 17-32.
    // May need I2C initialization with custom pins??
    Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
    Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

    // Clockwise orientation of each leg's frame in reference to the body frame.
    float legAngles[LEG_COUNT] = {-45, -90, -135, -225, -270, -315};

    void servoSetup();
    void setServoAngle(const uint8_t &servoNum, float &angle);
    static void moveLeg(const int &legId, const Point &start, const Point &end, const int &duration, const int &steps);

    Point attachmentPoints[LEG_COUNT] = {
        {66.16, 79.71, 0},   // Front Right (Index 0)
        {103.59, 0, 0},      // Middle Right (Index 1)
        {66.16, -79.71, 0},  // Rear Right (Index 2)
        {-66.16, -79.71, 0}, // Rear Left (Index 3)
        {-103.59, 0, 0},     // Middle Left (Index 4)
        {-66.16, 79.71, 0}   // Front Left (Index 5)
    };
};


#endif //HEXAPOGBOT_TRANSFORMS_H
