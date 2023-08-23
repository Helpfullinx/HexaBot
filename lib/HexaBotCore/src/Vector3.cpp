#include <Arduino.h>
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

/**
 * @param v1 First Vector
 * @param v2 Second Vector
 * @return Returns back the dotproduct between the pair of Vector3 points
 * */

double Vector3::dot(Vector3& v1, Vector3& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

/**
 * Linearly interpolates between pair of Vector3 points. This function will stop lerping if the target is changed.
 *
 * @param start Starting point of Linear interpolation. **WARNING This variable is changed inside the function**
 * @param target The linear interpolation target that the starting point will move toward
 * @param numSteps The accuracy of the movement (Lower number = less accurate, High number = more accurate)
 * @param speed The total time it takes to travel the distance between vectors (in milliseconds)
 * */

void Vector3::lerp(Vector3& start, Vector3& target, int numSteps, int speed) {
    Vector3 tmp = start;
    Vector3 initTarget = target;
    const int totalTime = speed/numSteps;

    const float t = 1 / (float) numSteps;
    float step = t;
    for (int i = 0; i < numSteps; ++i) {
        start += ((target - tmp) * t);
        step + t;
        if (initTarget != target){
            break;
        }
        delay(totalTime);
    }
}

//Vector3 with Vector3

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

Vector3 operator+=(Vector3 &v1, const Vector3& v2) {
    return {
        v1.x += v2.x,
        v1.y += v2.y,
        v1.z += v2.z
    };
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) {
    return {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };
}

//Vector3 with Float

Vector3 operator*(const Vector3& v1, const float value) {
    return {
            v1.x * value,
            v1.y * value,
            v1.z * value
    };
}

Vector3 operator/(const Vector3& v1, const float value) {
    return {
            v1.x / value,
            v1.y / value,
            v1.z / value
    };
}

Vector3 operator+(const Vector3& v1, const float value) {
    return {
            v1.x + value,
            v1.y + value,
            v1.z + value
    };
}

Vector3 operator-(const Vector3& v1, const float value) {
    return {
            v1.x - value,
            v1.y - value,
            v1.z - value
    };
}

//Conditionals

bool operator==(const Vector3& v1, const Vector3& v2) {
    if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) {
        return true;
    }
    return false;
}

bool operator!=(const Vector3& v1, const Vector3& v2) {
    if (v1.x != v2.x || v1.y != v2.y || v1.z != v2.z) {
        return true;
    }
    return false;
}
