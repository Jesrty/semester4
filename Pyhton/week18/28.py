import turtle
from turtle import done
canvas = turtle.Screen()
canvas.setup(1080, 640, 0, 0)
escher = turtle.Turtle()
escher.speed(0.6)

instructions = "zazazazazazazazazazazazazazazaz"

for task in instructions:
    if task == "a":
        escher.right(25)
    elif task == "b":
        escher.forward(3*10)
    elif task == "c":
        escher.forward(8*10)
    elif task == "d":
        escher.forward(2*10)
    elif task == "e":
        escher.left(25)
    elif task == "f":
        escher.forward(3*10)
    elif task == "g":
        escher.forward(3*10)
    elif task == "h":
        escher.forward(4*10)
    elif task == "i":
        escher.right(75)
    elif task == "j":
        escher.forward(4*10)
    elif task == "k":
        escher.forward(3*10)
    elif task == "l":
        escher.forward(2*10)
    elif task == "m":
        escher.forward(4*10)
    elif task == "n":
        escher.forward(1*10)
    elif task == "o":
        escher.left(50)
    elif task == "p":
        escher.forward(4*10)
    elif task == "q":
        escher.forward(0*10)
    elif task == "r":
        escher.forward(1*10)
    elif task == "s":
        escher.forward(2*10)
    elif task == "t":
        escher.forward(2*10)
    elif task == "u":
        escher.right(75)
    elif task == "v":
        escher.forward(4*10)
    elif task == "w":
        escher.forward(0*10)
    elif task == "x":
        escher.forward(8*10)
    elif task == "y":
        escher.left(100)
    elif task == "z":
        escher.forward(9*10)
    elif task == "æ":
        escher.right(100)
    elif task == "ø":
        escher.left(100)
    elif task == "å":
        escher.right(100)

done()
