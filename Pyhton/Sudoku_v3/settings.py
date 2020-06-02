# Colours
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
LIGHTBLUE = (95, 215, 230)
LOCKEDCELLCOLOUR = (190, 190, 190)

# Board
emptyBoard = [[0 for y in range(9)] for x in range(9)]
PlayBoard = [[0, 0, 0, 0, 1, 0, 3, 0, 6],
             [0, 3, 0, 6, 0, 5, 0, 0, 9],
             [8, 6, 0, 4, 2, 0, 1, 5, 0],
             [0, 0, 0, 0, 0, 8, 0, 3, 1],
             [0, 8, 0, 2, 0, 1, 0, 6, 0],
             [1, 2, 0, 7, 0, 0, 0, 0, 0],
             [0, 9, 7, 0, 6, 4, 0, 1, 2],
             [2, 0, 0, 3, 0, 9, 0, 7, 0],
             [4, 0, 8, 0, 7, 0, 0, 0, 0]]

# positions and sizes
WIDTH = 600
HEIGHT = 600
gridPos = (75, 100)
cellSize = 50
gridSize = cellSize*9
