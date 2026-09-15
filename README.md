# Ackermann Lab

A C++ autonomous-vehicle project using an Ackermann-steering chassis,
Raspberry Pi 5, and Arduino Uno.

## Planned Architecture

Laptop development → Raspberry Pi 5 → Arduino Uno → steering and motor hardware

## Current Progress

- Created the C++ project structure
- Configured the project using CMake
- Built and ran the first executable successfully

## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
./ackermann_lab