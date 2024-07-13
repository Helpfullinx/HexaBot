#include "main.h"

uint8_t servonum = 1;

void setup() {
    Serial.begin(115200);
    while(!Serial.available());

    Serial.println("Initializing servos...");

    servoSetup();

    Point startPositions[LEG_COUNT] = {
            {100, 100, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    Point endPositions[LEG_COUNT] = {
            {150, 150, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    Point bodyPos = {0, 0, 0};
    EulerRotation bodyOrientation = {0, 0, 0};

    Transformation t = {
            bodyPos,
            bodyOrientation,
            startPositions,
            endPositions
    };


    moveLegs(t, 10000, 50);
}

void loop() {


    // Drive each servo one at a time using setPWM()
//    Serial.printf("Servo_Min = %i", SERVO_MIN);
//    Serial.printf("Servo_Max = %i", SERVO_MAX);
//    for (uint16_t pulselen = SERVO_MIN; pulselen < SERVO_MAX; pulselen++) {
//        pwm1.setPWM(servonum, 0, pulselen);
//    }
//
//    delay(500);
//    for (uint16_t pulselen = SERVO_MAX; pulselen > SERVO_MIN; pulselen--) {
//        pwm1.setPWM(servonum, 0, pulselen);
//    }
//
//    delay(500);

}