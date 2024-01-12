#ifndef HEXABOT_LEG_H
#define HEXABOT_LEG_H

#include <list>
#include "Vector3.h"
#include "Util.h"

using namespace std;

struct Segment{
    // Length of the segment
    float length;
    // Angle of the servo at the base of this segment
    float angle;

    Segment( const float f1, const float f2 ) {
        length = f1;
        angle = f2;
    };
};

class Leg {
public:
    Segment* segments[3];
    Vector3 ikTarget = Vector3();

    Leg();
    void CalculateIK();
};

#endif //HEXABOT_LEG_H
