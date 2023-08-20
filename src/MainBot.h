#ifndef HEXABOT_MAINBOT_H
#define HEXABOT_MAINBOT_H

#include <Body.h>

class MainBot {
public:
    Body body;
    Vector3 root;
    Vector3 iktarget;
    Segment coxa = Segment(root, 100.0);
    Segment tibia = Segment(*coxa.tail, 100.0);
    Segment femur = Segment(*tibia.tail,100.0);
    Leg leg = Leg(iktarget);

    MainBot() {
        leg.AddSegmentToEnd(coxa);
        leg.AddSegmentToEnd(tibia);
        leg.AddSegmentToEnd(femur);

        body.AddLeg(leg);
    }
};


#endif //HEXABOT_MAINBOT_H
