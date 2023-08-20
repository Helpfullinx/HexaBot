#include <Arduino.h>
#include <Vector3.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include "MainBot.h"

Vector3 v1;
Vector3 v2;
MainBot bot;

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

void vLerpTask( void* pvParameters) {
    while(true) {
        Vector3::lerp(v1, v2, 40, 5000);
    }
}

void vChangeLerpTarget( void* pvParameters ) {
    while(true) {
        v2 = Vector3(50.0, 20.0, 100.0);
        delay(5000);
        v2 = Vector3();
        delay(5000);
    }
}

void vPrint( void* pvParameters ) {
    while (true){
        Serial.printf("%f %f %f\n", v1.x, v1.y, v1.z);
    }
}

void setup() {
    Serial.begin(115200);
    while(!Serial);

    pwm1.begin(); // initialize i2c with first servo controller
    pwm1.setOscillatorFrequency(27000000);
    pwm1.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

    pwm2.begin(); // initialize i2c with the second servo controller
    pwm2.setOscillatorFrequency(27000000);
    pwm2.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

    delay(1000);

    pinMode(LED_BUILTIN, OUTPUT); // enable the onboard LED to digitalWrite to it

    TaskHandle_t Lerp;
    xTaskCreatePinnedToCore(vLerpTask,"Lerp",10000,NULL,1,&Lerp,0);

    TaskHandle_t ChangeLerpTarget;
    xTaskCreatePinnedToCore(vChangeLerpTarget, "Print", 10000, NULL, 0, &ChangeLerpTarget, 1);

    TaskHandle_t Print;
    xTaskCreatePinnedToCore(vPrint, "Print", 10000, NULL, 0, &Print, 1);
}


void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // turn the onboard LED on and wait one second
    delay(1000);
    Serial.printf("%f %f %f\n", v1.x, v1.y, v1.z);
    digitalWrite(LED_BUILTIN, LOW); // turn the onboard LED off and wait one second
    delay(1000);
    Serial.printf("%f %f %f\n", v1.x, v1.y, v1.z);
}