#ifndef AnaTechArm_h
#define AnaTechArm_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class AnaTechArm
{
  public:
    AnaTechArm();
    void begin();
    void dot();
    void dash();
    void pitch(int angle);
    void roll(int angle);
    void gripper(int angle);
    void elbow(int angle);
    void shoulder(int angle);
    void base(int angle);
    int Babaduk(int angle);
    int pitchV = 50;
    int rollV = 50;
    int gripperV = 0;
    int elbowV = 50;
    int shoulderV = 45;
    int baseV = 50;
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
};

#endif
