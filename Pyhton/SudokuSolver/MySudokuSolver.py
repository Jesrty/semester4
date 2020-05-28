import datetime

sudokuBoard = [[0, 0, 0, 7, 0, 0, 0, 0, 0],
                [1, 0, 0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 4, 3, 0, 2, 0, 0],
                [0, 0, 0, 0, 0, 0, 0, 0, 6],
                [0, 0, 0, 5, 0, 9, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 4, 1, 8],
                [0, 0, 0, 0, 8, 1, 0, 0, 0],
                [0, 0, 2, 0, 0, 0, 0, 5, 0],
                [0, 4, 0, 0, 0, 0, 3, 0, 0]]

class MySudokuSolver:
    '''
    >>> sudokuBoard = [[8, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 3, 6, 0, 0, 0, 0, 0], [0, 7, 0, 0, 9, 0, 2, 0, 0], [0, 5, 0, 0, 0, 7, 0, 0, 0], [0, 0, 0, 0, 4, 5, 7, 0, 0], [0, 0, 0, 1, 0, 0, 0, 3, 0], [0, 0, 1, 0, 0, 0, 0, 6, 8], [0, 0, 8, 5, 0, 0, 0, 1, 0], [0, 9, 0, 0, 0, 0, 4, 0, 0]]

    >>> sudoku = MySudokuSolver(sudokuBoard)
    >>> sudoku.print_board()
    8 0 0  | 0 0 0  | 0 0 0
    0 0 3  | 6 0 0  | 0 0 0
    0 7 0  | 0 9 0  | 2 0 0
    - - - - - - - - - - - -
    0 5 0  | 0 0 7  | 0 0 0
    0 0 0  | 0 4 5  | 7 0 0
    0 0 0  | 1 0 0  | 0 3 0
    - - - - - - - - - - - -
    0 0 1  | 0 0 0  | 0 6 8
    0 0 8  | 5 0 0  | 0 1 0
    0 9 0  | 0 0 0  | 4 0 0

    >>> sudoku._check_empty_square()
    (0, 1)

    >>> sudoku._check_number(6, (1, 1))
    False
    >>> sudoku._check_number(9, (1, 1))
    False
    >>> sudoku._check_number(8, (1, 1))
    False
    >>> sudoku._check_number(2, (1, 1))
    True

    >>> sudoku.solver()
    True

    >>> sudoku.print_board()
    8 1 2  | 7 5 3  | 6 4 9
    9 4 3  | 6 8 2  | 1 7 5
    6 7 5  | 4 9 1  | 2 8 3
    - - - - - - - - - - - -
    1 5 4  | 2 3 7  | 8 9 6
    3 6 9  | 8 4 5  | 7 2 1
    2 8 7  | 1 6 9  | 5 3 4
    - - - - - - - - - - - -
    5 2 1  | 9 7 4  | 3 6 8
    4 3 8  | 5 2 6  | 9 1 7
    7 9 6  | 3 1 8  | 4 5 2
    '''
    def __init__(self, board):
        self.board = board

    def print_board(self):
        for i in range(len(self.board)):
            #  the numbers with a line (vertical) every 3'ed row to make the squares
            if i % 3 == 0 and i != 0:
                print("- - - - - - - - - - - -")

            for j in range(len(self.board[0])):
                # separating the numbers with a line (horizontally) every 3'ed column to make the squares
                if j % 3 == 0 and j != 0:
                    print(" | ", end="")

                # after the 9 numbers make a new line (\n) else just print the numbers on the same line with space
                if j == 8:
                    print(self.board[i][j])
                else:
                    print(str(self.board[i][j]) + " ", end="")

    def _check_empty_square(self):
        # check every place in the board for a 0 and returns the coordinates (in a tuple) or None if there is no 0
        for i in range(len(self.board)):
            for j in range(len(self.board[0])):
                if self.board[i][j] == 0:
                    return (i, j) # row, column
        return None

    def _check_number(self, n, pos):
        # check if the row contains the number n
        for i in range(len(self.board[0])):
            if self.board[pos[0]][i] == n and pos[1] != i:
                return False

        # check if the column contains the number n
        for i in range(len(self.board)):
            if self.board[i][pos[1]] == n and pos[0] != i:
                return False

        # gives the square's upper left position
        x0 = (pos[1] // 3) * 3
        y0 = (pos[0] // 3) * 3
        # check if the square contains the number n
        for i in range(y0, y0 + 3):
            for j in range(x0, x0 + 3):
                if self.board[i][j] == n and (i, j) != pos:
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
                self.board[row][col] = i

                # will recursive call until the board is full (true) or loop though all the numbers
                if self.solver():
                    return True

                # if no number match it back tracks and have 2 set the number too 0
                self.board[row][col] = 0
        # return false if no solution
        return False

'''
if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True, optionflags=doctest.ELLIPSIS)
'''

ss = MySudokuSolver(sudokuBoard)
print(datetime.datetime.now())
ss.solver()
ss.print_board()
print(datetime.datetime.now())