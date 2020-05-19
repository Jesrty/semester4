WIDTH = 600
HEIGHT = 600


# Colours
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
LIGHTBLUE = (95, 215, 230)

# Board
testBoard1 = [[0 for y in range(9)] for x in range(9)]
testBoard2 = [[8, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 3, 6, 0, 0, 0, 0, 0],
              [0, 7, 0, 0, 9, 0, 2, 0, 0],
              [0, 5, 0, 0, 0, 7, 0, 0, 0],
              [0, 0, 0, 0, 4, 5, 7, 0, 0],
              [0, 0, 0, 1, 0, 0, 0, 3, 0],
              [0, 0, 1, 0, 0, 0, 0, 6, 8],
              [0, 0, 8, 5, 0, 0, 0, 1, 0],
              [0, 9, 0, 0, 0, 0, 4, 0, 0]]

# positions and sizes
gridPos = (75, 100)
cellSize = 50
gridSize = cellSize*9
