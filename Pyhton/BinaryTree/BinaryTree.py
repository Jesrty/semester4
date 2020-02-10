a = [2, 5, 3, 1, 4, 2]


class Node:
    b = []

    def __init__(self, node_value):
        self.node_value = node_value
        self.right_child = None
        self.left_child = None

    def return_b(self):
        return self.b

    def insert(self, new_node_value):
        if self.node_value:
            if new_node_value <= self.node_value:
                if self.left_child is None:
                    self.left_child = Node(new_node_value)
                else:
                    self.left_child.insert(new_node_value)
            elif new_node_value > self.node_value:
                if self.right_child is None:
                    self.right_child = Node(new_node_value)
                else:
                    self.right_child.insert(new_node_value)
        else:
            self.node_value = new_node_value

    def remove_value(self, old_value):
        if self.node_value == old_value:
            self.node_value = None
            self.left_child = None
            self.right_child = None

    def list_print(self):
        if self.left_child:
            self.left_child.list_print()
        print(self.node_value)
        if self.right_child:
            self.right_child.list_print()

    def add_list(self):
        if self.left_child:
            self.left_child.add_list()
        self.b.append(self.node_value)
        if self.right_child:
            self.right_child.add_list()


tree = Node(None)
for x in a:
    tree.insert(x)

tree.remove_value(2)
tree.insert(4)
tree.add_list()

print(tree.return_b())
c = []
print(c)


'''
tree.insert(5)
tree.insert(3)
tree.insert(1)
tree.insert(4)
tree.insert(2)

tree.list_print()
'''







