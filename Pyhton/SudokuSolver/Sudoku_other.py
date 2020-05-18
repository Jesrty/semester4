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

    def find_empty(self):
        for i in range(len(self.board)):
            for j in range(len(self.board[0])):
                if self.board[i][j] == 0:
                    return (i, j) #række, kollone
        return None

    def _check(self, n, pos):
        # check række
        for i in range(len(self.board[0])):
            if self.board[pos[0]][i] == n and pos[1] != i:
                return False

        #check kollone
        for i in range(len(self.board)):
            if self.board[i][pos[1]] == n and pos[0] != i:
                return False

        #check firkant
        x0 = (pos[1] // 3)
        y0 = (pos[0] // 3)
        for i in range(y0 * 3, y0*3 + 3):
            for j in range(x0 * 3, x0 * 3 + 3):
                if self.board[i][j] == n and (i, j) != pos:
                    return False
        return True

    def solver(self):
        find = self.find_empty()
        if not find:
            return True
        else:
            row, col = find
        for i in range(1, 10):
            if self._check(i, (row, col)):
                self.board[row][col] = i

                if self.solver():
                    return True

                self.board[row][col] = 0
        return False

'''
ss = SudokuSolver(myBoard)
ss.print_board()
print("\n\n")
ss.solver()
ss.print_board()
'''
