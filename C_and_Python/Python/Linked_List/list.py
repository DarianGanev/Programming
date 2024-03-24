class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class MyList:
    def __init__(self):
        self.head = None

    def append(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            current_node = self.head
            while current_node.next:
                current_node = current_node.next
            current_node.next = Node(data)

    def insert(self, index, data):
        if index < 0:
            raise IndexError("Index out of range")
        if index == 0:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
        else:
            current_node = self.head
            for _ in range(index - 1):
                if current_node is None:
                    raise IndexError("Index out of range")
                current_node = current_node.next
            if current_node is None:
                raise IndexError("Index out of range")
            new_node = Node(data)
            new_node.next = current_node.next
            current_node.next = new_node

    def remove(self, data):
        current_node = self.head
        if current_node is not None:
            if current_node.data == data:
                self.head = current_node.next
                return
            while current_node.next:
                if current_node.next.data == data:
                    current_node.next = current_node.next.next
                    return
                current_node = current_node.next
        raise ValueError("Value not found in the list")

    def pop(self, index=None):
        if index is None:
            if self.head is None:
                raise IndexError("Pop from empty list")
            elif self.head.next is None:
                popped_data = self.head.data
                self.head = None
                return popped_data
            else:
                current_node = self.head
                while current_node.next.next:
                    current_node = current_node.next
                popped_data = current_node.next.data
                current_node.next = None
                return popped_data
        else:
            if index < 0:
                raise IndexError("Index out of range")
            if index == 0:
                if self.head is None:
                    raise IndexError("Index out of range")
                popped_data = self.head.data
                self.head = self.head.next
                return popped_data
            current_node = self.head
            for _ in range(index - 1):
                if current_node is None:
                    raise IndexError("Index out of range")
                current_node = current_node.next
            if current_node is None or current_node.next is None:
                raise IndexError("Index out of range")
            popped_data = current_node.next.data
            current_node.next = current_node.next.next
            return popped_data

    def clear(self):
        self.head = None

    def index(self, data):
        current_node = self.head
        index = 0
        while current_node:
            if current_node.data == data:
                return index
            current_node = current_node.next
            index += 1
        raise ValueError("Value not found in the list")

    def sort(self):
        if self.head is None:
            return
        swapped = True
        while swapped:
            swapped = False
            current_node = self.head
            while current_node.next:
                if current_node.data > current_node.next.data:
                    current_node.data, current_node.next.data = current_node.next.data, current_node.data
                    swapped = True
                current_node = current_node.next

    def reverse(self):
        prev_node = None
        current_node = self.head
        while current_node:
            next_node = current_node.next
            current_node.next = prev_node
            prev_node = current_node
            current_node = next_node
        self.head = prev_node

    def __getitem__(self, index):
        current_node = self.head
        if index < 0:
            raise IndexError("Index out of range")
        for _ in range(index):
            if current_node is None:
                raise IndexError("Index out of range")
            current_node = current_node.next
        if current_node is None:
            raise IndexError("Index out of range")
        return current_node.data

    def __setitem__(self, index, data):
        current_node = self.head
        if index < 0:
            raise IndexError("Index out of range")
        for _ in range(index):
            if current_node is None:
                raise IndexError("Index out of range")
            current_node = current_node.next
        if current_node is None:
            raise IndexError("Index out of range")
        current_node.data = data

import turtle

figures = MyList()

figures.append("circle")
figures.append("square")
figures.append("triangle")

print(figures[0])

figures[1] = "rectangle"
print(figures[1])
