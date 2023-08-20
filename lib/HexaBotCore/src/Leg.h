#ifndef HEXABOT_LEG_H
#define HEXABOT_LEG_H

#include <list>
#include "Segment.h"
using namespace std;

class Leg {
public:
    list<Segment*> segments;
    Vector3* iktarget;
    Leg(Vector3&);
    void AddSegmentToEnd(Segment&);
    void CalculateIK();
};


#endif //HEXABOT_LEG_H
