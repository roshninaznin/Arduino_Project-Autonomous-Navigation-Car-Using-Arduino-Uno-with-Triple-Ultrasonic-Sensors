# Autonomous Navigation Car Using Arduino Uno with Triple Ultrasonic Sensors

 - ![Project Picture](Project%20Pictures%20And%20Video/Picture%20Side.jpeg)

## Overview
This project demonstrates the development of an autonomous navigation car that uses Arduino Uno and triple ultrasonic sensors for obstacle detection and avoidance. The system is designed to navigate dynamic environments efficiently and adaptively, making it suitable for applications like robotics, automation, and education.

## Features
- **Obstacle Detection**: Utilizes three ultrasonic sensors to detect obstacles in front, left, and right directions.
- **Real-Time Navigation**: Processes sensor data to adjust the car’s direction in real-time.
- **Simple Control System**: Uses an Arduino Uno and L298N motor driver to manage DC motors.
- **Cost-Effective**: Designed with readily available components for affordability.

## Components Used
- **Arduino Uno**: Acts as the microcontroller for processing sensor data and controlling motors.
- **Ultrasonic Sensors (3)**: Detect obstacles in front, left, and right directions.
- **DC Motors (2)**: Provide movement and are controlled via the motor driver.
- **L298N Motor Driver**: Interfaces between Arduino and DC motors for speed and direction control.
- **Breadboard and Wires**: For wiring and connections.

## Circuit Diagram
Include a detailed circuit diagram showcasing the connections between:
- Arduino Uno
- Ultrasonic sensors (front, left, and right)
- L298N motor driver
- DC motors
  - ![Circuit Design](Proteus%20Simulation/Circuit%20Diagram.png)

## How It Works
1. The three ultrasonic sensors continuously monitor for obstacles in front, left, and right directions.
2. The Arduino processes sensor data and determines if an obstacle is within the predefined range.
3. Based on the detection, the Arduino sends signals to the motor driver to adjust the car's movement (e.g., stop, turn left, turn right).
4. The car resumes its path after avoiding the obstacle.

## Installation and Setup
1. **Hardware Setup**:
   - Mount the Arduino Uno and L298N motor driver onto the car chassis.
   - Attach the ultrasonic sensors to the front, left, and right positions.
   - Connect the DC motors to the motor driver.
   - Complete the wiring as per the circuit diagram.

2. **Software Setup**:
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Connect the Arduino Uno to your computer using a USB cable.
   - Clone this repository to your local system.
   - Open the `obstacle.ino` file in the Arduino IDE.
   - Upload the code to your Arduino Uno.
   
3. **Powering the System**:
   - Use a suitable power source (e.g., a battery pack) to power the Arduino and motors.


## Testing and Results
1. Place the car in an environment with obstacles.
2. Observe the car's ability to detect and avoid obstacles in all directions.
3. Measure the response time and navigation accuracy.

## Performance and Limitations
### Performance:
- Successfully detects obstacles within a range of 15 cm.
- Responds to obstacles within 0.2 seconds.
- Effective in simple indoor environments.

### Limitations:
- Limited detection range (15 cm).
- Struggles with complex obstacles (e.g., narrow or reflective surfaces).
- Battery-dependent for prolonged operations.
- 
## Future Improvements
- Adding more ultrasonic sensors for 360° obstacle detection.
- Implementing advanced path-planning algorithms.
- Enhancing power efficiency for longer operations.
- Adding GPS for outdoor navigation.

## Contact

For more information, please contact:  

**Naznin Akter Roshmny** 
- Email: roshninaznin202@gmail.com
- Phone: 01956494298
