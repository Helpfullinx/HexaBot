#include "Leg.h"

Leg::Leg(Vector3& iktarget) {
    this->iktarget = &iktarget;
}

void Leg::AddSegmentToEnd(Segment& segment) {
    this->segments.push_back(&segment);
}

void Leg::CalculateIK() {
    //TODO
}
