// Write a C++ program to construct binary search tree with n nodes and implement following
// operations
// Insert a node b. all traversals and nonrecursive inorder c. Check whether two trees are equal.

#include <iostream>
#include <stack>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST Class
class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void displayRecursiveTraversals() {
        cout << "\nInorder (recursive): ";
        inorder(root);
        cout << "\nPreorder (recursive): ";
        preorder(root);
        cout << "\nPostorder (recursive): ";
        postorder(root);
        cout << endl;
    }

    void inorderIterative() {
        cout << "\nInorder (non-recursive): ";
        stack<Node*> s;
        Node* curr = root;

        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    Node* getRoot() {
        return root;
    }

    // Compare two trees
    static bool isEqual(Node* a, Node* b) {
        if (!a && !b) return true;
        if (a && b)
            return (a->data == b->data &&
                    isEqual(a->left, b->left) &&
                    isEqual(a->right, b->right));
        return false;
    }
};

int main() {
    BST tree1, tree2;
    int n, val;

    cout << "Enter number of nodes for Tree 1: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree1.insert(val);
    }

    cout << "Enter number of nodes for Tree 2: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree2.insert(val);
    }

    cout << "\n--- Tree 1 Traversals ---";
    tree1.displayRecursiveTraversals();
    tree1.inorderIterative();

    cout << "\n--- Tree 2 Traversals ---";
    tree2.displayRecursiveTraversals();
    tree2.inorderIterative();

    if (BST::isEqual(tree1.getRoot(), tree2.getRoot()))
        cout << "\n✅ The two BSTs are equal.\n";
    else
        cout << "\n❌ The two BSTs are NOT equal.\n";

    return 0;
}
