#include <ios>
#include <iostream>
#include <limits>
#define MAX_SIZE 10
using std::cin;
using std::cout;
using std::endl;

class Stack {
   private:
    int top = -1;
    int stack[MAX_SIZE];

   public:
    int get_top() {
        return top;
    }
    void push();
    int pop();
    void display();
    void palindrome();
};

void Stack::push() {
    if (top + 1 == MAX_SIZE) {
        cout << "\nStack is full, Cannot insert elements!!\n";
    } else {
        cout << "\nEnter value to be inserted: ";
        cin >> stack[++top];
        cout << "\nElement successfully pushed into the stack\n";
    }
}

int Stack::pop() {
    int popped_value = stack[top];
    top--;
    return popped_value;
}

void Stack::palindrome() {
    if (top == -1) {
        cout << "\nStack is empty, palindrome operation not "
                "possible\n";
    } else {
        Stack temp_stack;
        temp_stack.top = top;
        for (int i = 0; i <= top; i++) temp_stack.stack[i] = stack[i];
        bool ispalindrome = true;
        for (int i = 0; i <= (top / 2); i++) {
            if (temp_stack.stack[i] != temp_stack.pop()) {
                ispalindrome = false;
                break;
            }
        }
        cout << "\nStack is "
             << (ispalindrome ? "palindrome" : "not palindrome")
             << "\n";
    }
}

void Stack::display() {
    if (top == -1) {
        cout << "\nThere are no elements to display in stack\n";
    } else {
        cout << "\nStack elements are:\n\n";
        for (int i = top; i >= 0; i--) {
            cout << "Element - " << i + 1 << " : " << stack[i]
                 << "\n";
        }
        cout << "\n";
    }
}

void perform_operation(Stack &s, int &option) {
    switch (option) {
        case 1:
            s.push();
            break;
        case 2:
            if (s.get_top() == -1) {
                cout << "\nStack is empty, pop is not possible!!!\n";
            } else {
                cout << "\n"
                     << s.pop() << " popped out of the stack\n";
            }
            break;
        case 3:
            s.palindrome();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "\n----------Program ends----------\n";
            break;
        default:
            cout << "\nSelect a valid option\n";
    }
}

void start_operation(Stack &s) {
    int option;
    do {
        cout << "\n1. Push an Element on to Stack"
             << "\n2. Pop an Element from Stack"
             << "\n3. Check Palindrome"
             << "\n4. Display the elements of a Stack"
             << "\n5. Exit\n";
        cout << "\nSelect a option from above: ";
        cin >> option;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        perform_operation(s, option);
    } while (option != 5);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    Stack s;
    cout << "\n-----------Implementation of Stack using "
            "array-----------\n\n";
    start_operation(s);
    return 0;
}
