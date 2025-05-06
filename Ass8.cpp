// Write a program to convert given binary search tree into inorder threaded binary search tree and
// its inorder traversal

#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
    bool lthread;
    bool rthread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        lthread = rthread = false;
    }
};

// Standard BST insertion
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    return root;
}

// Convert BST to Inorder Threaded BST
void createThreaded(Node* root, Node*& prev) {
    if (!root) return;

    createThreaded(root->left, prev);

    if (!root->left) {
        root->left = prev;
        root->lthread = true;
    }

    if (prev && !prev->right) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    createThreaded(root->right, prev);
}

// Find the leftmost node
Node* leftmost(Node* root) {
    while (root && !root->lthread)
        root = root->left;
    return root;
}

// Inorder traversal using threads
void inorderThreaded(Node* root) {
    Node* curr = leftmost(root);
    while (curr) {
        cout << curr->data << " ";

        if (curr->rthread)
            curr = curr->right;
        else
            curr = leftmost(curr->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insertBST(root, val);
    }

    // Convert to threaded BST
    Node* prev = nullptr;
    createThreaded(root, prev);

    cout << "\nInorder Traversal (Threaded): ";
    inorderThreaded(root);

    /*
    Sample Test Case:
    Input:
    Enter number of nodes: 6
    Enter 6 values:
    50 30 70 20 40 60

    Output:
    Inorder Traversal (Threaded): 20 30 40 50 60 70
    */

    return 0;
}
