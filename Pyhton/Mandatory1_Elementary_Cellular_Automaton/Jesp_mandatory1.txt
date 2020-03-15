#this test is ofc only for rule 126 with length 16
"""
>>> e = ElementaryCellularAutomaton(16, 126)
>>> e.run()
███████████████░██████████████
██████████████░░░█████████████
█████████████░░█░░████████████
████████████░░░░░░░███████████
███████████░░█████░░██████████
██████████░░░░███░░░░█████████
█████████░░██░░█░░██░░████████
████████░░░░░░░░░░░░░░░███████
███████░░█████████████░░██████
██████░░░░███████████░░░░█████
█████░░██░░█████████░░██░░████
████░░░░░░░░███████░░░░░░░░███
███░░██████░░█████░░██████░░██
██░░░░████░░░░███░░░░████░░░░█
█░░██░░██░░██░░█░░██░░██░░██░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
"""


class Rule:
    def __init__(self, rule_number):
        self.rule_number = rule_number

    def return_number(self):
        return self.rule_number

    def return_list(self):
        # make the list of the binery number
        my_list = [int(i) for i in list("{0:b}".format(self.rule_number))]
        #if the binary number is shorter then 8 it put 0 in the list so its 2 byts long
        while len(my_list) < 8:
            my_list.insert(0, 0)
        return my_list


class ElementaryCellularAutomaton:
    def __init__(self, run_time, rule_number):
        self.run_time = run_time
        self.rule = Rule(rule_number).return_list()
        self.list1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.list2 = []

    def run(self):
        # tegn som kan bruges til at give andre farver   █░ --- _# --- █| --- █ ---
        #a dictionary that is use 2 replace 0 and 1 with difrent signs
        dic_flot_print = {0: "█", 1: "░"}

        #prints the first line that is made up in the __init__
        print(''.join([dic_flot_print[value] for value in self.list1]))
        counter = 1
        #makes the next list and prints them out
        while counter < self.run_time:
            #append to the list the number from the given rule
            for x in range(len(self.list1)):
                #makes sure you don't get an error at x-1 out of bouns
                if x == 0:
                    if self.list1[x] == 0 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[7])
                    elif self.list1[x] == 0 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[6])
                    elif self.list1[x] == 1 and self.list1[x+1] == 0:
                        self.list2.append(self.rule[5])
                    elif self.list1[x] == 1 and self.list1[x+1] == 1:
                        self.list2.append(self.rule[4])
                #makes sure you don't get an error at last run at x+1 out of bouns
                elif x == (len(self.list1) - 1):
                    if self.list1[x-1] == 0 and self.list1[x] == 0:
                        self.list2.append(self.rule[7])
                    elif self.list1[x-1] == 0 and self.list1[x] == 1:
                        self.list2.append(self.rule[5])
                    elif self.list1[x-1] == 1 and self.list1[x] == 0:
                        self.list2.append(self.rule[3])
                    elif self.list1[x-1] == 1 and self.list1[x] == 1:
                        self.list2.append(self.rule[1])
                #makes sure the middle number gets added corektly
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

            #prints the list (next line) after every number have been added
            print(''.join([dic_flot_print[value] for value in self.list2]))

            #print(self.list2)
            #se the old list 2 the new list and empty the new list
            self.list1 = self.list2
            self.list2 = []
            counter += 1

#the class takes 2 peremetos the length and the number/rule
#e = ElementaryCellularAutomaton(16, 126)
#e.run()

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True, optionflags=doctest.ELLIPSIS)