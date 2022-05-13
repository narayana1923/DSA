#include <iostream>
using std::cin;
using std::cout;
typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;
Stack *head = nullptr;

void push() {
    Stack *node = new Stack;
    if (node == NULL) {
        cout << "\nMemory is full !!!\n";
        return;
    }
    cout << "\nEnter value to be inserted : ";
    cin >> node->data;
    node->next = nullptr;
    if (head == nullptr) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
    cout << "\nValue pushed\n";
}

void peek() {
    if (head == nullptr) {
        cout << "\nStack is empty\n";
        return;
    }
    cout << "\n" << head->data << "is present at the end of stack\n";
}

void pop() {
    if (head == nullptr) {
        cout << "\nStack is empty\n";
    } else {
        int val = head->data;
        Stack *prev = head;
        head = head->next;
        delete prev;
        cout << "\n" << val << " is removed from the stack\n";
    }
}

void display() {
    cout << "\nStack elements are: \n";
    int i = 0;
    Stack *ptr = head;
    while (ptr != NULL) {
        cout << "Element - " << i + 1 << " : " << ptr->data << "\n";
        ptr = ptr->next;
        i++;
    }
    cout << "\n";
}

void finish() {
    Stack *prev = head;
    while (head != NULL) {
        prev = head;
        head = head->next;
        delete prev;
    }
    head = nullptr;
}

void perform(int &option) {
    switch (option) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (head == nullptr)
                cout << "\nThere are no elements to diaplay in "
                        "stack\n";
            else
                display();
            break;
        case 5:
            finish();
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~Program "
                    "ends~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        default:
            break;
    }
}
void start() {
    int option;
    do {
        cout << "\n1. Push an element\n"
             << "2. pop an element\n"
             << "3. peek at top of stack\n"
             << "4. Display stack\n"
             << "5. Exit\n\n";
        cout << "Select a option: ";
        cin >> option;
        perform(option);
    } while (option != 5);
}
int main() {
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~Implementation Of Stack "
            "with linked list~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    start();
    return 0;
}
