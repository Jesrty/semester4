import sys
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
        self.playingButton = []
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
            if event.type == pygame.MOUSEBUTTONDOWN:
                if self.playingButton[0].hoverButton(self.mousePos):
                    self.solver()
                if self.playingButton[1].hoverButton(self.mousePos):
                    self.play()
                if self.playingButton[2].hoverButton(self.mousePos):
                    self.clear()

    def playing_update(self):
        self.mousePos = pygame.mouse.get_pos()

        # change color when hovering
        for button in self.playingButton:
            button.hoverButton(self.mousePos)

    def playing_draw(self):
        self.window.fill(WHITE)

        # draws the buttons
        for button in self.playingButton:
            button.draw(self.window)

        # draws the clicked cell light blue
        if self.selected:
            self.drawSelected(self.window, self.selected)

        # draw the locked cells gray
        self.shadeLockedCells(self.window, self.lockedCell)

        # draws the numbers in the grid
        self.drawNumbers(self.window)

        # draw the grid (the lines in square)
        self.drawGrid(self.window)

        pygame.display.update()

##### HELPER FUNKCTIONS #####

    # draw the locked cells gray
    def shadeLockedCells(self, window, locked):
        for cell in locked:
                           # Surface, color, Rect, width
            pygame.draw.rect(window, LOCKEDCELLCOLOUR, (cell[0]*cellSize+gridPos[0], cell[1]*cellSize+gridPos[1], cellSize, cellSize))

    # draws the numbers in the grid
    def drawNumbers(self, window):
        for yidx, row in enumerate(self.grid):
            for xidx, num in enumerate(row):
                if num != 0:
                    pos = [xidx*cellSize+gridPos[0], yidx*cellSize+gridPos[1]]
                    self.textToScreen(window, str(num), pos)

    # draws the clicked cell light blue
    def drawSelected(self, window, pos):
                        # Surface, color, Rect, width
        pygame.draw.rect(window, LIGHTBLUE, ((pos[0]*cellSize)+gridPos[0], (pos[1]*cellSize)+gridPos[1], cellSize, cellSize))

    # draw the grid (the lines in square)
    def drawGrid(self, window):
        # draw the outer lines    Surface, color, Rect, width
        pygame.draw.rect(window, BLACK, (gridPos[0], gridPos[1], WIDTH-150, HEIGHT-150), 2)
        # draws the lines insdie   Surface, color, Rect, width
        for x in range(9):
            pygame.draw.line(window, BLACK, (gridPos[0]+(x*cellSize), gridPos[1]), (gridPos[0]+(x*cellSize), gridPos[1]+450), 2 if x % 3 == 0 else 1)
            pygame.draw.line(window, BLACK, (gridPos[0], gridPos[1]+(x*cellSize)), (gridPos[0]+450, gridPos[1]+(x*cellSize)), 2 if x % 3 == 0 else 1)

    # check if the mouse is on the bord  and returns cell pos fx (1,2)
    def mouseOnGrid(self):
        if self.mousePos[0] < gridPos[0] or self.mousePos[1] < gridPos[1]:
            return False
        elif self.mousePos[0] > gridPos[0]+gridSize or self.mousePos[1] > gridPos[1]+gridSize:
            return False

        return ((self.mousePos[0]-gridPos[0])//cellSize, (self.mousePos[1]-gridPos[1])//cellSize)

    # load the buttons and add them 2 the button list
    def loadButtons(self):
        self.playingButton.append(Button(gridPos[0], 40, 100, 40, text="Solver"))
        self.playingButton.append(Button(gridPos[0]+110, 40, 100, 40, text="Play"))
        self.playingButton.append(Button(gridPos[0]+220, 40, 100, 40, text="Clear"))

    # draw the text in the cells but could draw other things
    def textToScreen(self, window, text, pos):
        font = self.font.render(text, False, BLACK)
        fontWidth = font.get_width()
        fontHeight = font.get_height()
        pos[0] += (cellSize-fontWidth)//2
        pos[1] += (cellSize-fontHeight)//2
        window.blit(font, pos)

    # the method called in the init
    def load(self):
        self.loadButtons()

    # check if the given string is an int
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

    # the play function thats called when you click the play button so it print the bord below
    def play(self):
        self.grid = [[0, 0, 0, 0, 1, 0, 3, 0, 6],
                    [0, 3, 0, 6, 0, 5, 0, 0, 9],
                    [8, 6, 0, 4, 2, 0, 1, 5, 0],
                    [0, 0, 0, 0, 0, 8, 0, 3, 1],
                    [0, 8, 0, 2, 0, 1, 0, 6, 0],
                    [1, 2, 0, 7, 0, 0, 0, 0, 0],
                    [0, 9, 7, 0, 6, 4, 0, 1, 2],
                    [2, 0, 0, 3, 0, 9, 0, 7, 0],
                    [4, 0, 8, 0, 7, 0, 0, 0, 0]]
        # setting locked cells from og board
        for yidx, row in enumerate(self.grid):
            for xidx, num in enumerate(row):
                if num != 0:
                    self.lockedCell.append((xidx, yidx))

    # the clear function thats called when you click the clear button so it removes every thing from the bord
    def clear(self):
        self.lockedCell.clear()
        self.grid = [[0 for y in range(9)] for x in range(9)]














