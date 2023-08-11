//
// Created by zachv on 8/11/2023.
//
#ifndef HEXABOT_VECTOR3_H
#define HEXABOT_VECTOR3_H

using namespace std;

class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3();
    Vector3(double, double, double);
    Vector3 dot(Vector3);
    Vector3 operator*(const Vector3& v);
    Vector3 operator/(const Vector3& v);
    Vector3 operator+(const Vector3& v);
    Vector3 operator-(const Vector3& v);
};


#endif //HEXABOT_VECTOR3_H
