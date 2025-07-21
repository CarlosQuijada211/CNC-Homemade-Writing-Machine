# CNC-Homemade-Writing-Machine
CNC Homemade writing machine made from cardboard and easily accesible materials, and driven by stepper motors, capable of rendering vector graphics using G-code-like instructions. 

## Project Overview
### Introduction
This is a custom-built CNC writing machine constructed primarily from cardboard and widely available electronic components. It operates using stepper motors and executes simplified, G-code-inspired instructions to reproduce vector-based line drawings. The design emphasizes affordability and accessibility, requiring no precision-manufactured parts or specialized fabrication tools.

### Motivation
This project emerged from a desire to better understand how mechanical, electrical, and software systems integrate in robotics. I set out to build a fully functional plotter from scratch, not only to explore CNC principles, but also to challenge myself with constrained materials and minimal budget. Along the way, I learned about motion control, instruction parsing, mechanical stability, and iterative design. The process sharpened my skills in debugging, creative problem-solving, and making engineering trade-offs under tight resource limits.

### Features
- Moves along two axes (X and Y)
- Pen-lift mechanism controlled by servo motor
- Executes a simplified vector instruction format inspired by G-code
- Controlled via Arduino Mega + G-code parser
- Powered by external 12V (stepper) and 5V (servo) supplies

### Constraints and Scope
- Not suitable for high-precision applications
- Limited drawing area
- Limited to simple, not very detailed drawings
- Paper must be manually positioned and taped down

These limitations are by design, reflecting the project's educational and proof-of-concept focus rather than production use.

## Materials and Tools
### Electronics

| Component           | Quantity | Specs / Notes                                 |
|---------------------|----------|-----------------------------------------------|
| Arduino Mega 2560   | 1        | Main controller                               |
| DRV8825 Stepper Driver| 2        | Controls X and Y stepper motors               |
| NEMA 17 Stepper     | 2        | 1/4 Microstepping, 12V                                |
| SG90 Servo Motor    | 1        | Controls pen lift                             |
| 12V Power Supply    | 1        | Minimum 3A recommended                        |
| 5V Regulator / PSU  | 1        | Powers servo independently                    |
| Breadboard          | 1        | For prototyping                   |
| Analog Joystick   | 1 | Custom movement and adjustment  |
| Jumper Wires        | —        | Male-male and male-female    |

### Software Tools
| Software | Purpose | Notes |
| - | - | - |
| Arduino IDE | Programming, compiling, and uploading firmware to the Arduino Mega | Version utilized: Arduino 1.8.18 |
| Inkscape | 	Creating and editing vector paths from images | Open-source vector graphics editor |
| J Tech Laser Tool | Inkscape extension for converting vector paths into G code. | Originally for laser cutters. Repurposed for this project |
| Python (custom scripts) | Post-process G-code into simplified instructions compatible with Arduino firmware | Custom-built for this project |

### Mechanical Structure

| Component                            |Quantity| Description |
|--------------------------------------|--|-------------|
| **Hard cardboard sheets** (3mm thick) |-| Used for the structural frame, base, and motor mounts. Lightweight and easy to cut. |
| **Threaded rods** (21 cm, 5 mm diameter)| 2 | Act as linear actuators; rotated by stepper motors to move nuts and drive the axis. |
| **Wooden rods** (20 cm, ~5 mm diameter)| 4 | Serve as linear guides for the moving base along each axis. |
| **Plastic drinking straws** (recycled, 2cm) | 4 | Sleeved over the wooden rods to reduce friction and help maintain alignment. Act as low-friction linear bushings. |
| **Nuts** (M5) | 6 | Coupled to the threaded rods to transform rotary motion into linear motion. Used to move the axis carriage. |
| **Ball bearings**| 2 | Support the ends of the threaded rods, allowing smooth and stable rotation. |
| **Attachable support wheel** | 1 | Provides vertical support to prevent sagging on one axis. |
| **Custom pen holder** | 1 | Built from the frame of an old drawing compass. Holds the pen securely and allows for easy replacement. |
| **Custom springloaded pen** | 1 | Has a retractable point that allows for smooth drawing in spite of surface imperfections or small height differences. |

### Tools Used
- Hot glue gun
- Super glue
- Rulers and calipers
- Computer (for programming Arduino and generating instructions)

## Mechanical Design
### Structure Overview

- **Purpose**: This machine is a 2D Cartesian plotter equipped with a simple pen-lift mechanism, designed to draw vector-based graphics onto flat surfaces such as paper.

- **Materials Used**: The frame and structural supports are made from hard cardboard, offering a lightweight and accessible foundation. Motion is enabled through two threaded rods acting as screw-driven linear actuators, each rotating to move a nut along its axis, allowing to move the carriages. Wooden rods serve as linear guides, while segments of recycled drinking straws are used as improvised bushings to reduce friction between the moving parts and the guides.

- **Design Philosophy**: The project prioritizes accessibility, low cost, and ease of construction using common or recycled materials. It is an educational tool, that can allow students to explore robotics and mechanical concepts without the need of specialized tools or expensive components. It is not aimed for industrial precision or as a product, but as a demonstration of core CNC principles and practice of the engineering mindset.

### Frame and Base
The frame of each axis is built from hard cardboard and is made up from two main pieces, protrayed in the layout below: 

