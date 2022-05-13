class Node:
    def __init__(self):
        self.data = 0
        self.next = None


class Stack:
    def __init__(self):
        self.head = None

    def push(self):
        node = Node()
        if node is None:
            print("Memory is full !!!\n")
            return
        node.data = int(input("Enter value to be inserted : "))
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node
        print("Value pushed\n")

    def peek(self):
        if self.head is None:
            print("Stack is empty\n")
            return
        print(self.head.data, "is present at the end of stack\n")

    def pop(self):
        if self.head is None:
            print("\nStack is empty\n")
        else:
            val = self.head.data
            self.head = self.head.next
            print(val, " is removed from the stack\n")

    def display(self):
        if self.head is None:
            print("Stack is empty\n")
            return
        print("\nStack elements are: \n")
        i = 0
        ptr = self.head
        while ptr:
            print("Element - ", i + 1, " : ", ptr.data, "\n")
            ptr = ptr.next
            i += 1
        print()

    def perform(self, option):
        if option not in range(1, 6):
            print("Enter a valid option\n")
        else:
            if option == 1:
                self.push()
            elif option == 2:
                self.pop()
            elif option == 3:
                self.peek()
            elif option == 4:
                self.display()
            elif option == 5:
                print("==========Program ends=============")

    def start(self):
        while True:
            print(
                "1.Push an Element on to Stack\n"
                + "2.Pop an Element from Stack\n"
                + "3.Peek at top of stack\n"
                + "4.Display the elements of a Stack\n"
                + "5.Exit\n\n"
            )
            option = int(input("Enter your option : "))
            self.perform(option)
            if option == 5:
                break


if __name__ == "__main__":
    print(
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~Implementation Of Stack with linked list~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
    )
    s = Stack()
    s.start()
