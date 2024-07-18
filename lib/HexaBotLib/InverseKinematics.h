#ifndef HEXAPOGBOT_INVERSEKINEMATICS_H
#define HEXAPOGBOT_INVERSEKINEMATICS_H

#include "Parameters.h"

using namespace BLA;

void inverseKinematics(const float &x, const float &y, const float &z, float &theta1, float &theta2, float &theta3);
void rotationMatrix(const float &roll, const float &pitch, const float &yaw, BLA::Matrix<3,3> &R);

#endif //HEXAPOGBOT_INVERSEKINEMATICS_H
