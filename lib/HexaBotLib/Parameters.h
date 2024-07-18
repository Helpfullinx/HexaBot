#ifndef HEXABOT_PARAMETERS_H
#define HEXABOT_PARAMETERS_H

#include "BasicLinearAlgebra.h"

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

typedef BLA::Matrix<3> Point;
typedef BLA::Matrix<3> EulerRotation;

// Clockwise orientation of each leg's frame in reference to the body frame.
const float LEG_ANGLES[LEG_COUNT] = {-45.0, -90.0, -135.0, -225.0, -270.0, -315.0};

// Where each leg attaches to the body in respect to the center point of the body.
// First leg is top right, then clockwise after.
const Point ATTACHMENT_POINTS[LEG_COUNT] = {
        {66.16,   79.71,  0},   // Front Right (Index 0)
        {103.59,  0,      0},      // Middle Right (Index 1)
        {66.16,   -79.71, 0},  // Rear Right (Index 2)
        {-66.16,  -79.71, 0}, // Rear Left (Index 3)
        {-103.59, 0,      0},     // Middle Left (Index 4)
        {-66.16,  79.71,  0}   // Front Left (Index 5)
};

#endif //HEXABOT_PARAMETERS_H
