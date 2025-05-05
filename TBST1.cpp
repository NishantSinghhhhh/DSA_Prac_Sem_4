#include <iostream>
using namespace std;

// Structure of a threaded BST Node
struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        lthread = rthread = true;
    }
};

class ThreadedBST {
    Node* root;

public:
    ThreadedBST() : root(nullptr) {}

    // Insert a new node
    void insert(int key) {
        Node* ptr = root;
        Node* parent = nullptr;

        while (ptr != nullptr) {
            if (key == ptr->data) {
                cout << "Duplicate keys not allowed.\n";
                return;
            }

            parent = ptr;

            if (key < ptr->data) {
                if (!ptr->lthread)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (!ptr->rthread)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        Node* newNode = new Node(key);

        if (parent == nullptr) {
            root = newNode;
        } else if (key < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lthread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rthread = false;
            parent->right = newNode;
        }
    }

    void inorder() {
        Node* curr = root;
        if (!curr) {
            cout << "Tree is empty.\n";
            return;
        }

        // Move to the leftmost node
        while (!curr->lthread)
            curr = curr->left;

        while (curr) {
            cout << curr->data << " ";

            // If rthread is true, go to inorder successor directly
            if (curr->rthread)
                curr = curr->right;
            else {
                curr = curr->right;
                while (curr && !curr->lthread)
                    curr = curr->left;
            }
        }
        cout << endl;
    }
};

int main() {
    ThreadedBST tbt;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tbt.insert(val);
    }

    cout << "\nInorder Traversal (Threaded): ";
    tbt.inorder();

    // Sample test case
    /*
    Sample Input:
    Enter number of nodes: 6
    Enter 6 values:
    50 30 70 20 40 60

    Expected Output:
    Inorder Traversal (Threaded): 20 30 40 50 60 70
    */

    return 0;
}
