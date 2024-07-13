#include "Transforms.h"

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);


void servoSetup() {
    pwm1.begin();
    pwm2.begin();

    // Needs tuned with oscilloscope to make sure it is actually outputting 50 Hz
    pwm1.setOscillatorFrequency(25000000);
    pwm1.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
    pwm2.setOscillatorFrequency(25000000);
    pwm2.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

    delay(10);
}


void setServoAngle(uint8_t servoNum, float angle) {
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

void moveLegs(const Transformation &ts, const int &duration, const int &steps) {
    // Resultant Rotation matrix used in transforming start and end positions
    BLA::Matrix<3,3> R;

    // Iterate over legs, calculating their joint rotation values
    for (int i = 0; i < LEG_COUNT; i++) {
        // Calculate rotation matrix for leg
        rotationMatrix(ts.bodyOrientation(0), ts.bodyOrientation(1), ts.bodyOrientation(2), LEG_ANGLES[i], R);

        // Transforms the start position and end position of the current leg in relation to the body position
        Point startPosTransformed = R * (ts.startPosition[i] - ts.bodyPosition) + ATTACHMENT_POINTS[i];
        Point endPosTransformed = R * (ts.endPosition[i] - ts.bodyPosition) + ATTACHMENT_POINTS[i];

        // Calculate step duration for current lerp step
        float stepDuration = (float) duration / steps;  // duration is in milliseconds

        // Iterate through steps to calculate the IK for each leg and set the servos to those results
        for (int j = 0; j <= steps; j++) {
            float t = (float) j / steps; // How far we are into the lerp

            // Calculates lerp step
            Point stepPos = startPosTransformed + (endPosTransformed - startPosTransformed) * t;

            // Updates Z position to follow arc. Adjust height as needed (millimeters).
            stepPos(2) += (sin(t * M_PI) * 50);

            // Resultant angle values
            float theta1, theta2, theta3;
            inverseKinematics(stepPos(0), stepPos(1), stepPos(2), theta1, theta2, theta3);

            // Determine which servos correspond to the given legId
            int servoBase = i * 3 + 1;  // Assuming servos are numbered sequentially

            // Set the servo angles
            Serial.printf("%d, %f\n\r", servoBase, theta1);
            Serial.printf("%d, %f\n\r", servoBase + 1, theta2);
            Serial.printf("%d, %f\n\r", servoBase + 2, theta3);

            setServoAngle(servoBase, theta1);  // Coxa angle
            setServoAngle(servoBase + 1, theta2);  // Femur angle
            setServoAngle(servoBase + 2, theta3);  // Tibia angle

            delay(stepDuration);
        }
    }
}

