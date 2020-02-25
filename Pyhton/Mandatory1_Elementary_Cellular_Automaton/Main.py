class Rule:
    def __init__(self, rule_number):
        self.rule_number = rule_number

    def return_number(self):
        return self.rule_number

    def return_list(self):
        my_list = [int(i) for i in list("{0:b}".format(self.rule_number))]
        while len(my_list) < 8:
            my_list.insert(0, 0)
        return my_list


class AutoFiller:
    def __init__(self, rule_number):
        self.r = Rule(rule_number)
        self.my_board = [[0, 0, 0, 0, 0, 0, 0, 0, 0] for i in range(8)]
        self.my_board.insert(0, [0, 0, 0, 0, 1, 0, 0, 0, 0])

    def return_grid(self):
        return self.my_board

    def grid_fill(self):
        number_x = 1
        number_y = 0
        for x in self.my_board:
            for y in x:
                self.my_board[number_x][number_y] = 1
                number_y += 1
            number_x += 1
            number_y = 0

    def print_grid(self):
        for x in self.my_board:
            for y in x:
                print(y, end=" ")
            print("")













#r = Rule(30)
#print("you have selected rule {} in other words {}".format(r.rule_number, r.return_list()))

AF = AutoFiller(30)
#print(AF.return_grid())
AF.grid_fill()
AF.print_grid()
