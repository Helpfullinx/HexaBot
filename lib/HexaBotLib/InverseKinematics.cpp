#include "InverseKinematics.h"

// Performs inverse kinematics to get the angles of each segment, given the end effector.
void inverseKinematics(const float &x, const float &y, const float &z, float &theta1, float &theta2, float &theta3) {
    if (sqrt(x*x + y*y + z*z) < (L_FEMUR + L_TIBIA + L_COXA)) {
        // Coxa angle from -90 to 90 degrees
        theta1 = atan2(y, x);

        // Distances given the point
        float L = sqrt(x * x + y * y);  // Length of the leg from the top view
        Serial.println(L);
        float L_prime = L - L_COXA;
        Serial.println(L_prime);
        float D = sqrt(L_prime * L_prime + z * z);  // Distance from L' to the endpoint of the tibia
        Serial.println(D);

        // Calculate intermediary angles A1 and A2
        float a1 = atan2(L_prime, z);
        Serial.println(degrees(a1));
        float a2 = acos((L_TIBIA * L_TIBIA - L_FEMUR * L_FEMUR - D * D) / (-2 * L_FEMUR * D));
        Serial.println(degrees(a2));

        // Calculate intermediary angle B1
        float b1 = acos((D * D - L_FEMUR * L_FEMUR - L_TIBIA * L_TIBIA) / (-2 * L_FEMUR * L_TIBIA));
        Serial.println(degrees(b1));

        // Calculate theta2 and theta3 using horizontal reference approach
        theta2 = (degrees(a1) + degrees(a2));
        theta3 = 180 - degrees(b1);

        // Convert to degrees
        theta1 = degrees(theta1) + 90.0 - 45;
    } else {
        Serial.println("MATH ERROR: coordinate beyond range of leg...");
        theta1 = degrees(atan2(y, x)) + 90.0 - 45;
        theta2 = 90;
        theta3 = 0;
    }
}


// Calculates the rotation matrix to be applied, given the roll(x), pitch(y), and yaw(z) angles.
// Accepts roll pitch and yaw in degrees!
void rotationMatrix(const float &roll, const float &pitch, const float &yaw, BLA::Matrix<3,3> &R) {
    float rollRad = radians(roll);
    float pitchRad = radians(pitch);
    float yawRad = radians(yaw);

    float cos_r = cos(rollRad), sin_r = sin(rollRad);
    float cos_p = cos(pitchRad), sin_p = sin(pitchRad);
    float cos_y = cos(yawRad), sin_y = sin(yawRad);

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

    // Matrix dot product must be x and y first, then z, then leg angles (from right to left).
    R = R_z * R_y * R_x;
}