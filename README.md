# Ackermann Lab

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B)](https://github.com/Brighht/ackermann-lab-)
[![Build](https://img.shields.io/badge/build-CMake-064F8C?logo=cmake)](https://github.com/Brighht/ackermann-lab-/blob/main/CMakeLists.txt)
![Status](https://img.shields.io/badge/status-in%20development-orange)

A hands-on autonomous vehicle project built around a **standard Ackermann-steering chassis, Raspberry Pi 5, Arduino Uno, and C++**.

The goal is to build the control stack in small, testable layers: represent a requested vehicle motion, constrain it to allowed values, serialize it as a line of text, then connect that software to the Raspberry Pi, Arduino, steering servo, motor controller, and sensors.

> **Current status:** the desktop C++ command path now validates, serializes, and checks one example. Raspberry Pi–Arduino communication and physical vehicle control are planned next.

## Why this project exists

Rather than treating the Raspberry Pi and Arduino as a collection of disconnected experiments, this project is structured as a small robotics system:

```text
High-level logic
      │
      ▼
VehicleCommand
      │
      ▼
Validation / safety limits
      │
      ▼
Command serialization
      │
      ▼
Raspberry Pi 5
      │  serial communication
      ▼
Arduino Uno
      │
      ├── steering servo
      ├── motor controller
      └── sensors
```

The Raspberry Pi is intended to handle higher-level computation while the Arduino handles low-level hardware I/O and control.

## What works today

The repository currently contains a working C++17/CMake project with:

- a `VehicleCommand` data structure for speed and steering requests;
- command validation using `std::clamp`;
- speed limited to `[-1.0, 1.0]`;
- steering angle limited to `[-25°, 25°]`;
- `serializeCommand`, which formats a command as `CMD,<speed>,<steeringAngle>` followed by a newline;
- an executable that validates a sample, serializes the safe command, and prints `PASS` when the string matches the expected line.

For example, the current test command requests:

```text
speed = -2.5
steeringAngle = 32.5°
```

and the validation layer constrains it to:

```text
speed = -1.0
steeringAngle = 25.0°
```

The safe example is encoded as `CMD,-1,25\n`. `CMD` identifies the message, commas separate the fields, and the newline terminates the line. The string is generated locally; it is not yet sent to the Arduino.

Validation is a separate step so later code can request a motion without being responsible for enforcing the vehicle's allowed command range.

## Repository structure

```text
ackermann-lab-/
├── CMakeLists.txt
├── include/
│   └── vehicle_command.hpp
└── src/
    ├── main.cpp
    └── vehicle_command.cpp
```

### Key files

- [`include/vehicle_command.hpp`](https://github.com/Brighht/ackermann-lab-/blob/main/include/vehicle_command.hpp) — defines the command data passed through the control stack.
- [`src/vehicle_command.cpp`](https://github.com/Brighht/ackermann-lab-/blob/main/src/vehicle_command.cpp) — applies speed and steering limits and formats the command as text.
- [`src/main.cpp`](https://github.com/Brighht/ackermann-lab-/blob/main/src/main.cpp) — runs the validation → serialization example and checks the expected string.
- [`CMakeLists.txt`](https://github.com/Brighht/ackermann-lab-/blob/main/CMakeLists.txt) — builds the project as C++17.

## Build and run

Requirements:

- C++17-compatible compiler
- CMake 3.16+

```bash
git clone https://github.com/Brighht/ackermann-lab-.git
cd ackermann-lab-

cmake -S . -B build
cmake --build build
./build/ackermann_lab
```

Expected output from the current example:

```text
Validated speed: -1
Validated steeringAngle: 25
CMD,-1,25

PASS
```

The extra blank line comes from printing a string that already ends with a newline using `std::endl`. `PASS` checks this one example, including the terminator; it is not a full test suite.

## Development roadmap

| Stage | Goal | Status |
|---|---|---|
| 1 | C++ project + CMake foundation | ✅ Complete |
| 2 | Vehicle command representation and validation | ✅ Complete for current limits |
| 3 | Format newline-terminated command and check example output | ✅ Complete locally |
| 4 | Establish Raspberry Pi ↔ Arduino serial link | ⏳ Next |
| 5 | Steering and motor hardware interfaces | ⏳ Planned |
| 6 | Sensor acquisition and feedback | ⏳ Planned |
| 7 | Closed-loop vehicle experiments | ⏳ Planned |
| 8 | Higher-level navigation | ⏳ Planned |

The roadmap reflects intended work, not completed functionality. Completed features will be documented here as they are implemented and tested.

## Engineering decisions so far

**Why validate commands separately?**  
The requested motion and the motion the hardware is allowed to receive are different concepts. Keeping validation in its own function creates a clear safety boundary and makes the behavior easy to test.

**Why Raspberry Pi + Arduino?**  
The planned split gives the Raspberry Pi room for higher-level robotics software while the Arduino can focus on deterministic hardware-facing tasks such as actuator commands and sensor reads.

**Why CMake?**  
The project is expected to grow beyond a single source file. CMake provides a repeatable build structure as communication, hardware, and testing modules are added.

## Hardware

- Raspberry Pi 5
- Arduino Uno
- Ackermann-steering chassis
- Steering and drive hardware

Additional sensors and electronics will be documented when they are actually integrated.

## Current learning focus

This project is being developed incrementally to build practical understanding of:

- modern C++ project organization;
- interfaces between software modules;
- validation and safety boundaries;
- serial communication;
- embedded control;
- sensor integration;
- vehicle kinematics and autonomous navigation.

---

**Project repository:** [github.com/Brighht/ackermann-lab-](https://github.com/Brighht/ackermann-lab-)
