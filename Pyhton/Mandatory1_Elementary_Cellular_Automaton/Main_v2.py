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


class ElementaryCellularAutomaton:
    def __init__(self, run_time, rule_number):
        self.run_time = run_time
        self.rule = Rule(rule_number).return_list()
        self.list1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.list2 = []

    def run(self):
        dic_flot_print = {0: "_", 1: "#"}
        print(''.join([dic_flot_print[value] for value in self.list1]))
        counter = 1
        while counter < self.run_time:
            for x in range(len(self.list1)):
                if x == 0:
                    if self.list1[x] == 0 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[7])
                    elif self.list1[x] == 0 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[6])
                    elif self.list1[x] == 1 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[5])
                    elif self.list1[x] == 1 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[4])

                elif x == (len(self.list1) - 1):
                    if self.list1[x-1] == 0 and self.list1[x] == 0:
                        self.list2.append(self.rule[7])
                    elif self.list1[x-1] == 0 and self.list1[x] == 1:
                        self.list2.append(self.rule[5])
                    elif self.list1[x-1] == 1 and self.list1[x] == 0:
                        self.list2.append(self.rule[3])
                    elif self.list1[x-1] == 1 and self.list1[x] == 1:
                        self.list2.append(self.rule[1])
                else:
                    if self.list1[x-1] == 0 and self.list1[x] == 0 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[7])
                    elif self.list1[x-1] == 0 and self.list1[x] == 0 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[6])
                    elif self.list1[x-1] == 0 and self.list1[x] == 1 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[5])
                    elif self.list1[x-1] == 0 and self.list1[x] == 1 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[4])
                    elif self.list1[x-1] == 1 and self.list1[x] == 0 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[3])
                    elif self.list1[x-1] == 1 and self.list1[x] == 0 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[2])
                    elif self.list1[x-1] == 1 and self.list1[x] == 1 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[1])
                    elif self.list1[x-1] == 1 and self.list1[x] == 1 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[0])

            print(''.join([dic_flot_print[value] for value in self.list2]))

            #print(self.list2)
            self.list1 = self.list2
            self.list2 = []
            counter += 1


e = ElementaryCellularAutomaton(60, 126)
e.run()
