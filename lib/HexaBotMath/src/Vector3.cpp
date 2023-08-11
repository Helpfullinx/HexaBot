//
// Created by zachv on 8/11/2023.
//

#include "Vector3.h"

Vector3::Vector3() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::dot(Vector3 v) {
    this->x + v.x;
}

Vector3 Vector3::operator*(const Vector3 &v) {
    this->x * v.x;
    this->y * v.y;
    this->x * v.x;
    return *this;
}

Vector3 Vector3::operator/(const Vector3 &v) {
    this->x / v.x;
    this->y / v.y;
    this->x / v.x;
    return *this;
}

Vector3 Vector3::operator+(const Vector3 &v) {
    this->x + v.x;
    this->y + v.y;
    this->x + v.x;
    return *this;
}

Vector3 Vector3::operator-(const Vector3 &v) {
    this->x - v.x;
    this->y - v.y;
    this->x - v.x;
    return *this;
}
