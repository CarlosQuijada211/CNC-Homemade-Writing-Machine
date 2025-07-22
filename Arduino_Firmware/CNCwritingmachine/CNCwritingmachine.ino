#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h>

// Pin Configuration
#define STEP_PIN1 5
#define DIR_PIN1 6
#define STEP_PIN2 7
#define DIR_PIN2 8
#define SERVO_PIN 4

// Set physical limits of the drawing area
const float STEPS_PER_CM = 1592.0 * 4; // Account for microstepping
const float MAX_X_CM = 13.5;
const float MAX_Y_CM = 11.3;

// Create Motors
AccelStepper motor1(AccelStepper::DRIVER, STEP_PIN1, DIR_PIN1);
AccelStepper motor2(AccelStepper::DRIVER, STEP_PIN2, DIR_PIN2);
MultiStepper steppers;

// Servo
Servo Marker;
int MarkerAngle = 0;

// Instruction Format
struct Instruction {
  long x_steps;
  long y_steps;
  bool markerDown;
};

// Instructions Array.
const Instruction path[] PROGMEM = {
  // Insert Instructions of the desired drawing
};

const int numInstructions = sizeof(path) / sizeof(path[0]);
int currentInstruction = 0;

void setup() {
  Serial.begin(9600);

  motor1.setPinsInverted(true, false, false);
  motor2.setPinsInverted(false, false, false);
  
  motor1.setMaxSpeed(3000);
  motor2.setMaxSpeed(3000);
  
  steppers.addStepper(motor1);
  steppers.addStepper(motor2);

  // Initialize Servomotor
  Marker.attach(SERVO_PIN);
  Marker.write(MarkerAngle);

}

void loop() {
  // Follow Instructions
  if (currentInstruction < numInstructions) {
    Instruction inst;
    memcpy_P(&inst, &path[currentInstruction], sizeof(Instruction));

    if (inst.markerDown) {
      Marker.write(180);
    } else {
      Marker.write(0);
    }

    long positions[2] = { inst.x_steps, inst.y_steps };
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();

    currentInstruction++;
  }
}
