// Write a C++ program to construct binary search tree with n nodes and implement following
// operations
// a. Insert a node b. all traversals(recursive and nonrecursive) c. delete a node

#include <iostream>
#include <stack>
using namespace std;

// BST Node
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

// Find minimum value node (for deletion)
Node* minValue(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Delete a node
Node* deleteNode(Node* root, int val) {
    if (!root) return nullptr;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // Case 1 & 2: One or no child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Recursive traversals
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

// Non-recursive inorder
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

    cout << "\nInorder (recursive): ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nInorder (non-recursive): ";
    inorderIterative(root);

    cout << "\n\nEnter a value to delete: ";
    cin >> val;
    root = deleteNode(root, val);

    cout << "\nAfter deletion:\n";
    cout << "Inorder (recursive): ";
    inorder(root);
    cout << "\nInorder (non-recursive): ";
    inorderIterative(root);
    cout << endl;

    return 0;
}
