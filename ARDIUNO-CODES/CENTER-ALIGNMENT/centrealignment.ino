#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angleToPulse(int ang){
  return map(ang, 0, 180, 150, 600);
}

// Change channel as needed
int channel = 0;  

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);

  pwm.setPWM(channel, 0, angleToPulse(90)); // CENTER
}

void loop() {}
