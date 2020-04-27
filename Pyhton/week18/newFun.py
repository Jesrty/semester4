from turtle import *
color('red')

x = 1

while True:
    forward(8)
    left(x)
    x = x + 0.05
    if x >= 25:
        break


done()