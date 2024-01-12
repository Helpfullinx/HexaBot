#ifndef HEXABOT_MAINBOT_H
#define HEXABOT_MAINBOT_H

#include <Body.h>

class MainBot {
public:
    Body body;

    Leg leg = Leg();

    MainBot() {

        body.AddLeg(leg);
    }
};


#endif //HEXABOT_MAINBOT_H
