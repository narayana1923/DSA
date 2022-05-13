import array as arr


class Stack:
    def __init__(self):
        self.MAXSIZE = 100
        self.stack = arr.array("u", "\0" * self.MAXSIZE)
        self.top = -1
        self.postfix = ""

    def pop(self):
        popped = self.stack[self.top]
        self.top -= 1
        return popped

    def push(self, j):
        if self.top == self.MAXSIZE - 1:
            print("stack is full")
            exit(0)
        self.top += 1
        self.stack[self.top] = j

    def peek(self):
        return self.stack[self.top]

    def isoperand(self, ch):
        return (ch >= "a" and ch <= "z") or (ch >= "A" and ch <= "Z")

    def precedence(self, operator):
        if operator == "^":
            return 3
        elif operator == "*" or operator == "/":
            return 2
        elif operator == "+" or operator == "-":
            return 1
        return 0

    def infix_to_postfix(self, infix):
        for i in range(len(infix)):
            if self.isoperand(infix[i]) or infix[i].isdigit():
                self.postfix += infix[i]
            elif infix[i] == "(":
                self.push(infix[i])
            elif infix[i] == ")":
                while self.top != -1 and self.peek() != "(":
                    self.postfix += self.pop()
                if self.top != -1:
                    self.pop()
            else:
                while self.top != -1 and self.precedence(infix[i]) <= self.precedence(
                    self.stack[self.top]
                ):
                    self.postfix += self.pop()
                self.push(infix[i])
        while self.top != -1 and self.peek() != "(":
            self.postfix += self.pop()
        return self.postfix


if __name__ == "__main__":
    infix = input("Enter infix expression : ")
    stack = Stack()
    print("Postfix expression is", stack.infix_to_postfix(infix))
