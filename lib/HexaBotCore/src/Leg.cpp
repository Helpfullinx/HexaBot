#include "Leg.h"
#include "Vector3.h"
#include "math.h"
#include "Util.h"

Leg::Leg() {
    Segment coxa(COXA_LENGTH,90.0);
    Segment tibia(TIBIA_LENGTH,90.0);
    Segment femur(FEMUR_LENGTH,180.0);


    segments[0] = &coxa;
    segments[1] = &tibia;
    segments[2] = &femur;
}

void Leg::CalculateIK() {
    // calculate inverse kinematic solution for J1-J3

    ikTarget.y += 161.0;
    ikTarget.z += -69.4;

    const float J1 = Util::radiansToDegrees(atan(ikTarget.x / ikTarget.y));
    const float H = sqrt((pow(ikTarget.y,2)) + (pow(ikTarget.x,2))) - COXA_LENGTH;
    const float L = sqrt(pow(ikTarget.z,2)) + (pow(H,2));
    const float J3 = Util::radiansToDegrees(acos((pow(TIBIA_LENGTH, 2) + pow(FEMUR_LENGTH,2) - pow(L,2)) / (2 * TIBIA_LENGTH * FEMUR_LENGTH)));
    const float B = Util::radiansToDegrees(acos((pow(L,2) + pow(TIBIA_LENGTH,2) - (FEMUR_LENGTH,2)) / (2*L*TIBIA_LENGTH)));
    const float A = Util::radiansToDegrees(atan(ikTarget.z / H));
    const float J2 = (ikTarget.z > 0) ? 90 - (B - A) : 90 - (B + A);

    // update the segments to the new angles
    segments[0]->angle = J1;
    segments[1]->angle = J2;
    segments[2]->angle = J3;
}
