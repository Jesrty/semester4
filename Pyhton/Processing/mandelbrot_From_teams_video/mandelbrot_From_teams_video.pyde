import time

xmin, xmax = -2, 0.8
ymin, ymax = -1.5, 1.5

max_iter = 200

screen_width, screen_height = 400, 400

def pix(x, y):
    return x + y * width

def setup():
    t0 = time.time()
    size(screen_width, screen_height)
    
    loadPixels()
    for cx in range(height):
        for cy in range(height):
            cr = map(cx, 0, width, xmin, xmax)
            ci = map(cy, 0, height, ymin, ymax)
            
            c = complex(cr, ci)
            z = complex(0, 0)
            
            for i in range(max_iter):
                z = z * z + c
                if abs(z) > 2:
                    pixels[pix(cx, cy)] = color(255)
                    break
                
            else:
                pixels[pix(cx, cy)] = color(0)
    updatePixels()
    
    t1 = time.time()
    print("time_ %s") % str(t1 -t0)[:4]
