#ifndef HEXABOT_VECTOR3_H
#define HEXABOT_VECTOR3_H

#include <iostream>

using namespace std;

class Vector3 {
public:
    float x;
    float y;
    float z;

    Vector3();
    Vector3(float, float, float);
    static void lerp(Vector3&, Vector3&, int, int);
    inline static float dot(Vector3&, Vector3&);
    inline friend Vector3 operator*(const Vector3&, const Vector3&);
    inline friend Vector3 operator/(const Vector3&, const Vector3&);
    inline friend Vector3 operator+(const Vector3&, const Vector3&);
    inline friend Vector3 operator+=(Vector3&, const Vector3&);
    inline friend Vector3 operator-(const Vector3&, const Vector3&);
    inline friend Vector3 operator*(const Vector3&, float);
    inline friend Vector3 operator/(const Vector3&, float);
    inline friend Vector3 operator+(const Vector3&, float);
    inline friend Vector3 operator-(const Vector3&, float);
    inline friend bool operator==(const Vector3&, const Vector3&);
    inline friend bool operator!=(const Vector3&, const Vector3&);
};


#endif //HEXABOT_VECTOR3_H
