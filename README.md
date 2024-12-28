
# Maze Solver Robot

## Overview
The Maze Solver Robot is an innovative autonomous vehicle designed to navigate and solve complex mazes. Equipped with sensors and intelligent algorithms, the robot ensures precise navigation, maintains an optimal distance from walls, and identifies the shortest path to the exit. This project combines advanced robotics, sensor integration, and algorithmic programming to create a reliable solution for real-world maze-solving challenges.

---

## Features
1. **Autonomous Navigation**
   - Solves mazes without human intervention using algorithm Wall-Following.

2. **Wall Distance Control**
   - Uses ultrasonic sensors to maintain a safe distance from maze walls, ensuring smooth navigation.

3. **Real-Time Decision Making**
   - Processes sensor data in real time to decide the robot's next move.

4. **Modular Design**
   - Easy to modify and extend for additional functionalities, such as speed optimization or obstacle avoidance.

---

## Hardware Components
1. **Microcontroller**: Arduino Uno 
2. **Motors**: 4 DC motors with motor driver
3. **Ultrasonic Sensors**: For measuring distances from walls
4. **Wheels**: 4 driving wheels 
5. **Power Source**: Rechargeable battery

---

## Software Components
1. **Programming Language**: C++

2. **Algorithms**:
   - Wall-Following Algorithm
   - PID Control for distance maintenance

---

## How It Works
1. **Initialization**:
   - The robot initializes all sensors and sets a target distance for wall-following.
   
2. **Maze Solving**:
   - It uses the wall following or left biased algorithm to solve the maze.

3. **Wall Distance Maintenance**:
   - Ultrasonic sensors detect distances to the left and right walls.

4. **Real-Time Adjustments**:
   - The robot dynamically adjusts its path to avoid collisions and maximize efficiency.

---

## Setup Instructions
1. Assemble the robot with the specified hardware components.
2. Install the required software dependencies on your microcontroller.
3. Upload the maze-solving code to the microcontroller.
4. Place the robot at the starting point of a maze and power it on.

---

## Applications
- Educational tool for robotics and programming.
- Demonstration of autonomous navigation systems.
- Use in competitions or exhibitions to showcase technical capabilities.

---

## Future Enhancements
1. **Integration with Computer Vision**
   - Use cameras to identify maze markings or dynamic obstacles.

2. **Enhanced Algorithms**
   - Implement more advanced algorithms like flood filter for faster maze solving.

3. **Wireless Control**
   - Add Wi-Fi or Bluetooth for remote monitoring and control.

4. **Improved Hardware**
   - Replace ultrasonic sensors with LiDAR for more accurate wall detection.

---

## Contributors
- **Yash Wathrey**
- Aman Kushwaha, Amit Kanojia , Anuj Sahu

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Acknowledgments
- Hrishant Prajapati
- CreateShala Learning Solution

---

Thank you for your interest in the Maze Solver Robot. For any questions or contributions, feel free to reach out!

