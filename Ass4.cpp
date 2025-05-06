// Write a C++ program to construct binary search tree with n nodes and implement the following
// operations
// a. Insert a node b. all traversals and nonrecursive inorder c. find the height of a tree. d. find
// mirror image of a tree

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

// Recursive Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Non-recursive inorder traversal
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

// Height of the tree
int height(Node* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// Mirror the tree
void mirror(Node* root) {
    if (!root) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
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

    // Traversals
    cout << "\nRecursive Inorder: "; inorder(root);
    cout << "\nRecursive Preorder: "; preorder(root);
    cout << "\nRecursive Postorder: "; postorder(root);
    cout << "\nNon-recursive Inorder: "; inorderIterative(root);

    // Height
    cout << "\n\nHeight of the tree: " << height(root);

    // Mirror
    mirror(root);
    cout << "\n\nInorder after mirroring: "; inorder(root);
    cout << endl;

    return 0;
}
