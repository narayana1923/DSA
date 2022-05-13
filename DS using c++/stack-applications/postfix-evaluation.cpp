#include <cmath>
#include <iomanip>
#include <iostream>
#define MAX_SIZE 100
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Stack {
   private:
    double stack[MAX_SIZE];
    int top = -1;

   public:
    double pop() {
        if (top != -1)
            return stack[top--];
        else
            return '#';
    }
    void push(double j) {
        top++;
        stack[top] = j;
    }
    char peek() {
        return stack[top];
    }
    void postfix_evaluvation(string &);
    bool is_operator(char &);
};

bool Stack::is_operator(char &ch) {
    return ch == '+' || ch == '*' || ch == '-' || ch == '^' ||
           ch == '/';
}

void Stack::postfix_evaluvation(string &postfix) {
    int postfix_value = 0;
    for (char i : postfix) {
        if (!is_operator(i) && !isdigit(i)) {
            cout << "Invalid Expression!!!";
            return;
        } else if (isdigit(i)) {
            push(i - '0');
        } else if (is_operator(i)) {
            double operand2 = pop();
            double operand1 = pop();
            switch (i) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '^':
                    push(pow(operand1, operand2));
                    break;
            }
        }
    }
    cout << "postfix value is " << std::setprecision(2) << (int)peek()
         << endl;
}

int main() {
    string postfix;
    cout << "Enter postfix expression to evaluate: ";
    getline(cin, postfix);
    Stack s;
    s.postfix_evaluvation(postfix);
    return 0;
}
