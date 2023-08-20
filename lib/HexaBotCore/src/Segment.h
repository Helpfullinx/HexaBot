#ifndef HEXABOT_SEGMENT_H
#define HEXABOT_SEGMENT_H

#include "Vector3.h"

class Segment {
public:
    Vector3* head;
    Vector3* tail;
    double length;

    Segment(Vector3&, float);
    void CalculateTail() const;
};


#endif //HEXABOT_SEGMENT_H
