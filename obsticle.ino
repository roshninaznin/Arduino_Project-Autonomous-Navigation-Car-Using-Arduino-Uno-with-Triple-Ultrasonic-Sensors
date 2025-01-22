// Pin definitions
#define TRIG_FRONT 8
#define ECHO_FRONT 9
#define TRIG_LEFT 10
#define ECHO_LEFT 11
#define TRIG_RIGHT 6
#define ECHO_RIGHT 7


#define MOTOR_A_IN1 5
#define MOTOR_A_IN2 4
#define MOTOR_B_IN3 3
#define MOTOR_B_IN4 2


// Function to calculate distance
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; 
}


// Movement functions
void moveForward() {
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}






void moveBackward() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}


void turnLeft() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}


void turnRight() {
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}


void stopCar() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
}



void setup() {
  // Ultrasonic sensor pins
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);




  // Motor driver pins
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  long distanceFront = getDistance(TRIG_FRONT, ECHO_FRONT);
  long distanceLeft = getDistance(TRIG_LEFT, ECHO_LEFT);
  long distanceRight = getDistance(TRIG_RIGHT, ECHO_RIGHT);


  Serial.print("Front: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Left: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Right: ");
  Serial.print(distanceRight);
  Serial.println(" cm");


  if (distanceFront < 15) { 
    stopCar();
    if (distanceLeft > distanceRight) {
      turnLeft();
      delay(500); 
    } else {
      turnRight();
      delay(500); 
    }
  } else {
    moveForward(); 
  }

  delay(100); 
}
