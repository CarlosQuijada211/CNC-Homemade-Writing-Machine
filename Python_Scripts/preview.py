import turtle

# === CONFIG ===
DRAWING_AREA_MM_X = 135  # Machine's drawing width in mm
DRAWING_AREA_MM_Y = 113  # Machine's drawing height in mm

SCALE = 3  # Scale factor to make the preview larger on screen

def draw(instructions):
    # === TURTLE SETUP ===
    screen = turtle.Screen()
    screen.title("Machine Path Preview")
    screen.setup(width=DRAWING_AREA_MM_X * SCALE + 50, height=DRAWING_AREA_MM_Y * SCALE + 50)
    screen.setworldcoordinates(0, 0, DRAWING_AREA_MM_X, DRAWING_AREA_MM_Y)

    pen = turtle.Turtle()
    pen.speed(0)
    pen.penup()
    pen.hideturtle()

    # === DRAW BOUNDARY ===
    boundary = turtle.Turtle()
    boundary.speed(0)
    boundary.penup()
    boundary.goto(0, 0)
    boundary.pendown()
    boundary.goto(DRAWING_AREA_MM_X, 0)
    boundary.goto(DRAWING_AREA_MM_X, DRAWING_AREA_MM_Y)
    boundary.goto(0, DRAWING_AREA_MM_Y)
    boundary.goto(0, 0)
    boundary.hideturtle()

    # === DRAW THE PATH ===
    for x_mm, y_mm, marker_down in instructions:
        if marker_down:
            pen.pendown()
        else:
            pen.penup()
        pen.goto(x_mm, y_mm)

    # === DONE ===
    screen.mainloop()