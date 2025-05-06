// Write a C++ program to construct a binary search tree with n nodes and implement the following
// operations
// a. Insert a node b. all traversals and nonrecursive inorder c. Create a clone of a tree and
// then erase all nodes in the original tree.

#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Recursive Inorder
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive Preorder
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive Postorder
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Non-recursive Inorder
void inorderIterative(Node* root) {
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
}

// Clone tree
Node* clone(Node* root) {
    if (!root) return nullptr;
    Node* newNode = new Node(root->data);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}

// Delete tree
void deleteTree(Node*& root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nRecursive Inorder: ";
    inorder(root);
    cout << "\nRecursive Preorder: ";
    preorder(root);
    cout << "\nRecursive Postorder: ";
    postorder(root);
    cout << "\nNon-recursive Inorder: ";
    inorderIterative(root);

    // Clone and delete
    Node* clonedRoot = clone(root);
    deleteTree(root);
    cout << "\n\nOriginal tree deleted.";

    cout << "\nCloned Tree Inorder: ";
    inorder(clonedRoot);
    cout << endl;

    deleteTree(clonedRoot);
    return 0;
}
