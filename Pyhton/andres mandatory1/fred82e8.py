"""
The Cellular Automata assignment. First mandatory assignment with Advanced Python, KEA, 2020. 
by Frederik Lundbeck Jørgensen.

https://github.com/Fliipzy 

After-thoughts: 
I think the assignment turned out alright, though quite hacky some places. Given more time I 
would've liked to try and refactor some of the algorithms.


"""

class CellularUtils:
    """Provides static utility functions for the Cellular Automaton class"""

    def print_cell_map(map, fill_char):
        """Takes in a cell map and prints it neatly to the output stream"""
        height = len(map)
        width = len(map[0])

        for y in range(height):
            line = ""
            map_slice = map[y]
            for x in range(width):
                line += (" " if map_slice[x] == 0 else fill_char)
            print(line)


class CellularAutomaton:
    """This class contains functions to generate cellular automata maps."""

    def __init__(self):
        self.length = None
        self.rule = None

    def __get_state_from_neighbours(self, left, center, right):
        """This function applies the ruleset to the 3 passed in states, and returns the result (0 or 1)"""

        state = None

        #[1][1][1]
        if (left == 1 and center == 1 and right == 1):
            state = self.rule[0]
        #[1][1][0]
        elif (left == 1 and center == 1 and right == 0):
            state = self.rule[1]
        #[1][0][1]
        elif (left == 1 and center == 0 and right == 1):
            state = self.rule[2]
        #[1][0][0]
        elif (left == 1 and center == 0 and right == 0):
            state = self.rule[3]
        #[0][1][1]
        elif (left == 0 and center == 1 and right == 1):
            state = self.rule[4]
        #[0][1][0]
        elif (left == 0 and center == 1 and right == 0):
            state = self.rule[5]
        #[0][0][1]
        elif (left == 0 and center == 0 and right == 1):
            state = self.rule[6]
        #[0][0][0], if program pointer reaches this, it must be this state.
        else:
            state = self.rule[7]
        
        return state
        

    def __generate_next_state(self, prev_state):
        """Returns a new state generated from the previous state."""
        
        new_state = []

        #Iterate through the previous state and find it's neighbours values
        for cell_index in range(self.length):

            #Find current cell's upper left & right neighbour indexes. If current cell's x is 0 or self.length, we wrap around.
            #[left] [center ] [right]   <-- upper neighbours
            #[    ] [current] [     ]   <-- current cell 
            left_index = cell_index - 1 if cell_index > 0 else self.length - 1
            right_index = cell_index + 1 if cell_index < self.length - 1 else 0

            #Find the current cell's state by passing in it's upper neighbours into the __get_state_from_neighbours function.
            #Append the returned cell state to the new_state list.
            new_state.append(self.__get_state_from_neighbours( prev_state[left_index], prev_state[cell_index], prev_state[right_index] ))
        
        return new_state


    def generate_cell_map(self, height, rule, initial_state):
        """Generates and returns a cellular map with the applied rule and initial state."""

        #Start by assigning the length of initial_state to the instance variable length. Next assign the rule -
        #instance variable to the given rule parameter.
        self.length = len(initial_state)

        #Quite hacky but manages to clamp rule between 0-255 and convert it to a binary string
        self.rule = "{:08b}".format(max(0, min(rule, 255)))

        #Not happy with the following code, but if I don't convert the rule string to an integer list
        #there will be problems later, when trying to match neighbour states (ints) to the ruleset (chars).
        temp = []
        for char in self.rule:
            temp.append(int(char))

        self.rule = temp 

        #Declare and assign a new list with intial_state. This list will hold all the states/slices of our cellular map.
        cell_map = [initial_state]

        #Iterate this loop height amount of times and populate cell_map with slices.
        new_state = initial_state

        for i in range(height):
            #Assign the previous state with the old new state, so we don't lose data in the next step.
            prev_state = new_state
            new_state = self.__generate_next_state(prev_state)
            

            #Append the generated new state to the cell map.
            cell_map.append(new_state)

        #Once we've iterated the loop our map should be done. Now we return it.
        return cell_map 
            

#Declare and initialize a CellularAutomaton object
cellular_automata = CellularAutomaton()

#Will repeat the contents of initial_state 32 times = 32 zeros.  
initial_state = [0] * 32

#Assign the middle index to 1.
initial_state[int(len(initial_state) / 2)] = 1

#Declare and initialize cell_map by using the generate_cell_map function from the CellularAutomaton object.
cell_map = cellular_automata.generate_cell_map(10, 54, initial_state)

CellularUtils.print_cell_map(cell_map, '█')



if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True, optionflags=doctest.ELLIPSIS)