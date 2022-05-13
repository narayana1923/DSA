class Stack:
    def __init__(self):
        self.top = -1
        self.size = 10
        self.stack = list(range(self.size))

    def push(
        self,
    ):
        if self.top == self.size - 1:
            print("Stack is full\n")
        else:
            self.top += 1
            self.stack[self.top] = int(input("Enter value: "))
            print("Successfully pushed the element\n")

    def pop(self):
        self.top -= 1
        return self.stack[self.top + 1]

    def palindrome(self):
        if self.top == -1:
            print("Stack is full")
            return
        stack2 = Stack()
        stack2.stack = self.stack.copy()
        stack2.top = self.top
        x = 0
        for i in range(0, stack2.top + 1):
            if stack2.stack[i] != stack2.pop():
                x = 1
                break
        if x == 0:
            print("Stack is plaindrome\n")
        else:
            print("Stack is not a palindrome\n")

    def display(self):
        if self.top == -1:
            print("stack is empty\n")
        else:
            print("stack elements are: ", end=" ")
            for i in range(self.top, -1, -1):
                print(self.stack[i], end=" ")
            print()

    def perform(self, option):
        if option not in range(1, 6):
            print("Enter a valid option\n")
        else:
            if option == 1:
                self.push()
            elif option == 2:
                if self.top == -1:
                    print("stack is empty\n")
                else:
                    print(self.pop(), "is removed from stack")
            elif option == 3:
                self.palindrome()
            elif option == 4:
                self.display()
            elif option == 5:
                print("==========Program ends=============")

    def start(self):
        while True:
            print(
                "1.Push an Element on to Stack\n"
                + "2.Pop an Element from Stack\n"
                + "3.check Palindrome\n"
                + "4.Display the elements of a Stack\n"
                + "5.Exit\n\n"
            )
            option = int(input("Enter your option : "))
            self.perform(option)
            if option == 5:
                break


if __name__ == "__main__":
    print("===============Program starts===============\n")
    s = Stack()
    s.start()
