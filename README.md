# CNC-Homemade-Writing-Machine
CNC Homemade writing machine made from cardboard and easily accesible materials, and driven by stepper motors, capable of rendering vector graphics using G-code-like instructions. 

## Project Overview

### Introduction  
This CNC-style writing machine was built from scratch using simple, affordable materials—primarily cardboard, wooden rods, and widely available electronic components. Driven by stepper motors and powered by an Arduino Mega, the system interprets simplified, G-code-like instructions to produce vector-based line drawings. The entire build emphasizes accessibility over precision, avoiding specialized tools or factory-made parts.

### Motivation  
What began as a casual experiment with an Arduino board gradually evolved into a complete working machine. With no access to advanced tools or expensive components, the challenge became not just to build a CNC-like system, but to make it function using only what was on hand. The goal was never to create a replicable blueprint; it was about exploration, improvisation, and seeing how far careful iteration and creative problem-solving could take a simple idea. In the process, I learned a great deal about mechanical systems, instruction parsing, motion control, and the trade-offs involved when working within strict constraints.

### Features  
- Two-axis (X/Y) motion using threaded rods and stepper motors  
- Servo-controlled pen lift mechanism  
- Executes custom vector instructions inspired by G-code  
- Arduino Mega-based control system with a basic instruction parser  
- Powered by external 12V and 5V supplies  

### Constraints and Scope  
- Limited precision and drawing detail  
- Small drawing area (approx. 11.3 cm x 13.5 cm)  
- Manual paper alignment and tape-based mounting  
- Not designed for reproducibility or mass production  

## Materials and Tools
### Electronics

| Component           | Quantity | Specs / Notes                                 |
|---------------------|----------|-----------------------------------------------|
| Arduino Mega 2560   | 1        | Main controller                               |
| DRV8825 Stepper Driver| 2        | Controls X and Y stepper motors               |
| NEMA 17 Stepper     | 2        | 1/4 Microstepping, 12V                                |
| SG90 Servo Motor    | 1        | Controls pen lift                             |
| 12V Power Supply    | 1        | Minimum 3A recommended                        |
| 5V Power Supply  | 1        | Powers servo independently                    |
| Breadboard          | 1        | Circuit Assembly                  |
| Analog Joystick   | 1 | Custom movement and adjustment  |
| Barrel Jack Adaptor | 2 | Connect circuit and external power sources |
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

Each axis of the machine is built using a custom frame made from hard cardboard. The basic structure consists of two main pieces: a flat **base** and upright **wall pieces**, as shown in the layout diagram below:

<br>
<p align="center">
  <img src="/Assets/frame_layout.png" alt="Frame Layout" width="70%">
</p>
<br>

There are two identical-looking frames in total — one for each axis (X and Y) — but they differ slightly in function and construction. The **wall pieces** are glued onto the base to form the vertical supports. Each wall is made from two layers of cardboard for added strength and contains three holes: one for a threaded rod and two for wooden guide rods that support the moving carriage.

The **bottom frame** (Y-axis) serves as the foundation. Its base is made from three stacked cardboard layers to increase weight and stability. The **second frame** (X-axis) is mounted on top of the Y-axis carriage. Its base only uses a single layer of cardboard to keep it lightweight, since it needs to move smoothly along the Y-axis.

On the carriage of the top frame, the servo motor and pen holder are mounted to perform the drawing operation. At the opposite end of this frame, a small **support wheel** is attached. This helps maintain balance and allows the frame to roll along the lower axis without tilting or dragging.

These dimensions allow for a 11.3cm x 13.5cm drawing area. 

### Motion System and Moving Carriages

Motion in both axes is achieved through a screw-driven linear actuator system. Each axis consists of a 21 cm threaded rod that passes through the central holes in the frame walls. When the rod is rotated by a motor, nuts screwed onto it translate along the rod, converting rotational motion into linear motion.

Each motor is mounted onto its corresponding frame and secured in place with glue. When the upper frame is installed on top of the lower one, its motor rests directly on the lower frame's moving carriage, allowing it to move along with the bottom axis. To couple the motor shaft to the threaded rod, a simple improvised coupler was constructed using a small plastic straw. One end of the straw is glued to the motor shaft, while the other end is press-fitted and taped onto the threaded rod. While not ideal for transmitting high torque, this lightweight and low-cost solution was effective for the relatively low mechanical demands of the system. On the opposite end of the rod, a ball bearing is mounted in the frame to support the shaft and allow free, low-friction rotation.

Each moving carriage is constructed from a rectangular piece of cardboard (dimensions vary by axis, as shown in the frame diagram). Three evenly spaced nuts are glued in a straight line along the center of the carriage. These nuts engage with the threaded rod and serve as the primary actuation mechanism, ensuring stable linear motion with minimal backlash.

For guidance and stability, each axis is flanked by two wooden rods parallel to the threaded rod. These serve as linear guides. To reduce friction between the carriage and the guides, small segments of drinking straws are fixed to the carriage ends. These straw sleeves slide along the wooden rods, acting as low-friction bushings. This makeshift bearing system is both lightweight and easy to implement with recycled materials, and it provides sufficient accuracy for drawing applications.

The lower frame features a larger carriage to support the upper-axis assembly. The upper frame’s carriage is smaller and carries only the pen-lift mechanism. This nested design allows one axis to ride atop the other, forming a compact and efficient Cartesian system.

### Actuator and Pen Mechanism
A custom-built spring-loaded pen is used to account for slight height variations and surface irregularities caused by material imperfections and hand-assembled components. The pen mechanism includes a spring mounted at the rear of the ink tube, which continuously pushes the writing tip forward. This allows the tip to remain in contact with the drawing surface but also retract slightly if the surface is uneven, preventing excessive pressure or skipping.

To control whether the pen draws or not, a string is tied around the ink tube and routed through a hole in the pen’s plastic casing. This string connects to a servo motor mounted on the frame. When the servo rotates, it pulls on the string, retracting the pen tip into its housing and lifting it off the surface. When released, the spring extends the tip again, allowing the machine to resume drawing.

<br>
<p align="center">
  <img src="/Assets/custom_pen.png" alt="Custom Pen" width="80%">
</p>
<br>

## Electronics and Wiring
### Electrical System Overview

The electronic control system is centered around an Arduino Mega, which controls motion by controlling two NEMA 17 stepper motors and one SG90 servo motor. Each stepper motor is driven by a DRV8825 stepper driver, which receives step and direction signals from the Arduino. Each stepper motor is configured to 1/4 microstepping. The drivers are powered by a 12V external power supply connected via a barrel jack. The SG90 servo motor, responsible for lifting and lowering the pen, is powered separately through a dedicated 5V power source, also connected via a barrel jack. Finally, a joystick module is also connected to the Arduino, enabling manual control of the stepper motors. This feature is useful for calibration, alignment, and testing purposes.

### Main Components and Their Roles
|Component|Purpose|
|-|-|
|Arduino Mega|main controller, runs firmware and sends control signals to drivers and servo |
|NEMA 17 Stepper Motors (x2) | Drive X and Y axes via threaded rods |
|DRV8825 Drivers (x2) | Interface between Arduino and stepper motors |
|SG90 Servo Motor | Raises and lowers pen via string mechanism |
|Analog Joystick | Allows manual control of stepper motors |
|12V Power Supply | Powers NEMA17 Stepper motors |
|5V Power Supply | Powers SG90 servomotor |
|Barrel Jack Adaptor (x2) | Connects circuit and external power supply |
|100uF capacitors (x2) | Handle voltage spikes and noise |
| Jumper Wires | Male-male and male-female for connecting electronic components |
|Breadboard | Allows circuit assembly |

### Wiring Diagram
<br>
<p align="center">
  <img src="/Assets/circuit_layout.png" alt="Custom Pen" width="80%">
</p>
<br>

## Software and Logic
### Overview
To convert an external image into drawing instructions for the machine, the input must pass through a structured software pipeline. The process begins in **Inkscape**, where the image is converted into a vector path, and then into **G-code** using the **J Tech Laser Tool extension**. This **G-code** is not directly compatible with the Arduino, so it is parsed and translated into a simplified, custom instruction format by a Python script.

The central script, `interface.py`, provides a graphical interface that guides the user through this process. It asks for the name of the **G-code** file, handles translation via helper scripts, and offers an optional preview of the final drawing. It also splits the output into organized `.txt` files, each containing up to **2500** instructions to respect Arduino's memory constraints.

Finally, these processed instructions are inserted into the Arduino’s firmware, specifically the `CNCWritingMachine.ino` file, where they are executed to control the stepper motors and pen mechanism.

### Firmware Files (Arduino Code)
#### `JoystickFree.ino` **– Manual Control Mode**
This Arduino sketch enables manual control of the CNC machine using a joystick and serial input. It is mainly used for testing, calibration, and positioning before running automatic drawing routines.

**Main Features**
- **Joystick movement:** Controls two stepper motors (X and Y axes) in real time.
- **Serial input:** Allows setting the servo angle (0–180°) to raise or lower the pen.
- **Joystick button:** Prints current motor step counts and servo angle for calibration/debugging.
- Used as a setup tool—not for drawing—this file provides hands-on control of the machine’s axes and pen.

#### `CNCWritingMachine.ino` – Main Drawing Controller
This is the core program that executes drawing instructions on the CNC writing machine. It reads a predefined array of movement and pen commands and moves the motors and servo accordingly.

**Key Components**
- **Stepper Motors:** Controlled using `AccelStepper` and `MultiStepper` for synchronized X and Y axis motion.
- **Servo:** Moves the pen up (0°) or down (180°) based on the current instruction.
- **Instruction Array** (`path[]`):
The most critical element of this file. It holds all the drawing commands in flash memory (PROGMEM) to save RAM. Each Instruction contains:
  - `x_steps`: target position on the X axis (in steps)
  - `y_steps`: target position on the Y axis (in steps)
  - `markerDown`: whether the pen should be down (true) or up (false)
  The array is filled externally by the user via the Python interface, and instructions are executed one-by-one inside the `loop()`.

**Execution Flow**
1. Load the next instruction from `path[]`.
2. Move both motors to the target position.
3. Raise or lower the pen accordingly.
4. Repeat until all instructions are completed.

This file must be updated with a new path[] array every time a new drawing is uploaded

### Python Processing Scripts
#### `interface.py` – User Interface for Instruction Generation
This file provides a simple graphical interface (built with `tkinter`) that allows users to process G-code files and generate instructions for the CNC writing machine.

**Purpose**
- It serves as the main user entry point to the software stack. From here, users can:
- Specify the name of a G-code file.
- Choose to preview the drawing using Turtle graphics.
- Choose to generate `.txt` instruction files for the Arduino sketch.

**Key Features**
- **Two Main Options:**
  - **Show preview:** Visualizes the drawing.
  - **Generate instruction files:** Creates Arduino-friendly text files split into 2500-instruction chunks.
- **Filename Validation:** Uses `check_filename()` from gcode.py to verify the G-code file exists.
- **Centralized Processing:** Delegates actual logic to `generate_file()` and `generate_preview()` functions.

**Flow Summary**
- User inputs the G-code filename.
- Selects one or both checkboxes.
- Upon clicking "Generate":
  - The program validates input.
  - Based on selection, it either previews, generates instruction files, or both.

**Dependencies**
- `gcode.py`: for core processing logic.
 -`preview.py`: indirectly used for rendering the drawing.

#### `gcode.py` – G-code Parsing and Instruction Generation
This file handles the conversion of G-code files into simplified, Arduino-ready instructions and visual previews. It provides the core logic behind both file generation and drawing preview functionality.

**Function Overview:**
- `gcode_to_instructions(gcode_lines)`
  - **Purpose:** Parses a list of G-code lines and converts them into a list of tuples: (x, y, pen_down).
  - **Details:**
    - Extracts X and Y coordinates from G0 or G1 commands.
    - Interprets M03 as pen down and M05 as pen up.
    - Output: list of (x, y, bool) tuples in integer format.

- `to_arduino_code(instructions)`
  - **Purpose:** Converts coordinate instructions into Arduino-ready format.
  - **Details:**
    - Scales the (x, y) positions from mm to internal motor steps using a constant (*6368/10).
    - Formats each line as: `{x, y, true/false},`

- `generate_file(file)`
  - **Purpose:** Reads a G-code file and writes Arduino instruction text files to disk.
  - **Details:**
   - Loads .gcode file and parses it into instructions.
   - If instructions ≤ 2500 → writes a single `.txt` file.
   - If >2500:
     - Splits into chunks of ≤2500 lines.
     - Adds transitional instructions to ensure pen-up between chunks.
     - Saves each chunk as a numbered file in a subfolder (Instructions/filename/).

- `generate_preview(file)`
  - **Purpose:** Displays a visual preview of the parsed instructions using Turtle graphics.
  - **Details:**
    - Reads and parses the .gcode file.
    - Calls draw() from preview.py to render the result.

- `check_filename(file)`
  - **Purpose:** Checks if the given .gcode file exists in the Gcode/ folder.
  - **Returns:** True if it exists, False otherwise.

This file is the processing core of the project. Everything that turns user input into machine-ready or human-readable output happens here.

#### `preview.py` – Path Visualization Tool
This file uses Python’s Turtle graphics to display a visual preview of the drawing path based on parsed instructions.

- `draw(instructions)`
  - **Purpose:** Visually renders the movement path of the drawing machine.
  - **Details:**
    - Sets up a Turtle canvas scaled to match the machine’s drawing area.
    - Draws the machine boundary box.
    - Iterates over the list of (x, y, pen_down) instructions.
    - Moves the turtle without drawing if pen_down is False.
    - Draws lines if pen_down is True.
   
### Third-Party Software – Inkscape (v0.92)
To generate G-code for the CNC writing machine, I use Inkscape version 0.92, the latest release compatible with the J Tech Laser Tool extension.

**Workflow:**
  - I begin by setting the document size to 135 mm × 113 mm, matching the machine’s physical drawing area.
  - An image is imported and converted into a bitmap.
  - The bitmap is vectorized, and I intentionally flatten Bézier curves with a flatness value of 0.1, increasing the number of nodes to maximize positional accuracy.
  - The resulting vector paths are then exported to G-code using the J Tech Laser Tool extension, ready for processing by the instruction generator.


## Challenges and Engineering Decision
### Problems Faced and Solutions

#### **Transition from Version 1 to Version 2**
The first attempt at this project barely "worked," but it served as a proof of concept: the core idea (using a screw-driven linear actuator) was sound, even if the implementation wasn’t. At the time, I didn’t know the technical term for it, but this first version validated that concept.

It was built using two wooden pieces arranged in an L-shape to provide structure. A long threaded rod passed through this frame, connected to a motor with tape on one end and fixed to a ball bearing on the other. A thick metal rod ran parallel to the threaded rod to act as a rail, and the carriage was a wooden piece with nuts glued in a straight line down the middle, sliding along the rail with the help of a plastic guide.

This version had multiple flaws: it was too large, fragile, prone to vibration, and poorly aligned. However, it laid the groundwork for a more refined design. The second version was scaled down and built with hard cardboard, much easier to cut precisely by hand. It also featured two wooden guide rods for better stability and smoother movement. This second version ultimately evolved into the final machine.

#### **Vibration**
Vibration was one of the most persistent challenges throughout development. The second version significantly reduced this issue by adding more structural support and reducing friction. However, the materials I used (primarily cardboard, straws, and wood) couldn’t eliminate vibrations entirely.

The final version still exhibits some vibration, especially when the motors accelerate or decelerate. While it causes slight wobbling in lines, the effect is minor enough to be acceptable for most drawings.

#### **Z-Axis: Pen Lifting Mechanism**
Creating a reliable Z-axis was one of the most difficult problems. Since everything was cut and assembled by hand, the X-axis wasn’t perfectly level. This meant that simply gluing a pen to the carriage wouldn’t work—the pen would press too hard in some places and barely touch the paper in others.

The first Z-axis attempt involved a servo motor rotating a gear, which meshed with a rack gear attached to the pen. The pen itself was mounted on two parallel straws, which slid along wooden rods in the carriage; this allowed vertical movement while keeping the pen in place. Unfortunately, the system wasn’t precise enough. The small vertical distances required made the servo's resolution a problem, and the plastic gears often slipped, requiring constant recalibration.

This system was eventually abandoned and replaced by a spring-loaded pen. In this final version, a spring compensates for uneven surfaces, and a string controlled by a servo motor lifts the pen when needed. This simplified the Z-axis and greatly improved reliability.

#### **Drawing Automation**
Initially, I manually controlled the motors through Arduino code, without using any libraries. This was sufficient for testing and basic manual drawing, but it became a problem when trying to draw diagonal lines or curves. I experimented with adapting Bresenham’s line algorithm, which helped with straight lines at arbitrary angles, but overall control was still imprecise.

To solve this, I adopted the AccelStepper library, and specifically its MultiStepper feature. This allowed me to coordinate both motors smoothly, resulting in consistent and accurate line drawing, including diagonal movements.

#### **Instruction Automation**
Generating drawing instructions was another major hurdle. My first approach was to write a custom Python script using OpenCV to trace image outlines and convert them into drawing commands. Unfortunately, the results were rough and barely resembled the original images.

Instead, I turned to existing tools developed for industrial machines. I used Inkscape (an open-source vector graphics editor) with the J Tech Laser Tool extension to export images as G-code. From there, I wrote Python scripts that could:

- Parse the G-code,
- Preview the drawing using Python’s turtle module,
- And organize the instructions into smaller files for upload to the Arduino.

This workflow enabled full automation of the drawing process in the final version. The final interface included an integrated Python GUI to make managing and sending instructions easier.

### Design Tradeoffs
#### Cheap Materials vs. Vibration Control
To keep the project low-cost and accessible, I used recycled and easily available materials like cardboard, straws, wooden rods, and hot glue. These were ideal for a solo, low-budget build and allowed me to prototype quickly without needing specialized tools. However, such materials are not ideal for absorbing motor vibrations. Despite efforts to minimize vibration (especially by reinforcing the structure with wooden supports) the final version still exhibits noticeable vibration. This causes the pen to draw in tiny spirals rather than clean straight lines, slightly reducing drawing precision. Still, this tradeoff was essential for making the project feasible in the first place.

#### Ease of Construction vs. Mechanical Precision
Since I didn’t have access to precise cutting tools or a 3D printer, all parts were cut by hand using scissors, cutters, and hand saws. While this made the project accessible and flexible to iterate on, it also introduced structural imperfections such as uneven surfaces, slightly tilted parts, and inconsistent measurements. These issues directly impacted precision and made mechanical alignment difficult. To work around these challenges, I developed adaptive components such as the spring-loaded pen, which compensated for slight variations in surface height and construction error.

#### Compact Design vs. Drawing Detail
Building a smaller machine made the design easier to manage and build, especially for a single person working with limited space and tools. The reduced scale meant fewer materials and tighter tolerances, which helped maintain mechanical consistency. However, it also limited the machine’s drawing area to 11.3 cm by 13.5 cm. While this is sufficient for most drawings, it imposes a limit on detail. Lines that are too close together may blend due to vibration and space constraints. A larger machine could have reduced the impact of vibration on drawing quality, but it would have required significantly more effort and resources to build.
