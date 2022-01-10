class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def unshift(self, data):
        if self.head == None:
            self.head = Node(data)
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

    def push(self, data):
        temp = self.head
        new_node = Node(data)
        if self.head == None:
            self.head = Node(data)
        else:
            while temp.next != None:
                temp = temp.next
            temp.next = new_node

    def length(self):
        temp = self.head
        i = 0
        while temp != None:
            i += 1
            temp = temp.next
        return i

    def find_index(self, data):
        temp = self.head
        i = 0
        while temp.data != data:
            i += 1
            temp = temp.next
        return i

    def remove(self, index):
        temp = self.head
        i = 0
        while i < index - 1:
            i += 1
            temp = temp.next

        temp.next = temp.next.next

    def print(self):
        temp = self.head
        while temp != None:
            print(temp.data)
            temp = temp.next


my_list = LinkedList()

my_list.push(1)
# print(my_list.find_index(2), "INDEX")
my_list.push(2)
# my_list.push(3)
my_list.remove(3)
print(my_list.length(), "Length")

my_list.print()
