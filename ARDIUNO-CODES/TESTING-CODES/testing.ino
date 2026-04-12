#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angleToPulse(int ang){
  return map(ang, 0, 180, 150, 600);
}

// CHANGE THIS for each motor
int testChannel = 0;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);
}

void loop() {

  pwm.setPWM(testChannel, 0, angleToPulse(70));
  delay(2000);

  pwm.setPWM(testChannel, 0, angleToPulse(90));
  delay(2000);

  pwm.setPWM(testChannel, 0, angleToPulse(110));
  delay(2000);
}
