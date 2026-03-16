#include <Servo.h>

Servo baseServo;      // Base rotation
Servo shoulderServo;  // Shoulder joint
Servo elbowServo;     // Elbow joint
Servo gripperServo;   // Gripper open/close

char command;

void setup() {

  Serial.begin(9600);

  baseServo.attach(3);
  shoulderServo.attach(5);
  elbowServo.attach(6);
  gripperServo.attach(9);

  // Initial Position
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  gripperServo.write(70);

}

void loop() {

  if (Serial.available() > 0) {

    command = Serial.read();

    // Command A → Pick Object
    if (command == 'A') {

      baseServo.write(90);
      delay(500);

      shoulderServo.write(60);
      delay(500);

      elbowServo.write(120);
      delay(500);

      gripperServo.write(20); // close gripper
      delay(1000);

    }

    // Command B → Lift Object
    if (command == 'B') {

      shoulderServo.write(30);
      delay(500);

    }

    // Command C → Rotate Arm
    if (command == 'C') {

      baseServo.write(0);
      delay(1000);

    }

    // Command D → Release Object
    if (command == 'D') {

      gripperServo.write(70); // open gripper
      delay(1000);

    }

    // Command R → Reset Position
    if (command == 'R') {

      baseServo.write(90);
      shoulderServo.write(90);
      elbowServo.write(90);
      gripperServo.write(70);

    }

  }

}
