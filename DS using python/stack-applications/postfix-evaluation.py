import array as arr


class Stack:
    def __init__(self):
        self.MAXSIZE = 100
        self.stack = arr.array("f", [0 for x in range(self.MAXSIZE)])
        self.top = -1
        self.postfix = ""

    def pop(self):
        if self.top != -1:
            popped = self.stack[self.top]
            self.top -= 1
            return popped
        else:
            return "#"

    def push(self, j):
        if self.top == self.MAXSIZE - 1:
            print("stack is full")
            exit(0)
        self.top += 1
        self.stack[self.top] = j

    def peek(self):
        return self.stack[self.top]

    def is_operator(self, ch):
        return ch == "+" or ch == "*" or ch == "-" or ch == "^" or ch == "/"

    def postfix_evaluation(self, postfix):
        for i in postfix:
            if not self.is_operator(i) and not i.isdigit():
                print("invalid expression")
            elif i.isdigit():
                self.push(ord(i) - 48)
            elif self.is_operator(i):
                operand2 = self.pop()
                operand1 = self.pop()
                if i == "+":
                    self.push(operand1 + operand2)
                elif i == "*":
                    self.push(operand1 * operand2)
                elif i == "/":
                    self.push(operand1 / operand2)
                elif i == "-":
                    self.push(operand1 - operand2)
                elif i == "^":
                    self.push(operand1 ** operand2)
        print("Postfix value is %.2f" % self.peek())


if __name__ == "__main__":
    postfix = input("Enter postfix expression : ")
    stack = Stack()
    stack.postfix_evaluation(postfix)
