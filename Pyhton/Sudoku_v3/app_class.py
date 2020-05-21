import sys
from settings import *
import copy
from buttonClass import *


class App:
    def __init__(self):
        pygame.init()
        self.window = pygame.display.set_mode((WIDTH, HEIGHT))
        self.running = True
        self.grid = emptyBoard.copy()
        self.selected = None
        self.mousePos = None
        self.state = "playing"
        self.button1 = None
        self.button2 = None
        self.button3 = None
        self.lockedCell = []
        self.font = pygame.font.SysFont("arial", cellSize//2)
        self.load()

    def run(self):
        while self.running:
            if self.state == "playing":
                self.playing_events()
                self.playing_update()
                self.playing_draw()
        pygame.quit()
        sys.exit()

##### PLAYING STATE Functions #####

    def playing_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False

            # user clicks
            if event.type == pygame.MOUSEBUTTONDOWN:
                selected = self.mouseOnGrid()
                if selected:
                    self.selected = selected
                else:
                    self.selected = None

            # User types a key
            if event.type ==pygame.KEYDOWN:
                if self.selected != None and self.selected not in self.lockedCell:
                    if self.isInt(event.unicode):
                        # cell change
                        self.grid[self.selected[1]][self.selected[0]] = int(event.unicode)

            # User button click









    def playing_update(self):
        self.mousePos = pygame.mouse.get_pos()
        mouseClick = pygame.mouse.get_pressed()

        self.button1.update(self.mousePos)
        self.button2.update(self.mousePos)
        self.button3.update(self.mousePos)

        if self.button1.click(self.mousePos, mouseClick):
            self.solver()
        elif self.button2.click(self.mousePos, mouseClick):
            self.play()
        elif self.button3.click(self.mousePos, mouseClick):
            self.clear()

    def playing_draw(self):
        self.window.fill(WHITE)

        self.button1.draw(self.window)
        self.button2.draw(self.window)
        self.button3.draw(self.window)

        if self.selected:
            self.drawSelected(self.window, self.selected)

        self.shadeLockedCells(self.window, self.lockedCell)


        self.drawNumbers(self.window)
        self.drawGrid(self.window)
        pygame.display.update()

##### HELPER FUNKCTIONS #####

    def shadeLockedCells(self, window, locked):
        for cell in locked:
            pygame.draw.rect(window, LOCKEDCELLCOLOUR, (cell[0]*cellSize+gridPos[0], cell[1]*cellSize+gridPos[1], cellSize, cellSize))

    def drawNumbers(self, window):
        for yidx, row in enumerate(self.grid):
            for xidx, num in enumerate(row):
                if num != 0:
                    pos = [xidx*cellSize+gridPos[0], yidx*cellSize+gridPos[1]]
                    self.textToScreen(window, str(num), pos)


    def drawSelected(self, window, pos):
        pygame.draw.rect(window, LIGHTBLUE, ((pos[0]*cellSize)+gridPos[0], (pos[1]*cellSize)+gridPos[1], cellSize, cellSize))

    def drawGrid(self, window):
        pygame.draw.rect(window, BLACK, (gridPos[0], gridPos[1], WIDTH-150, HEIGHT-150), 2)
        for x in range(9):
            pygame.draw.line(window, BLACK, (gridPos[0]+(x*cellSize), gridPos[1]), (gridPos[0]+(x*cellSize), gridPos[1]+450), 2 if x % 3 == 0 else 1)
            pygame.draw.line(window, BLACK, (gridPos[0], gridPos[1]+(x*cellSize)), (gridPos[0]+450, gridPos[1]+(x*cellSize)), 2 if x % 3 == 0 else 1)

    def mouseOnGrid(self):
        if self.mousePos[0] < gridPos[0] or self.mousePos[1] < gridPos[1]:
            return False
        elif self.mousePos[0] > gridPos[0]+gridSize or self.mousePos[1] > gridPos[1]+gridSize:
            return False

        return ((self.mousePos[0]-gridPos[0])//cellSize, (self.mousePos[1]-gridPos[1])//cellSize)

    def loadButtons(self):
        self.button1 = Button(gridPos[0], 40, 100, 40, text="Solver")
        self.button2 = Button(gridPos[0]+110, 40, 100, 40, text="Play")
        self.button3 = Button(gridPos[0]+220, 40, 100, 40, text="Clear")


    def textToScreen(self, window, text, pos):
        font = self.font.render(text, False, BLACK)
        fontWidth = font.get_width()
        fontHeight = font.get_height()
        pos[0] += (cellSize-fontWidth)//2
        pos[1] += (cellSize-fontHeight)//2
        window.blit(font, pos)

    def load(self):
        self.loadButtons()

    def isInt(self, string):
        try:
            int(string)
            return True
        except:
            return False





### SOLVER METODER ###

    def _check_empty_square(self):
        # check every place in the board for a 0 and returns the coordinates (in a tuple) or None if there is no 0
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                if self.grid[i][j] == 0:
                    return (i, j)  # row, column
        return None

    def _check_number(self, n, pos):
        # check if the row contains the number n
        for i in range(len(self.grid[0])):
            if self.grid[pos[0]][i] == n and pos[1] != i:
                return False

        # check if the column contains the number n
        for i in range(len(self.grid)):
            if self.grid[i][pos[1]] == n and pos[0] != i:
                return False

        # gives the square's upper left position
        x0 = (pos[1] // 3) * 3
        y0 = (pos[0] // 3) * 3
        # check if the square contains the number n
        for i in range(y0, y0 + 3):
            for j in range(x0, x0 + 3):
                if self.grid[i][j] == n and (i, j) != pos:
                    return False
        # if none of the test contains the number n return true
        return True

    def solver(self):
        # use the _check_empty_square 2 get the position with a 0 (with out a number)
        find = self._check_empty_square()
        # if there is no 0 (empty position) the board is full and is a solution - else save the position in row and col
        if not find:
            return True
        else:
            row, col = find
        # loops through 1-9 (every number in a sudoku)
        for i in range(1, 10):
            # if the number is valid in the sudoku, insert the number on the position
            if self._check_number(i, (row, col)):
                self.grid[row][col] = i

                # will recursive call until the board is full (true) or loop though all the numbers
                if self.solver():
                    return True

                # if no number match it back tracks and have 2 set the number too 0
                self.grid[row][col] = 0
        # return false if no solution
        return False

    def play(self):
        self.grid = [[8, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 3, 6, 0, 0, 0, 0, 0],
                    [0, 7, 0, 0, 9, 0, 2, 0, 0],
                    [0, 5, 0, 0, 0, 7, 0, 0, 0],
                    [0, 0, 0, 0, 4, 5, 7, 0, 0],
                    [0, 0, 0, 1, 0, 0, 0, 3, 0],
                    [0, 0, 1, 0, 0, 0, 0, 6, 8],
                    [0, 0, 8, 5, 0, 0, 0, 1, 0],
                    [0, 9, 0, 0, 0, 0, 4, 0, 0]]
        # setting locked cells from og board
        for yidx, row in enumerate(self.grid):
            for xidx, num in enumerate(row):
                if num != 0:
                    self.lockedCell.append((xidx, yidx))

    def clear(self):
        self.lockedCell.clear()
        self.grid = [[0 for y in range(9)] for x in range(9)]

    # Marcus hjælpe liste
    # 1 button ikke klikker mange gange
    # 2 self.grid = emptyboard vil fucke det op











