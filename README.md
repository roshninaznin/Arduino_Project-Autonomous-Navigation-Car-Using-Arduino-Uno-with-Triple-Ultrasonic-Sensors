# Autonomous Navigation Car Using Arduino Uno with Triple Ultrasonic Sensors

## Overview
This project demonstrates the development of an autonomous navigation car that uses Arduino Uno and triple ultrasonic sensors for obstacle detection and avoidance. The system is designed to navigate dynamic environments efficiently and adaptively, making it suitable for applications like robotics, automation, and education.

## Features
- **Obstacle Detection**: Utilizes three ultrasonic sensors to detect obstacles in front, left, and right directions.
- **Real-Time Navigation**: Processes sensor data to adjust the car’s direction in real-time.
- **Simple Control System**: Uses an Arduino Uno and L298N motor driver to manage DC motors.
- **Cost-Effective**: Designed with readily available components for affordability.

## Components Required
| Component            | Quantity | Description                          |
|----------------------|----------|--------------------------------------|
| Arduino Uno          | 1        | Microcontroller for processing data |
| Ultrasonic Sensors   | 3        | For obstacle detection              |
| L298N Motor Driver   | 1        | To control the DC motors            |
| DC Motors            | 2        | For vehicle propulsion              |
| Chassis              | 1        | Base structure for the car          |
| Breadboard & Wires   | -        | For connections                     |
| Power Source         | 1        | Battery or external power supply    |

## Circuit Diagram
Include a detailed circuit diagram showcasing the connections between:
- Arduino Uno
- Ultrasonic sensors (front, left, and right)
- L298N motor driver
- DC motors

## Installation and Setup
1. **Hardware Assembly**:
   - Mount the Arduino Uno and L298N motor driver onto the car chassis.
   - Attach the ultrasonic sensors to the front, left, and right positions.
   - Connect the DC motors to the motor driver.
   - Complete the wiring as per the circuit diagram.

2. **Software Setup**:
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Connect the Arduino Uno to your computer using a USB cable.
   - Upload the provided code to the Arduino Uno.

## Arduino Code
```cpp
#include <NewPing.h>

// Define pins for ultrasonic sensors
#define TRIG_FRONT 2
#define ECHO_FRONT 3
#define TRIG_LEFT 4
#define ECHO_LEFT 5
#define TRIG_RIGHT 6
#define ECHO_RIGHT 7

// Motor driver pins
#define ENA 9
#define ENB 10
#define IN1 8
#define IN2 11
#define IN3 12
#define IN4 13

// Sensor range
#define MAX_DISTANCE 200

NewPing sonarFront(TRIG_FRONT, ECHO_FRONT, MAX_DISTANCE);
NewPing sonarLeft(TRIG_LEFT, ECHO_LEFT, MAX_DISTANCE);
NewPing sonarRight(TRIG_RIGHT, ECHO_RIGHT, MAX_DISTANCE);

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distanceFront = sonarFront.ping_cm();
  int distanceLeft = sonarLeft.ping_cm();
  int distanceRight = sonarRight.ping_cm();

  if (distanceFront > 0 && distanceFront < 20) {
    stopCar();
    if (distanceLeft > distanceRight) {
      turnLeft();
    } else {
      turnRight();
    }
  } else {
    moveForward();
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
}
```

## Testing and Results
1. Place the car in an environment with obstacles.
2. Observe the car's ability to detect and avoid obstacles in all directions.
3. Measure the response time and navigation accuracy.

## Future Improvements
- Integration of additional sensors for enhanced obstacle detection.
- Implementation of advanced algorithms for smoother navigation.
- Addition of GPS for location-based navigation.

## Contribution
Feel free to contribute to this project by improving the code or suggesting new features. Create a pull request with your changes.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.
