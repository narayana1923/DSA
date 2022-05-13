#include <iostream>
using namespace std;

typedef struct node {
    struct node *lchild, *rchild;
    int data;
    node(int data, struct node *lchild = nullptr,
         struct node *rchild = nullptr)
        : data(data), lchild(lchild), rchild(rchild) {}
} Node;

class BinarySearchTree {
   public:
    int size, *elements;
    Node *root;
    void freemem(Node *temp) {
        if (temp == nullptr) return;
        freemem(temp->lchild);
        freemem(temp->rchild);
        delete temp;
    }
    void findElement(int elem, Node *temp, Node *prev) {
        if (temp->data == elem)
            deleteElem(elem, temp, prev);
        else if (temp->data != elem && temp->lchild == nullptr &&
                 temp->rchild == nullptr)
            cout << "\nElement not found";
        else if (temp->data < elem)
            findElement(elem, temp->rchild, temp);
        else if (temp->data > elem)
            findElement(elem, temp->lchild, temp);
    }

    void createBST() {
        cout << "Enter number of elements of binary search tree: ";
        cin >> size;
        elements = new int[size];
        cout << "Enter BST elements seperated by space: ";
        for (int i = 0; i < size; i++) cin >> elements[i];
        root = new Node(elements[0]);
        for (int i = 1; i < size; i++) insert(elements[i], root);
        delete[] elements;
        cout << "\nSuccessfully created binary search tree with the "
                "given elements";
    }

    void insert(int elem, Node *temp) {
        if (temp->data > elem) {
            if (temp->lchild == nullptr)
                temp->lchild = new Node(elem);
            else
                insert(elem, temp->lchild);
        } else if (temp->data < elem) {
            if (temp->rchild == nullptr)
                temp->rchild = new Node(elem);
            else
                insert(elem, temp->rchild);
        } else {
            cout << "\nElement already exists!!!!";
            return;
        }
    }

    int findMin(Node *temp) {
        int min;
        Node *prev = temp;
        temp = temp->rchild;
        while (temp->lchild != nullptr) {
            prev = temp;
            temp = temp->lchild;
        }
        min = temp->data;
        if (temp->rchild != nullptr) {
            prev->rchild = temp->rchild;
            delete temp;
        } else {
            if (temp == prev->lchild)
                prev->lchild = nullptr;
            else if (temp == prev->rchild)
                prev->rchild = nullptr;
            delete temp;
        }
        return min;
    }

    void deleteElem(int elem, Node *temp, Node *prev) {
        if (temp->lchild == nullptr && temp->rchild == nullptr &&
            temp->data == elem) {
            if (prev->rchild == temp)
                prev->rchild = nullptr;
            else if (prev->lchild == temp)
                prev->lchild = nullptr;
            delete temp;
        } else if (temp->data == elem) {
            if (temp->lchild != nullptr && temp->rchild != nullptr) {
                temp->data = findMin(temp);
                return;
            }
            if (prev == root) {
                if (prev->lchild == nullptr)
                    root = root->rchild;
                else if (prev->rchild == nullptr)
                    root = root->lchild;
                delete prev;
            } else {
                if (temp->rchild == nullptr &&
                    temp->lchild != nullptr) {
                    (prev->lchild == temp)
                        ? prev->lchild = temp->lchild
                        : prev->rchild = temp->lchild;
                } else if (temp->lchild == nullptr &&
                           temp->rchild == nullptr) {
                    (prev->lchild == temp)
                        ? prev->lchild = temp->rchild
                        : prev->rchild = temp->rchild;
                }
                delete temp;
            }
        }
        cout << "\nDeleted successfully";
    }

    void inorder(Node *temp) {
        if (temp == nullptr) return;
        inorder(temp->lchild);
        cout << temp->data << " --> ";
        inorder(temp->rchild);
    }

    void preorder(Node *temp) {
        if (temp == nullptr) return;
        cout << temp->data << " --> ";
        preorder(temp->lchild);
        preorder(temp->rchild);
    }

    void postorder(Node *temp) {
        if (temp == nullptr) return;
        postorder(temp->lchild);
        postorder(temp->rchild);
        cout << temp->data << " --> ";
    }

    void operations(int &option) {
        if (option == 1)
            createBST();
        else if (option == 2 || option == 3) {
            int elem;
            cout << "Enter the element: ";
            cin >> elem;
            if (option == 2) {
                if (root == nullptr) {
                    root = new Node(elem);
                    cout << "\nElement successfully inserted\n";
                } else
                    insert(elem, root);
            } else {
                if (root == nullptr)
                    cout << "\nBST is already empty!!!\n";
                else if (root->lchild == nullptr &&
                         root->rchild == nullptr) {
                    if (root->data == elem) {
                        delete root;
                        root = nullptr;
                        cout << "\nElement successfully deleted and "
                                "BST is empty now\n";
                    } else
                        cout << "\nELement not found\n";
                } else
                    findElement(elem, root, root);
            }
        } else if (option == 4 || option == 5 || option == 6) {
            if (root == nullptr)
                cout << "\nBST is empty!!\n";
            else if (option == 4)
                inorder(root);
            else if (option == 5)
                preorder(root);
            else if (option == 6)
                postorder(root);
        } else if (option == 7) {
            freemem(root);
            cout << "\n\n------------------Program "
                    "ends------------------\n";
        } else
            cout << "\nInvalid option!!! Try again\n";
    }

    void todo() {
        int option = 0;
        do {
            cout << "\n1. Create binary search tree\n2. Insert an "
                    "element into a binary search tree\n"
                 << "3. Delete an element from binary search "
                    "tree\n4. Inorder traversal\n"
                 << "5. Preorder traversal\n6. post order "
                    "traversal\n7. Exit\n";
            cout << "\nEnter your option: ";
            cin >> option;
            operations(option);
        } while (option != 7);
    }
};

int main() {
    BinarySearchTree l;
    cout << "\n\n----------------------Binary Search Tree "
            "implementation using dynamic memory "
            "allocation----------------------\n\n";
    l.todo();
    return 0;
}
