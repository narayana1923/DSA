#include <iostream>
#define MAX_SIZE 200
using std::cin;
using std::cout;
using std::string;

class Stack {
   private:
    char stack[MAX_SIZE];
    int top = -1;
    string postfix;

   public:
    char pop() {
        return stack[top--];
    }
    void push(char j) {
        top++;
        stack[top] = j;
    }
    char peek() {
        return stack[top];
    }
    string infix_to_postfix(string &);
    int precedence(char &);
    bool is_operand(char &);
};
bool Stack::is_operand(char &ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Stack::precedence(char &operate) {
    if (operate == '^')
        return 3;
    else if (operate == '*' || operate == '/')
        return 2;
    else if (operate == '+' || operate == '-')
        return 1;
    return 0;
}

string Stack::infix_to_postfix(string &infix) {
    int k = -1;
    for (int i = 0, k = -1; i < infix.length(); i++) {
        if (is_operand(infix[i]) || isdigit(infix[i])) {
            postfix.push_back(infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && peek() != '(') {
                postfix.push_back(pop());
            }
            if (top != -1) pop();
        } else {
            while (top != -1 &&
                   precedence(infix[i]) <= precedence(stack[top]))
                postfix.push_back(pop());
            push(infix[i]);
        }
    }
    while (top != -1 && peek() != '(') postfix.push_back(pop());
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix Expression: ";
    getline(cin, infix);
    Stack stack;
    cout << "Postfix expression is " << stack.infix_to_postfix(infix)
         << std::endl;
    return 0;
}
