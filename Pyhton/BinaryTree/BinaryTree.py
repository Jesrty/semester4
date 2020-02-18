a = [2, 5, 3, 1, 4, 2]
c = [50, 100, 125, 75, 60, 80, 55, 70, 75, 90, 25, 20, 30, 15, 22, 27, 30]


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
            if new_node_value < self.node_value:
                if self.left_child is None:
                    self.left_child = Node(new_node_value)
                else:
                    self.left_child.insert(new_node_value)
            elif new_node_value >= self.node_value:
                if self.right_child is None:
                    self.right_child = Node(new_node_value)
                else:
                    self.right_child.insert(new_node_value)
        else:
            self.node_value = new_node_value

    def insert_more_test(self, new_node):
        self.insert(new_node.node_value)
        if new_node.left_child is not None:
            self.insert_more_test(new_node.left_child)
        if new_node.right_child is not None:
            self.insert_more_test(new_node.right_child)

    def remove_value(self, old_value):
        if self.node_value > old_value:
            if self.left_child:
                if self.left_child.node_value == old_value:
                    if self.left_child.right_child:
                        test = None
                        if self.left_child.left_child:
                            test = self.left_child.left_child
                        self.left_child = self.left_child.right_child
                        if test is not None:
                            self.insert_more_test(test)
                    elif self.left_child.left_child:
                        self.left_child = self.left_child.left_child
                    else:
                        self.left_child = None
                else:
                    self.left_child.remove_value(old_value)

        elif self.node_value < old_value:
            if self.right_child:
                if self.right_child.node_value == old_value:
                    if self.right_child.right_child:
                        test = None
                        if self.right_child.left_child:
                            test = self.right_child.left_child
                        self.right_child = self.right_child.right_child
                        if test is not None:
                            self.insert_more_test(test)
                    elif self.right_child.left_child:
                        self.right_child = self.right_child.left_child
                    else:
                        self.right_child = None
                    # Her skal den add de nodes der er under den selv
                else:
                    self.right_child.remove_value(old_value)

        elif self.node_value == old_value:
            if self.right_child:
                test1 = self.right_child
                test2 = None
                if self.left_child:
                    test2 = self.left_child
                self.node_value = None
                self.left_child = None
                self.right_child = None
                self.insert_more_test(test1)
                if test2:
                    self.insert_more_test(test2)

            elif self.left_child:
                test1 = self.left_child
                self.node_value = None
                self.left_child = None
                self.right_child = None
                self.insert_more_test(test1)
            else:
                self.node_value = None
                self.left_child = None
                self.right_child = None
            # Her skal den add de nodes der er under den selv

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
for x in c:
    tree.insert(x)


tree.remove_value(50)

tree.add_list()
print(tree.return_b())

print("")

c.sort()
print(c)








