def remove_value(self, old_value):
    if self.node_value > old_value:
        if self.left_child:
            if self.left_child.node_value == old_value:
                self.left_child = None
                # Her skal den add de nodes der er under den selv
            else:
                self.left_child.remove_value(old_value)

    elif self.node_value < old_value:
        if self.right_child:
            if self.right_child.node_value == old_value:
                self.right_child = None
                # Her skal den add de nodes der er under den selv
            else:
                self.right_child.remove_value(old_value)

    elif self.node_value == old_value:
        self.node_value = None
        self.left_child = None
        self.right_child = None
        # Her skal den add de nodes der er under den selv