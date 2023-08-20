#include "Segment.h"

Segment::Segment(Vector3& head, const float length) {
    this->head = &head;
    this->length = length;
    this->tail = new Vector3();
    CalculateTail();
}

void Segment::CalculateTail() const {
    *tail = *head;
    tail->x += length;
}
