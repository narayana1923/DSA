#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;

const char line = '\n';

class Node {
   public:
    string name;
    string rollnumber;
    Node *next;
    Node(string name = "", string rollnumber = "",
         Node *next = NULL) {
        this->name = name;
        this->rollnumber = rollnumber;
        this->next = next;
    }
};

class Linked_List {
   public:
    Node *head /*=new Node()*/;
    Node *first /*=new Node()*/;
    Node *last /*=new Node()*/;
    void intialization_of_heads() {
        string name, rollnumber;
        cout << "Enter the name of the readers club head : ";
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        cout << "Enter the roll number of the readers club head : ";
        getline(cin, rollnumber);
        transform(rollnumber.begin(), rollnumber.end(),
                  rollnumber.begin(), ::toupper);
        first = new Node(name, rollnumber);
        cout << "Enter the name of the in-charge of readers club : ";
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        cout << "Enter the roll number of the in-charge of readers "
                "club : ";
        getline(cin, rollnumber);
        transform(rollnumber.begin(), rollnumber.end(),
                  rollnumber.begin(), ::toupper);
        last = new Node(name, rollnumber);
        first->next = last;
        head = first;
    }

    Node *searchNode(string rollnumber) {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL) {
            if (ptr->rollnumber == rollnumber) {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void add() {
        string rollnumber;
        getline(cin, rollnumber);
        cout << "Enter the roll number of person : ";
        getline(cin, rollnumber);
        transform(rollnumber.begin(), rollnumber.end(),
                  rollnumber.begin(), ::toupper);
        if (searchNode(rollnumber) != NULL) {
            cout
                << "\nStudent is already present in readers club\n\n";
        } else {
            string name;
            cout << "Enter the name of person : ";
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(),
                      ::toupper);
            if (head == NULL) {
                first->name = name;
                first->rollnumber = rollnumber;
                head = first;
                head->next = NULL;
                cout << "\nSuccessfully added the student to readers "
                        "club\n";
                return;
            }
            if (head->next == NULL) {
                last = new Node(name, rollnumber);
                head->next = last;
                cout << "\nSuccessfully added the student to readers "
                        "club\n";
                return;
            }
            Node *temp = head;
            while (temp->next != last) temp = temp->next;
            temp->next = new Node(name, rollnumber, last);
            cout << "\nSuccessfully added the students to readers "
                    "club\n";
        }
    }

    int total_members() {
        int n = 0;
        Node *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }
        return n;
    }

    void sort() {
        string a;
        string b;
        Node *temp = head;
        while (temp->next != NULL) {
            Node *min = temp;
            Node *temp1 = temp->next;
            while (temp1 != NULL) {
                if (temp1->name < min->name) {
                    min = temp1;
                }
                temp1 = temp1->next;
            }
            swap(min->name, temp->name);
            swap(min->rollnumber, temp->rollnumber);
            temp = temp->next;
        }
    }

    void delet() {
        if (total_members() == 0) {
            cout << "\nThere are no members in readers club\n";
        } else {
            string rollnumber;
            getline(cin, rollnumber);
            cout << "Enter the roll number of student you want to "
                    "delete: ";
            getline(cin, rollnumber);
            transform(rollnumber.begin(), rollnumber.end(),
                      rollnumber.begin(), ::toupper);
            if (searchNode(rollnumber) == NULL) {
                cout << "\nThere is no one in the readers club with "
                        "the roll number "
                     << rollnumber << "\n";
                return;
            }
            sort();
            if (head->rollnumber == rollnumber) {
                head = head->next;
                /*last=NULL;*/
                delete last;
                cout << "\nThe student you entered has been removed "
                        "form readers club\n";
                return;
            }
            Node *temp = head;
            Node *prev = temp;
            while (temp->next != NULL &&
                   temp->rollnumber != rollnumber) {
                prev = temp;
                temp = temp->next;
                if (temp->rollnumber > rollnumber) break;
            }
            if (temp->rollnumber == rollnumber) {
                prev->next = temp->next;
                temp->next = NULL;
                delete temp->next;
            }
            cout << "\nThe student you entered has been removed form "
                    "readers club\n";
        }
    }

    void display_members() {
        Node *temp = head;
        printf("%-30s%s\n", "Name", "Roll Number");
        while (temp != NULL) {
            cout << temp->name << setw(30) << temp->rollnumber
                 << line;
            // printf("%-30s%s\n", temp->name, temp->rollnumber);
            temp = temp->next;
        }
        cout << line;
    }

    void display_reverse(Node *head) {
        if (head->next != NULL) {
            display_reverse(head->next);
        }
        cout << head->name << setw(30) << head->rollnumber << line;
    }

    void todo(int option) {
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                delet();
                break;
            case 3:
                cout << "\nTotal number of members in readers club "
                        "are "
                     << total_members() << "\n";
                break;
            case 4:
                if (total_members() == 0)
                    cout
                        << "\nThere are no members in readers club\n";
                else {
                    cout << "Name " << setw(30) << " Rollnumber\n\n";
                    display_members();
                }
                break;
            case 5:
                if (total_members() == 0)
                    cout
                        << "\nThere are no members in readers club\n";
                else {
                    cout << "Name " << setw(30) << " Rollnumber\n\n";
                    display_reverse(head);
                }
                cout << "\n";
                break;
            case 6:
                if (total_members() == 0)
                    cout << "\nThere are no members in readers club "
                            "to sort\n";
                else {
                    sort();
                    cout << "\nSorted the list successfully\n";
                }
                break;
            case 7:
                cout << "\nProgram ended!!\n";
                break;
            default:
                string a;
                getline(cin, a);
                cout << "\nInvalid option, please try again\n";
        }
    }

    void operation() {
        int option;
        do {
            cout
                << ("\n1-> Add a member\n"
                    "2-> Delete a members\n"
                    "3-> Count of students in readers club\n"
                    "4-> Display All members in readers club\n"
                    "5-> Display all the members in reverse order\n"
                    "6-> sort the list\n"
                    "7-> To exit Enter 7 or any number >7\n");
            cout << ("\nEnter your option: ");
            cin >> option;
            todo(option);
        } while (option != 7);
    }
};
int main() {
    Linked_List l;
    l.intialization_of_heads();
    cout << line;
    l.operation();
    return 0;
}
