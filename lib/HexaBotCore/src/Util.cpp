#include "Util.h"
#include "math.h"

float Util::radiansToDegrees(const float radians) {
    return radians * (180 / M_PI);
}

float Util::degreesToRadians(const float degrees) {
    return degrees * (M_PI / 180);
}
