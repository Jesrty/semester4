import turtle

canvas = turtle.Screen()
escher = turtle.Turtle()
escher.speed(0.6)

instructions = "FF+F-FF-FF-FF-FF+FF+FF"

for task in instructions:
    if task == "F":
        escher.forward(25)
    elif task == "+":
        escher.right(45)
    elif task == "-":
        escher.left(45)