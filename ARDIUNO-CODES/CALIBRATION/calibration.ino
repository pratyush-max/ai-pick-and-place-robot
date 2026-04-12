#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angleToPulse(int ang){
  return map(ang, 0, 180, 150, 600);
}

int channel = 0;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);
}

void loop() {

  // Min position
  pwm.setPWM(channel, 0, angleToPulse(60));
  delay(2000);

  // Center
  pwm.setPWM(channel, 0, angleToPulse(90));
  delay(2000);

  // Max position
  pwm.setPWM(channel, 0, angleToPulse(120));
  delay(2000);
}
