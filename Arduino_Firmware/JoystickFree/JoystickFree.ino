# include <Servo.h>

// Stepper pins
#define STEP_PIN1 5
#define DIR_PIN1 6

#define STEP_PIN2 7
#define DIR_PIN2 8

// Joystick pins
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_BTN A3

// Joystick button
bool lastButtonState = HIGH; // Botón no presionado (pullup)

// Servo motor
Servo Marker;
int MarkerAngle = 90;
int currentMarkerAngle = -1;
String serialInput = "";

// Timing
unsigned long lastServoMoveTime = 0;
const unsigned long servoMoveInterval = 500; // ms between servo movements

// Stepper config
int motorDelay = 10;  // microseconds
int threshold = 100;

// Direction flags
byte lastDirection1 = 0; // 0 = idle, 1 = right, 2 = left
byte lastDirection2 = 0; // 0 = idle, 1 = up, 2 = down

// Step counters
long motor1Steps = 0;
long motor2Steps = 0;

void setup() {
  // Stepper pins
  pinMode(STEP_PIN1, OUTPUT);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(ENABLE_PIN1, OUTPUT);

  pinMode(STEP_PIN2, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  pinMode(ENABLE_PIN2, OUTPUT);

  // Joysticks
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);
  pinMode(JOYSTICK_BTN, INPUT_PULLUP);

  // Servo
  Marker.attach(4);
  Marker.write(MarkerAngle);

  // Enable stepper drivers initially (keep enabled)
  digitalWrite(ENABLE_PIN1, LOW);
  digitalWrite(ENABLE_PIN2, LOW);

  Serial.begin(9600);
}

void loop() {
  int joyX = analogRead(JOYSTICK_X);
  int joyY = analogRead(JOYSTICK_Y);

  bool motor1Active = false;
  bool motor2Active = false;
  bool motor1DirPositive = true;
  bool motor2DirPositive = true;
  
  // Read serial input if available
  while (Serial.available() > 0) {
    char inChar = (char)Serial.read();
    if (inChar == '\n' || inChar == '\r') {
      if (serialInput.length() > 0) {
        int angle = serialInput.toInt();
        if (angle >= 0 && angle <= 180) {
          MarkerAngle = angle;
        }
        serialInput = "";  // Clear buffer after processing
      }
    } else {
      serialInput += inChar;
    }
  }


  // Update servo if angle changed
  if (MarkerAngle != currentMarkerAngle) {
    Marker.write(MarkerAngle);
    currentMarkerAngle = MarkerAngle;
  }

  
  // Motor 1
  if (joyX > 512 + threshold) {
    digitalWrite(DIR_PIN1, LOW);  // Inverted
    motor1DirPositive = true;
    motor1Active = true;
  } else if (joyX < 512 - threshold) {
    digitalWrite(DIR_PIN1, HIGH);
    motor1DirPositive = false;
    motor1Active = true;
  } else {
    motor1Active = false;
  }

  // Motor 2
  if (joyY > 512 + threshold) {
    digitalWrite(DIR_PIN2, HIGH);
    motor2DirPositive = true;
    motor2Active = true;
  } else if (joyY < 512 - threshold) {
    digitalWrite(DIR_PIN2, LOW);
    motor2DirPositive = false;
    motor2Active = true;
  } else {
    motor2Active = false;
  }

  // Step motors if active
  if (motor1Active || motor2Active) {
    if (motor1Active) digitalWrite(STEP_PIN1, HIGH);
    if (motor2Active) digitalWrite(STEP_PIN2, HIGH);
    delayMicroseconds(motorDelay);
    if (motor1Active) digitalWrite(STEP_PIN1, LOW);
    if (motor2Active) digitalWrite(STEP_PIN2, LOW);
    delayMicroseconds(motorDelay);

    if (motor1Active) motor1Steps += motor1DirPositive ? 1 : -1;
    if (motor2Active) motor2Steps += motor2DirPositive ? 1 : -1;
  }
  
  // Leer botón del joystick (presionar para imprimir estados)
  bool buttonState = digitalRead(JOYSTICK_BTN);
  
  // Detectar flanco de bajada (presionado)
  if (lastButtonState == HIGH && buttonState == LOW) {
    Serial.print("Motor 1 position: ");
    Serial.println(motor1Steps);
    Serial.print("Motor 2 position: ");
    Serial.println(motor2Steps);
    Serial.print("Servo angle: ");
    Serial.println(MarkerAngle);
  }
  
  lastButtonState = buttonState;
}
