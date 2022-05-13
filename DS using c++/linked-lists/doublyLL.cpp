#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;
const char l = '\n';
class Node {
   public:
    int emp_id, emp_mobileno;
    double emp_sal;
    string emp_dept;
    Node *next, *prev;
    Node(int emp_id = 0, int emp_mobileno = 0, double emp_sal = 0.0,
         string emp_dept = "", Node *next = NULL, Node *prev = NULL)
        : emp_id(emp_id),
          emp_mobileno(emp_mobileno),
          emp_sal(emp_sal),
          emp_dept(emp_dept),
          next(next),
          prev(prev) {}
};
class LinkedList {
   public:
    Node *head = NULL;
    Node *last = NULL;
    int count = 0;
    Node *searchNode(int id) {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL) {
            if (ptr->emp_id == id) {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    Node *create() {
        int id;
        printf("Enter employee id : ");
        cin >> id;
        if (searchNode(id) != NULL) {
            cout << l << "Employee already exists in DLL" << l;
            return NULL;
        }
        Node *temp = new Node();
        temp->emp_id = id;
        cout << "Enter employee mobile no, salary separated by space "
                ": ";
        cin >> temp->emp_mobileno >> temp->emp_sal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter employee dept : ";
        cin >> temp->emp_dept;
        cout << l;
        count++;
        return temp;
    }
    void insertAtEnd() {
        Node *temp = create();
        if (temp == NULL) return;
        if (head->next == NULL) {
            last = temp;
            head->next = last;
            last->prev = head;
            return;
        }
        last->next = temp;
        temp = last;
        last = last->next;
        last->prev = temp;
    }
    void add() {
        int n, i = 1;
        cout << l << "Enter number of employees you want to add: ";
        cin >> n;
        Node *temp;
        if (head == NULL) {
            cout << "---------------Enter Employee - " << i
                 << " details---------------\n";
            temp = create();
            i++;
            head = temp;
            last = temp;
        }
        while (i <= n) {
            cout << "---------------Enter Employee - " << i
                 << " details---------------\n";
            insertAtEnd();
            i++;
        }
        cout << l << "Successfully updated the DLL" << l;
    }
    void displayDLL() {
        Node *temp = head;
        printf("\n%-10s%-15s%-13s%s\n", "Emp id", "Emp_mobileno",
               "Emp sal", "Emp dept");
        while (temp != NULL) {
            printf("%-10d%-15d%-13.2f", temp->emp_id,
                   temp->emp_mobileno, temp->emp_sal);
            cout << temp->emp_dept << l;
            temp = temp->next;
        }
        cout << l;
    }
    void del_main() {
        delete head;
        head = NULL;
        last = NULL;
    }
    void deleteaAtEnd() {
        if (last->prev != NULL) {
            last = last->prev;
            delete last->next;
            last->next = nullptr;
        } else
            del_main();
        count--;
        cout << l << "Deleted successfully" << l;
    }
    void deleteAtFront() {
        if (head->next != NULL) {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        } else
            del_main();
        count--;
        cout << l << "Deleted successfully" << l;
    }
    void insertAtFront() {
        Node *temp = create();
        if (temp == NULL) return;
        head->prev = temp;
        temp = head;
        head = head->prev;
        head->next = temp;
        cout << "\nSuccessfully updated the DLL\n";
    }
    void insert() {
        int id;
        cout << "Enter employee id after which you want to insert : ";
        cin >> id;
        Node *temp = searchNode(id);
        if (temp == NULL) {
            cout << "\nEmployee id entered doesn't exist in DLL\n";
        } else {
            Node *temp1 = create();
            if (temp1 == NULL) return;
            if (temp->next != NULL) {
                temp1->next = temp->next;
                temp->next = temp1;
                temp1->prev = temp;
                temp1->next->prev = temp1;
            } else {
                temp->next = temp1;
                temp1->prev = temp;
            }
        }
        cout << l << "Successfully updated the DLL" << l;
    }
    void delet() {
        int emp_id;
        cout << "Enter employee id you want to delete : ";
        cin >> emp_id;
        Node *temp = searchNode(emp_id);
        if (temp == NULL) {
            cout << l << "Employee id entered doesn't exist in DLL"
                 << l;
        } else {
            if (temp->next == NULL) {
                deleteaAtEnd();
            } else if (temp->prev == NULL) {
                deleteAtFront();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            count--;
            cout << l << "Deleted successfully" << l;
        }
    }
    void finish() {
        Node *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        last = nullptr;
    }
    void todo(int option) {
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                cout << l << "Total members in DLL is " << count << l;
                break;
            case 3:
                if (count == 0)
                    cout << l << "There are no employees in DLL" << l;
                else
                    displayDLL();
                break;
            case 4:
                if (count == 0)
                    cout << l << "There are no employees in DLL" << l;
                else
                    insertAtFront();
                break;
            case 5:
                if (count == 0)
                    cout << l << "There are no employees in DLL" << l;
                else
                    insertAtEnd();
                break;
            case 6:
                if (count == 0)
                    cout << l << "There are no employees in DLL" << l;
                else
                    insert();
                break;
            case 7:
                if (count == 0)
                    cout << l
                         << "There are no employees in DLL to delete"
                         << l;
                else
                    deleteAtFront();
                break;
            case 8:
                if (count == 0)
                    cout << l
                         << "There are no employees in DLL to delete"
                         << l;
                else
                    deleteaAtEnd();
                break;
            case 9:
                if (count == 0)
                    cout << l
                         << "There are no employees in DLL to delete"
                         << l;
                else
                    delet();
                break;
            case 10:
                finish();
                cout << l << l
                     << "------------------------Program "
                        "ends------------------------"
                     << l << l;
                break;
            default:
                cout << l << "Enter a valid option !!" << l;
        }
    }
    void operations() {
        int option;
        do {
            cout
                << ("\n1-> Add members\n"
                    "2->  Count of nodes in DLL\n"
                    "3->  Display Employee data in DLL\n"
                    "4->  Insert Employee at Front of the DLL\n"
                    "5->  Insert Employee at End of the DLL\n"
                    "6->  Insert Employee at a specific position in "
                    "DLL\n"
                    "7->  Delete Employee at Front of the DLL\n"
                    "8->  Delete Employee at End of the DLL\n"
                    "9->  Delete Employee at a specific position in "
                    "DLL\n"
                    "10-> Exit\n");
            cout << ("\nEnter your option: ");
            cin >> option;
            fflush(stdin);
            todo(option);
        } while (option != 10);
    }
};
int main() {
    cout << "------------------------Program "
            "starts------------------------"
         << l << l;
    LinkedList list;
    list.operations();
    return 0;
}
