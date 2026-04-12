#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angleToPulse(int ang){
  return map(ang, 0, 180, 150, 600);
}

// Channels
int base = 0;
int shoulder = 1;
int gripper = 2;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);
}

void loop() {

  // Position 1
  pwm.setPWM(base, 0, angleToPulse(40));
  pwm.setPWM(shoulder, 0, angleToPulse(90));
  pwm.setPWM(gripper, 0, angleToPulse(20));
  delay(2000);

  // Position 2
  pwm.setPWM(base, 0, angleToPulse(120));
  pwm.setPWM(shoulder, 0, angleToPulse(120));
  pwm.setPWM(gripper, 0, angleToPulse(80));
  delay(2000);
}
