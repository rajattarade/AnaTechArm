#include <Arduino.h>
#include <AnaTechArm.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

AnaTechArm::AnaTechArm(){}

void AnaTechArm::begin()
{
  pwm.begin();
  pwm.setPWMFreq(50);

  int ang = map(0, 0, 100, 600, 1800); //gripper
  pwm.writeMicroseconds(15, ang);
  ang = map(50, 0, 100, 2400, 1500); //elbow
  pwm.writeMicroseconds(12, ang);
  ang = map(45, 0, 100, 1300, 2400); //shoulder
  pwm.writeMicroseconds(11, ang);
  ang = map(50, 0, 100, 400, 2400); //pitch
  pwm.writeMicroseconds(14, ang);
  ang = map(50, 0, 100, 400, 2600); //roll
  pwm.writeMicroseconds(13, ang);
  ang = map(50, 0, 100, 400, 2800); //base
  pwm.writeMicroseconds(10, ang);
}

void AnaTechArm::pitch(int angle)
{
  while(pitchV < angle)
  {
  int ang = map(pitchV, 0, 100, 400, 2400);
  pwm.writeMicroseconds(14, ang);
  delay(10);
  pitchV++;
  }
  while(pitchV > angle)
  {
  int ang = map(pitchV, 0, 100, 400, 2400);
  pwm.writeMicroseconds(14, ang);
  delay(10);
  pitchV--;
  }
}


void AnaTechArm::base(int angle)
{
  while(baseV < angle)
  {
  int ang = map(baseV, 0, 100, 400, 2800);
  pwm.writeMicroseconds(10, ang);
  delay(50);
  baseV++;
  }
  while(baseV > angle)
  {
  int ang = map(baseV, 0, 100, 400, 2800);
  pwm.writeMicroseconds(10, ang);
  delay(50);
  baseV--;
  }
}




void AnaTechArm::shoulder(int angle)
{
  while(shoulderV < angle)
  {
  int ang = map(shoulderV, 0, 100, 1000, 2400);
  pwm.writeMicroseconds(11, ang);
  delay(50);
  shoulderV++;
  }
  while(shoulderV > angle)
  {
  int ang = map(shoulderV, 0, 100, 1000, 2400);
  pwm.writeMicroseconds(11, ang);
  delay(50);
  shoulderV--;
  }
}



void AnaTechArm::elbow(int angle)
{
  while(elbowV < angle)
  {
  int ang = map(elbowV, 0, 100, 2400, 1300);
  pwm.writeMicroseconds(12, ang);
  delay(50);
  elbowV++;
  }
  while(elbowV > angle)
  {
  int ang = map(elbowV, 0, 100, 2400, 1300);
  pwm.writeMicroseconds(12, ang);
  delay(50);
  elbowV--;
  }
}



void AnaTechArm::gripper(int angle)
{
  while(gripperV < angle)
  {
  int ang = map(gripperV, 0, 100, 600, 1800);
  pwm.writeMicroseconds(15, ang);
  delay(10);
  gripperV++;
  }
  while(gripperV > angle)
  {
  int ang = map(gripperV, 0, 100, 600, 1800);
  pwm.writeMicroseconds(15, ang);
  delay(10);
  gripperV--;
  }
  //int ang = map(angle, 0, 100, 600, 1800);
  //pwm.writeMicroseconds(15, ang);
}



void AnaTechArm::roll(int angle)
{
  while(rollV < angle)
  {
  int ang = map(rollV, 0, 100, 400, 2600);
  pwm.writeMicroseconds(13, ang);
  delay(25);
  rollV++;
  }
  while(rollV > angle)
  {
  int ang = map(rollV, 0, 100, 400, 2600);
  pwm.writeMicroseconds(13, ang);
  delay(25);
  rollV--;
  }
  //int ang = map(angle, 0, 100, 400, 2600);
  //pwm.writeMicroseconds(13, ang);
}

int AnaTechArm::Babaduk(int angle)
{
  return angle * 2;
}
