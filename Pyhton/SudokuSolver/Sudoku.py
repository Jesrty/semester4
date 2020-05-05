
myBoard = [
    [8, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 3, 6, 0, 0, 0, 0, 0],
    [0, 7, 0, 0, 9, 0, 2, 0, 0],
    [0, 5, 0, 0, 0, 7, 0, 0, 0],
    [0, 0, 0, 0, 4, 5, 7, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 3, 0],
    [0, 0, 1, 0, 0, 0, 0, 6, 8],
    [0, 0, 8, 5, 0, 0, 0, 1, 0],
    [0, 9, 0, 0, 0, 0, 4, 0, 0]
]


class SudokuSolver:
    def __init__(self, board):
        self.board = board

    def print_board(self):
        for i in range(len(self.board)):
            if i % 3 == 0 and i != 0:
                print("- - - - - - - - - - - -")

            for j in range(len(self.board[0])):
                if j % 3 == 0 and j != 0:
                    print(" | ", end="")

                if j == 8:
                    print(self.board[i][j])
                else:
                    print(str(self.board[i][j]) + " ", end="")

    def _check(self, y, x, n):
        #tjekker vandret
        for i in range(len(self.board)):
            if self.board[y][i] == n:
                return False

        #tjekker lodret
        for j in range(len(self.board[y])):
            if self.board[j][x] == n:
                return False

        #tjekker firkant
        x0 = (x//3)*3
        y0 = (y//3)*3
        for i in range(3):
            for j in range(3):
                if self.board[y0+i][x0+j] == n:
                    return False

        return True

    def solver(self):
        for y in range(9):
            for x in range(9):
                if self.board[y][x] == 0:
                    for n in range(1,10):
                        if self._check(y, x, n):
                            self.board[y][x] = n
                            self.solver()
                            self.board[y][x] = 0
                    return
        self.print_board()
        print("\n")
        #input("\nMore?\n")










ss = SudokuSolver(myBoard)
ss.print_board()

print("\n\n\n")
ss.solver()