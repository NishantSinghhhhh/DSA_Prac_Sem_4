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

// Enter number of nodes: 7  
// Enter 7 values:  
// 50 30 70 20 40 60 80

// Enter a value to delete: 30

// Let’s walk through your full C++ program, which:

// 1. **Builds a Binary Search Tree (BST)** from user input.
// 2. Supports **insertion** and **deletion**.
// 3. Implements **all traversals** (recursive & non-recursive inorder).
// 4. Handles **deletion cases** properly.

// Then we'll look at how deletion of node `30` works with your test case.

// ---

// ## ✅ 1. Code Structure Breakdown

// ### 📌 **1. BST Insertion**

// ```cpp
// Node* insert(Node* root, int val)
// ```

// * Recursively finds the correct spot for `val` and inserts it.
// * BST property: left subtree < node < right subtree.

// ---

// ### 📌 **2. BST Deletion**

// ```cpp
// Node* deleteNode(Node* root, int val)
// ```

// Handles 3 cases:

// 1. **Node has no child** (leaf) → delete directly.
// 2. **Node has one child** → bypass the node.
// 3. **Node has two children**:

//    * Replace node with its **inorder successor** (smallest node in right subtree).
//    * Delete that successor recursively.

// ```cpp
// Node* minValue(Node* node)
// ```

// Finds the minimum value in a given subtree (leftmost node).

// ---

// ### 📌 **3. Traversals**

// | Function           | Type          | Order                           |
// | ------------------ | ------------- | ------------------------------- |
// | `inorder`          | Recursive     | Left → Root → Right             |
// | `preorder`         | Recursive     | Root → Left → Right             |
// | `postorder`        | Recursive     | Left → Right → Root             |
// | `inorderIterative` | Non-recursive | Left → Root → Right using stack |

// ---

// ### 📌 **4. User Input Flow**

// * Reads `n` nodes.
// * Inserts them one by one.
// * Performs all traversals.
// * Asks for a value to delete.
// * Performs deletion.
// * Displays inorder again (recursive + iterative).

// ---

// ## 🧪 2. Execution Walkthrough

// ### Input:

// ```
// Enter number of nodes: 7
// Enter 7 values: 50 30 70 20 40 60 80
// ```

// ### BST Structure before deletion:

// ```
//          50
//         /  \
//       30    70
//      /  \   / \
//    20   40 60 80
// ```

// ### Traversal Outputs:

// | Traversal       | Output                 |
// | --------------- | ---------------------- |
// | Inorder         | `20 30 40 50 60 70 80` |
// | Preorder        | `50 30 20 40 70 60 80` |
// | Postorder       | `20 40 30 60 80 70 50` |
// | Inorder (Iter.) | `20 30 40 50 60 70 80` |

// ---

// ### Now: Delete value `30`

// **Node 30 has two children (20 and 40)** → apply **Case 3**:

// * Inorder successor is `40`.
// * Replace `30` with `40`.
// * Delete node `40` recursively (which is a leaf).

// ### BST after deletion:

// ```
//          50
//         /  \
//       40    70
//      /      / \
//    20     60  80
// ```

// ### Updated Traversals:

// | Traversal       | Output              |
// | --------------- | ------------------- |
// | Inorder         | `20 40 50 60 70 80` |
// | Inorder (Iter.) | `20 40 50 60 70 80` |

// ---

// ## ✅ Summary

// | Feature               | Implemented? | Notes                                  |
// | --------------------- | ------------ | -------------------------------------- |
// | Insert a node         | ✅            | Classic BST insert                     |
// | Recursive traversals  | ✅            | Inorder, Preorder, Postorder           |
// | Non-recursive inorder | ✅            | Uses a stack                           |
// | Delete a node         | ✅            | Handles 0, 1, and 2 children correctly |

// This code is a **full-featured BST playground**, covering all common operations you'd study in a data structures course.

// Would you like a visual diagram of the tree after deletion too?
