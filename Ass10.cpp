// Write a C++ program to construct AVL Tree. Implement following operations.
// a.Insert b. inorder traversal c. Print height of tree
// Test your program for following example: Input : 30,31,32,23,22,28,24,29,26,27 4

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

// Utility to get height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Utility to get balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update height
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right Rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left Rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

// Insert into AVL Tree
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // No duplicates

    updateHeight(node);

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main Function
int main() {
    Node* root = nullptr;
    int values[] = {30, 31, 32, 23, 22, 28, 24, 29, 26, 27};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        root = insert(root, values[i]);
    }

    cout << "Inorder Traversal of AVL Tree: ";
    inorder(root);
    cout << "\nHeight of Tree: " << getHeight(root) << endl;

    return 0;
}
