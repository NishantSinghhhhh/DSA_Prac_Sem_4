// Write a C++ program to inorder threaded binary search tree with n nodes and implement
// following operations 1.Insert a new node 2. Inorder traversal 

#include <iostream>
#include <stack>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
    Node* root;

public:
    BST() : root(nullptr) {}

    Node* getRoot() {
        return root;
    }

    // Insert a node into BST
    Node* insert(Node* node, int val) {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // Recursive Inorder Traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Recursive Preorder Traversal
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Recursive Postorder Traversal
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Non-recursive Inorder Traversal
    void inorderNonRecursive(Node* node) {
        stack<Node*> s;
        Node* curr = node;

        while (curr != nullptr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void displayTraversals() {
        cout << "\nRecursive Inorder: ";
        inorder(root);
        cout << "\nRecursive Preorder: ";
        preorder(root);
        cout << "\nRecursive Postorder: ";
        postorder(root);
        cout << "\nNon-Recursive Inorder: ";
        inorderNonRecursive(root);
        cout << endl;
    }

    // Check if two BSTs are equal
    static bool isEqual(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return (a->data == b->data) &&
               isEqual(a->left, b->left) &&
               isEqual(a->right, b->right);
    }
};

int main() {
    BST tree1, tree2;
    int n, val;

    cout << "Enter number of nodes in Tree 1: ";
    cin >> n;
    cout << "Enter values for Tree 1:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree1.insert(val);
    }

    cout << "Enter number of nodes in Tree 2: ";
    cin >> n;
    cout << "Enter values for Tree 2:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree2.insert(val);
    }

    cout << "\n--- Tree 1 Traversals ---";
    tree1.displayTraversals();

    cout << "\n--- Tree 2 Traversals ---";
    tree2.displayTraversals();

    cout << "\n\nAre both trees equal? ";
    if (BST::isEqual(tree1.getRoot(), tree2.getRoot()))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

// Enter number of nodes in Tree 1: 5
// 10 5 20 3 7

// Enter number of nodes in Tree 2: 5
// 10 5 20 3 7
