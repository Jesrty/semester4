size(640, 360)
noLoop()
background(255)

w = 4
h = (w * height) / width

xmin = -w / 2
ymin = -h / 2

loadPixels()
maxiterations = 100

xmax = xmin + w
ymax = ymin + h

dx = (xmax - xmin) / width
dy = (ymax - ymin) / height

y = ymin
for j in range(0, height):
    x = xmin
    for i in range(0, width):
        a =x
        b = y
        n = 0
        max = 4.0
        absOld = 0.0
        convergeNuber = maxiterations
        while(n<maxiterations):
            aa = a*a
            bb = b*b
            abs = sqrt(aa + bb)
            if abs > max:
                diffToLast = abs - absOld
                diffToMax = max - absOld
                convereNumber = diffToMax/diffToLast
                break
            twoab = 2.0 * a * b
            a = aa - bb + x
            b = twoab + y
            n += 1
            absOld = abs
        
        if n == maxiterations:
            pixels[i+j*width] = color(0)
        else:
            norm = map(convereNumber, 0, maxiterations, 0, 1)
            pixels[i+j*width] = color(map(sqrt(norm), 0, 1, 0, 255))
        x += dx
    y += dy
updatePixels()    
