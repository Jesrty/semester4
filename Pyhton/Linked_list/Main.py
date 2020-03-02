class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, data_in):
        new_node = Node(data_in)
        new_node.next = self.head
        self.head = new_node

    def print_list(self):
        print_node = self.head
        while print_node:
            print(print_node.data),
            print_node = print_node.next


my_list = LinkedList()
my_list.add(2)
my_list.add(3)
my_list.add(1)
my_list.add(4)
my_list.print_list()
