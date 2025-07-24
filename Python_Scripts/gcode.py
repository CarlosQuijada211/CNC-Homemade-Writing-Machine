import re
import os
import math
from pathlib import Path
from preview import draw

def gcode_to_instructions(gcode_lines):
    pen_down = False
    instructions = []

    for line in gcode_lines:
        line = line.strip()
        if line.startswith('M03'):
            pen_down = True
        elif line.startswith('M05'):
            pen_down = False
        elif line.startswith('G0') or line.startswith('G1'):
            # Extract X and Y
            x_match = re.search(r'X([-\d\.]+)', line)
            y_match = re.search(r'Y([-\d\.]+)', line)
            if x_match and y_match:
                x = int(round(float(x_match.group(1))))
                y = int(round(float(y_match.group(1))))
                instructions.append((x, y, pen_down))
    return instructions

def to_arduino_code(instructions):
    lines = []
    for inst in instructions:
        x_mm, y_mm, marker = inst
        x_cm = (x_mm / 10.0) * 6368
        y_cm = (y_mm / 10.0) * 6368
        marker_str = 'true' if marker else 'false'
        line = f"{{{int(x_cm)}, {int(y_cm)}, {marker_str} }},"
        lines.append(line)
    return "\n".join(lines)

def generate_file(file):
    # Select Gcode file to read
    filename = f"Gcode/{file}.gcode"
    name = str(file)

    # Read Gcode file
    with open(filename, 'r') as file:
        gcode_lines = file.readlines()

    # Turn to preview instructions
    instructions = gcode_to_instructions(gcode_lines)  
    print(len(instructions))
    ins_length =   len(instructions)

    # Create a text file and store instructions

        # Small drawing (Only one file required)
    if len(instructions) <= 2500:
        # Turn instructions into arduino code
        arduino_array_str = to_arduino_code(instructions)

        # Write to file
        with open(f"Instructions/{name}.txt", "w") as f:
            f.write(arduino_array_str)

        # Large drawing (More than one file required)
    elif ins_length > 2500:

        # Create a directory for instructions
        nested_directory = f"Instructions/{name}"

        # Create nested directorie and prevent any error
        try:
            os.makedirs(nested_directory)
            print(f"Nested directories '{nested_directory}' created successfully.")
        except FileExistsError:
            print(f"One or more directories in '{nested_directory}' already exist.")
        except PermissionError:
            print(f"Permission denied: Unable to create '{nested_directory}'.")
        except Exception as e:
            print(f"An error occurred: {e}")

        # How many files will be needed
        iterations = math.ceil(ins_length / 2500)

        for i in range(1, iterations + 1):

            # Set of instructions for this file
            if i == iterations: # Last slice
                current_slice = instructions[((i-1)*2500):]

                # Make sure next iterations beings with pen up
                previous_instruction = list(instructions[((i-1)*2500) - 1])
                previous_instruction[2] = False
                current_slice.insert(0, tuple(previous_instruction))

                arduino_array_str = to_arduino_code(current_slice)
                
            else:
                # Select the slice of the instructions that will be added to the current file
                current_slice = instructions[((i-1)*2500):(i*2500)]

                # Make sure next iterations beings with pen up
                if i != 1:
                    previous_instruction = list(instructions[((i-1)*2500) - 1])
                    previous_instruction[2] = False
                    current_slice.insert(0, tuple(previous_instruction))

                # Make sure the machine goes back to the origin 
                current_slice.append((0, 0, False))

                # Translate current slice to arduino code
                arduino_array_str = to_arduino_code(current_slice)

            # Write to current file in created directory
            with open(f"{nested_directory}/{name}{i}.txt", "w") as f:
                f.write(arduino_array_str)

def generate_preview(file):
     # Select Gcode file to read
    filename = f"Gcode/{file}.gcode"

    # Read Gcode file
    with open(filename, 'r') as file:
        gcode_lines = file.readlines()

    # Turn to preview instructions
    instructions = gcode_to_instructions(gcode_lines)

    # Call from preview.py and show preview
    draw(instructions)

def check_filename(file):
    filename = Path(f"Gcode/{file}.gcode")

    if not filename.exists():
        return False
    else:
        return True
