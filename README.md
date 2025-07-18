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
