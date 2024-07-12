#include "Transforms.h"


void Transforms::servoSetup() {
    pwm1.begin();
    pwm2.begin();

    // Needs tuned with oscilloscope to make sure it is actually outputting 50 Hz
    pwm1.setOscillatorFrequency(25000000);
    pwm1.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
    pwm2.setOscillatorFrequency(25000000);
    pwm2.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

    delay(10);
}


void Transforms::setServoAngle(const uint8_t &servoNum, float &angle) {
    // Ensure angle is within the valid range
    if (angle < ANGLE_MIN) angle = ANGLE_MIN;
    if (angle > ANGLE_MAX) angle = ANGLE_MAX;

    // Map angle to the pulse length
    uint16_t pulseLength = map(angle, ANGLE_MIN, ANGLE_MAX, SERVO_MIN, SERVO_MAX);

    // Set the PWM signal for the specified servo and determine which driver
    if (servoNum <= 16 & servoNum > 0) {
        pwm1.setPWM(servoNum - 1, 0, pulseLength);  // PWM driver 1 handles servos 1-16
    } else if (servoNum <= 32) {
        pwm2.setPWM(servoNum - 17, 0, pulseLength);  // PWM driver 2 handles servos 17-32
    } else {
        Serial.println("Couldn't find servo number...");
    }
}


void Transforms::moveLeg(const int &legId, const Point &start, const Point &end, const int &duration, const int &steps) {
    float stepDuration = (float) duration / steps;  // duration is in milliseconds
    for (int i = 0; i <= steps; i++) {
        float t = (float) i / steps;

        // Calculates lerp step
        Point stepPos = start + (end - start) * t;
        // Updates Z position to follow arc. Adjust height as needed (millimeters).
        stepPos(2) += (sin(t * M_PI) * 50);

        float theta1, theta2, theta3;
        inverseKinematics(stepPos(0), stepPos(1), stepPos(2), theta1, theta2, theta3);

        // Determine which servos correspond to the given legId
        int servoBase = legId * 3 + 1;  // Assuming servos are numbered sequentially

        // Set the servo angles
        setServoAngle(servoBase, theta1);  // Coxa angle
        setServoAngle(servoBase + 1, theta2);  // Femur angle
        setServoAngle(servoBase + 2, theta3);  // Tibia angle

        delay(stepDuration);
    }
}
