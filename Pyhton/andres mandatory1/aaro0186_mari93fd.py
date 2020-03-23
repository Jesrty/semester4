class CellularAutomation:
    

    """Cellular Automata to generate a pattern taking as 
    parameters as a rule from 0 - 255, and a size to get the itinial state

    >>> rule = 30
    >>> size = 10
    >>> c = CellularAutomation(rule, size)
    ----------*----------
    ---------***---------
    --------**--*--------
    -------**-****-------
    ------**--*---*------
    -----**-****-***-----
    ----**--*----*--*----
    ---**-****--******---
    --**--*---***-----*--
    -**-****-**--*---***-

    >>> rule = 60
    >>> size = 10
    >>> c = CellularAutomation(rule, size)
    ----------*----------
    ----------**---------
    ----------*-*--------
    ----------****-------
    ----------*---*------
    ----------**--**-----
    ----------*-*-*-*----
    ----------********---
    ----------*-------*--
    ----------**------**-
    
    >>> rule = 210
    >>> size = 10
    >>> c = CellularAutomation(rule, size)
    ----------*----------
    ---------*-*---------
    --------*---*--------
    -------*-*-*-*-------
    ------*-------*------
    -----*-*-----*-*-----
    ----*---*---*---*----
    ---*-*-*-*-*-*-*-*---
    --*---------------*--
    -*-*-------------*-*-


    https://github.com/aaronalayo/dk.kea.dat18.python/blob/master/mandatory_assig/cellularautomation.py

    """
    def __init__ (self, rule, size):   
        self.rule = rule
        self.size = size
        self.generate()

    def generate(self):
         initial_state = '0' * self.size + '1' + '0' * self.size
         state = list(initial_state)
         length = len(state)
         row = 0
         
         while row < self.size:
              self.print_state(state)
              new_generation = [None]*length
              #new_generation.append('0')
              for i in range(0, length-1):
                  if (i == 0):
                      combination = state[i - 1], state[i], state[i + 1]
                  if (i == length - 2):
                      combination = state[i], state[i+1], state[0]
                      new_generation[i + 1] = self.generate_rule(combination)
                  left = state[i - 1]
                  center =  state[i]
                  right = state[i + 1]
                  combination = left, center, right
                  new_generation[i] = self.generate_rule(combination)
              state = new_generation
              row = row + 1


    def print_state(self, state):
        for cell in state:
            if cell == '1':
                print('*', end = "", flush=True)
            else:
                print('-', end = "", flush=True)
        print('') 

    def generate_rule(self, combination):
         rule_in_binary =  "{0:08b}".format(self.rule)
         #print(rule_in_binary)
         if (combination == ('1', '1', '1')):
             return str(rule_in_binary[0])
         elif (combination == ('1', '1', '0')):
             return str(rule_in_binary[1])
         elif (combination == ('1', '0', '1')):
             return str(rule_in_binary[2])
         elif (combination == ('1', '0', '0')):
             return str(rule_in_binary[3])
         elif (combination == ('0', '1', '1')):
             return str(rule_in_binary[4])
         elif (combination == ('0', '1', '0')):
             return str(rule_in_binary[5])
         elif (combination == ('0', '0', '1')):
             return str(rule_in_binary[6])
         elif (combination == ('0', '0', '0')):
             return str(rule_in_binary[7])


if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True, optionflags=doctest.ELLIPSIS)