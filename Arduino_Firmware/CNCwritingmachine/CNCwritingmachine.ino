#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h>

// Configuración de pines
#define STEP_PIN1 5
#define DIR_PIN1 6
#define STEP_PIN2 7
#define DIR_PIN2 8
#define SERVO_PIN 4

const float STEPS_PER_CM = 1592.0 * 4;
const float MAX_X_CM = 13.5;
const float MAX_Y_CM = 11.3;

// Crear los motores
AccelStepper motor1(AccelStepper::DRIVER, STEP_PIN1, DIR_PIN1);
AccelStepper motor2(AccelStepper::DRIVER, STEP_PIN2, DIR_PIN2);
MultiStepper steppers;

// Servo
Servo Marker;
int MarkerAngle = 0;

struct Instruction {
  long x_steps;
  long y_steps;
  bool markerDown;
};

const Instruction path[] PROGMEM = {

};
const int numInstructions = sizeof(path) / sizeof(path[0]);
int currentInstruction = 0;

void setup() {
  Serial.begin(9600);

  motor1.setPinsInverted(true, false, false);  // Invert X
  motor2.setPinsInverted(false, false, false); // Y normal  
  
  motor1.setMaxSpeed(3000);  // Or whatever speed you want
  motor2.setMaxSpeed(3000);
  
  steppers.addStepper(motor1);
  steppers.addStepper(motor2);

  // Inicializar servo
  Marker.attach(SERVO_PIN);
  Marker.write(MarkerAngle);

}

void loop() {
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
