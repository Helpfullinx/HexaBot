#include "Body.h"

Body::Body() {
}

void Body::CalculateAllIK() {
    //TODO
}

void Body::AddLeg(Leg& l) {
    this->legs.push_back(&l);
}
