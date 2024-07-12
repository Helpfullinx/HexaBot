#include "InverseKinematics.h"

// Performs inverse kinematics to get the angles of each segment, given the end effector.
void inverseKinematics(const float &x, const float &y, const float &z, float &theta1, float &theta2, float &theta3) {
    theta1 = atan2(y, x);
    float L = sqrt(x*x + y*y);
    float L_prime = L - L_COXA;
    float D = sqrt(L_prime*L_prime + z*z);
    theta2 = atan2(z, L_prime) + acos((L_FEMUR*L_FEMUR + D*D - L_TIBIA*L_TIBIA) / (2 * L_FEMUR * D));
    theta3 = M_PI - acos((L_FEMUR*L_FEMUR + L_TIBIA*L_TIBIA - D*D) / (2 * L_FEMUR * L_TIBIA));

    // Convert to degrees
    theta1 = degrees(theta1);
    theta2 = degrees(theta2);
    theta3 = degrees(theta3);
}


// Calculates the rotation matrix to be applied, given the roll(x), pitch(y), and yaw(z) angles.
// Accepts roll pitch and yaw in degrees!
void rotationMatrix(const float &roll, const float &pitch, const float &yaw, const float &legAngle, BLA::Matrix<3,3> &R) {
    float rollRad = radians(roll);
    float pitchRad = radians(pitch);
    float yawRad = radians(yaw);
    float legAngleRad = radians(legAngle);

    float cos_r = cos(rollRad), sin_r = sin(rollRad);
    float cos_p = cos(pitchRad), sin_p = sin(pitchRad);
    float cos_y = cos(yawRad), sin_y = sin(yawRad);
    float cos_la = cos(legAngleRad), sin_la = sin(legAngleRad);

    // Rotation transformation matrix about the x-axis. Counterclockwise is positive.
    BLA::Matrix<3,3> R_x = {1, 0, 0,
                       0, cos_r, -sin_r,
                       0, sin_r, cos_r};

    // Rotation transformation matrix about the y-axis. Counterclockwise is positive.
    BLA::Matrix<3,3> R_y = {cos_p, 0, sin_p,
                       0, 1, 0,
                       -sin_p, 0, cos_p};

    // Rotation transformation matrix about the z-axis. Counterclockwise is positive.
    BLA::Matrix<3,3> R_z = {cos_y, -sin_y, 0,
                       sin_y, cos_y, 0,
                       0, 0, 1};

    BLA::Matrix<3,3> R_leg = {cos_la, -sin_la, 0,
                         sin_la, cos_la, 0,
                         0, 0, 1};

    // Matrix dot product must be x and y first, then z, then leg angles (from right to left).
    R = R_leg * R_z * R_x * R_y;
}