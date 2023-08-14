#include <Arduino.h>
#include <Vector3.h>

Vector3 v1(1.0,1.0,1.0);
Vector3 v2(1.0,1.0,1.0);
Vector3 v3;

void setup() {
    Serial.begin(115200);
    while(!Serial.available());

    v3 = v1 + v2;
    Serial.printf("%f %f %f\n",v3.x,v3.y,v3.z);
    v3 = v1 - v2;
    Serial.printf("%f %f %f\n",v3.x,v3.y,v3.z);
    v3 = v1 / v2;
    Serial.printf("%f %f %f\n",v3.x,v3.y,v3.z);
    v3 = v1 * v2;
    Serial.printf("%f %f %f\n",v3.x,v3.y,v3.z);

}

void loop() {
}