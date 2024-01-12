#ifndef HEXABOT_UTIL_H
#define HEXABOT_UTIL_H

#include "Vector3.h"
#define FEMUR_LENGTH 189.180
#define TIBIA_LENGTH 83.250
#define COXA_LENGTH 48.725


class Util {
    public:
        static inline float radiansToDegrees(float);
        static inline float degreesToRadians(float);
};

#endif //HEXABOT_UTIL_H
