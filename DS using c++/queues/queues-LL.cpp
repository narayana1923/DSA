#include <iostream>
using std::cin;
using std::cout;

typedef struct queue {
    int data;
    struct queue *next;
} Queue;
Queue *front = nullptr;
Queue *rear = nullptr;

void enqueue() {
    Queue *ptr = new Queue;
    if (ptr == NULL) {
        cout << "\nMemory is full\n";
        return;
    }
    cout << "\nEnter value to be inserted: ";
    cin >> ptr->data;
    ptr->next = nullptr;
    if (front == nullptr) {
        front = ptr;
        rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    cout << "\nValue added\n";
}
void dequeue() {
    if (front == nullptr) {
        cout << "\nQueue is empty\n";
    } else {
        Queue *prev = front;
        front = front->next;
        cout << "\n" << prev->data << " is removed from the queue\n";
        delete prev;
    }
}
void display() {
    Queue *ptr = front;
    cout << "\nQueue elements are:\n";
    int i = 0;
    while (ptr != NULL) {
        cout << "\nElement - " << i + 1 << " : " << ptr->data;
        ptr = ptr->next;
        i++;
    }
    cout << "\n";
}

void finish() {
    Queue *prev = front;
    while (front != NULL) {
        prev = front;
        front = front->next;
        delete prev;
    }
    front = nullptr;
    rear = nullptr;
}

void perform(int &option) {
    switch (option) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (front == nullptr)
                cout << "\nThere are no elements in queue\n";
            else
                display();
            break;
        case 4:
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
        cout << "\n1. Enqueue an element\n"
             << "2. Dequeue an element\n"
             << "3. Display stack\n"
             << "4. Exit\n\n";
        cout << "Select a option: ";
        cin >> option;
        perform(option);
    } while (option != 4);
}
int main() {
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~Implementation Of Queue "
            "with linked list~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    start();
    return 0;
}
