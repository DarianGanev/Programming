class Node:
    def __init__(self, data):
        self.__data = data
        self.__next = None


class MyList:
    def __init__(self, head):
        self.__head = None

    def append(self, data):
        if self.__head is None:
            self.__head = Node(data)
        else:
            current_node = self.__head
            while current_node.next:
                current_node = current_node.next
            current_node.next = Node(data)

    def insert(self, index, data):
        if self.__head is None:
            self.__head = Node(data)
        else:
            current_node = self.__head
            while current_node.next != index + 1:
                current_node = current_node.next
            current_node.next = Node(data)