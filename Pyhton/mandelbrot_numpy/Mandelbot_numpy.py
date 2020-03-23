from PIL import Image
import numpy as np

width, height = 400, 400
xmin, xmax = -2, 0.8
ymin, ymax = -1.5, 1.5

max_iter = 200

cmap = lambda value, v_min, v_max, p_min, p_max: p_min + (p_max - p_min) * ((value - v_min)/(v_max - v_min))

C = np.zeros((width, height), dtype=np.complex_)
Z = np.zeros((width, height), dtype=np.complex_)
M = np.zeros((width, height))

for cx in range(width):
    for cy in range(height):
        cr = cmap(cx, 0, width, xmin, xmax)
        ci = cmap(cy, 0, height, ymin, ymax)
        C[cx][cy] = cr + ci * 1j

for i in range(max_iter):
    N = np.less(abs(Z), 2)
    Z[N] = Z[N] * Z[N] + C[N]
    M[N & (abs(Z) > 2)] = 255

Image.fromarray(np.uint8(M.T))
