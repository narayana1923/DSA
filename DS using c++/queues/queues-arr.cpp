#include <ios>
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
#define MAX_SiZE 10
class Queue {
   private:
    int front = -1, rear = -1;
    int queue[MAX_SiZE];

   public:
    void enqueue() {
        if (front == -1 && rear == -1) {
            front = 0, rear = 0;
        } else if ((rear + 1) % MAX_SiZE == front) {
            cout << "\nQueue is full, cannot enqueue elements!!!\n";
            return;
        } else if (rear == MAX_SiZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SiZE;
        }
        cout << "\nEnter value to be inserted into the queue : ";
        cin >> queue[rear];
    }
    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "\nQueue is already empty!!!\n";
            return;
        }
        int dequeued_valued = queue[front];
        cout << "\n" << dequeued_valued << " removed from queue\n";
        if (front == MAX_SiZE - 1)
            front = 0;
        else if (front == rear) {
            front = -1, rear = -1;
        } else
            front++;
    }
    void display() {
        if (front == -1 && front == rear) {
            cout << "\nThere are no elements in queue to display\n";
        } else {
            cout << "\nQueue elements are: \n";
            int i = 0, j = front;
            while (true) {
                cout << "\nElement - " << i + 1 << " : " << queue[j];
                i++;
                if (j == rear)
                    break;
                else if (MAX_SiZE - 1 == j)
                    j = 0;
                else
                    j++;
            }
            cout << "\n";
        }
    }
};

void perform_operation(Queue &q, int &option) {
    switch (option) {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "\n----------Program ends----------\n";
            break;
        default:
            cout << "\nSelect a valid option\n";
    }
}

void start_operation(Queue &q) {
    int option;
    do {
        cout << "\n1. Enqueue an Element on to Queue"
             << "\n2. Dequeue an Element from Queue"
             << "\n3. Display the elements of a Queue"
             << "\n4. Exit\n";
        cout << "\nSelect a option from above: ";
        cin >> option;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        perform_operation(q, option);
    } while (option != 4);
}
int main() {
    std::ios::sync_with_stdio(false);
    cout << "\n----------Implementation Of Queues------------\n";
    Queue q;
    start_operation(q);
    return 0;
}
