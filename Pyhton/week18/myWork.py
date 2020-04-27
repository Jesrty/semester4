from turtle import *

color('black', 'green')
begin_fill()

while True:
    forward(75)
    left(45)
    for x in range(4):
        forward(75)
        right(90)
    if abs(pos()) < 1:
        break

end_fill()

color('black', 'blue')
begin_fill()

while True:
    forward(75)
    left(45)
    if abs(pos()) < 1:
        break
end_fill()
done()