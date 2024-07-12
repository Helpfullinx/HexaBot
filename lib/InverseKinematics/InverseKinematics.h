//
// Created by matty on 7/11/2024.
//

#ifndef HEXAPOGBOT_INVERSEKINEMATICS_H
#define HEXAPOGBOT_INVERSEKINEMATICS_H

#include "BasicLinearAlgebra.h"
#include "Transforms.h"

using namespace BLA;

void inverseKinematics(const float &x, const float &y, const float &z, float &theta1, float &theta2, float &theta3);
void rotationMatrix(const float &roll, const float &pitch, const float &yaw, const float &legAngle, BLA::Matrix<3,3> &R);
void transformAndIK(const Transforms::Point &bodyPos, const Transforms::EulerRotation &rotation, const Transforms::Point startPositions[], const Transforms::Point endPositions[], const int &duration, const int &steps);

#endif //HEXAPOGBOT_INVERSEKINEMATICS_H
