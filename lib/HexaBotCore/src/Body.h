#ifndef HEXABOT_BODY_H
#define HEXABOT_BODY_H

#include <FreeRTOS.h>
#include <list.h>
#include "Leg.h"
using namespace std;

class Body {
public:
    list<Leg*> legs;
    Body();
    void CalculateAllIK();
    void AddLeg(Leg&);
};


#endif //HEXABOT_BODY_H
