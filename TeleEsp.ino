// Pin Definitions
#define TRIG_FRONT 2
#define ECHO_FRONT 3
#define TRIG_LEFT 4
#define ECHO_LEFT 5
#define TRIG_RIGHT 6
#define ECHO_RIGHT 7
#define MOTOR_LEFT_FORWARD 8
#define MOTOR_LEFT_BACKWARD 9
#define MOTOR_RIGHT_FORWARD 10
#define MOTOR_RIGHT_BACKWARD 11

// Threshold Distance (in cm)
const int threshold = 15; // Minimum distance to consider a path clear

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up ultrasonic sensor pins
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);

  // Set up motor control pins
  pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);
}

void loop() {
  // Get distances from sensors
  long frontDistance = getDistance(TRIG_FRONT, ECHO_FRONT);
  long leftDistance = getDistance(TRIG_LEFT, ECHO_LEFT);
  long rightDistance = getDistance(TRIG_RIGHT, ECHO_RIGHT);

  // Print distances for debugging
  Serial.print("Front: ");
  Serial.print(frontDistance);
  Serial.print(" cm\tLeft: ");
  Serial.print(leftDistance);
  Serial.print(" cm\tRight: ");
  Serial.println(rightDistance);



  // Left-Hand Rule Logic
  if (leftDistance > threshold) {
    // Turn left
    turnLeft();
    delay(700); 
    moveForward();
    delay(600);// Adjust delay for smoother turn
  } else if (frontDistance > threshold) {
    // Move forward
    moveForward();
    delay(100);
  } else if (rightDistance > threshold) {
    // Turn right
    turnRight();
    delay(700);
    moveForward();
    delay(600); // Adjust delay for smoother turn
  } else {
    // Dead end, move backward
    moveBackward();
    delay(1250); // Adjust for desired backward movement
  }

  // Short delay for stable sensor readings
  delay(100);
}

// Function to measure distance using ultrasonic sensors
long getDistance(int trigPin, int echoPin) {
  // Send a 10-microsecond pulse to trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance (in cm)
  long distance = duration * 0.034 / 2; 
  return distance;
}

// Movement Functions
void moveForward() {
  digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}

void moveBackward() {
  digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, HIGH);
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT_FORWARD, LOW);
  digitalWrite(MOTOR_LEFT_BACKWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, HIGH);
}

void stopMotors() {
  digitalWrite(MOTOR_LEFT_FORWARD, LOW);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}
