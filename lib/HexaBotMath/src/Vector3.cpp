//
// Created by zachv on 8/11/2023.
//

#include "Vector3.h"

Vector3::Vector3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::dot(Vector3 v) {
    this->x + v.x;
}

Vector3 operator*(const Vector3& v1, const Vector3& v2) {
    return {
        v1.x * v2.x,
        v1.y * v2.y,
        v1.z * v2.z
    };
}

Vector3 operator/(const Vector3& v1, const Vector3& v2) {
    return {
        v1.x / v2.x,
        v1.y / v2.y,
        v1.z / v2.z
    };
}

Vector3 operator+(const Vector3& v1, const Vector3& v2) {
    return {
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    };
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) {
    return {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };
}

ostream &operator<<(ostream &os, const Vector3 &v1) {
    os << "(" << v1.x << ", " << v1.y << ", " << v1.z << ")";
    return os;
}
