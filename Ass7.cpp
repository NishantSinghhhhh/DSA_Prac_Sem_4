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

// You've written a full C++ program for creating and comparing **Binary Search Trees (BSTs)** — but the **title says "inorder threaded binary search tree"**, while the actual code implements a **regular (unthreaded) BST**.

// ---

// ## ✅ Let's break it down as-is first (Regular BST)

// ### 🔧 Features Implemented:

// | Feature                                 | Implemented? | Notes                   |
// | --------------------------------------- | ------------ | ----------------------- |
// | Insert a new node into a BST            | ✅            | Uses recursion          |
// | Recursive traversals (inorder/pre/post) | ✅            | Standard depth-first    |
// | Non-recursive inorder traversal         | ✅            | Uses a stack            |
// | Compare two BSTs for equality           | ✅            | Node-by-node comparison |
// | Inorder Threading                       | ❌            | Not present             |

// ---

// ## 🧠 Code Flow Summary

// ### 🌲 BST Construction

// Two BSTs `tree1` and `tree2` are built independently using:

// ```cpp
// tree.insert(val);
// ```

// which internally calls:

// ```cpp
// Node* insert(Node* node, int val);
// ```

// to place each value in the proper BST location.

// ---

// ### 🔁 Traversals

// * **Recursive Inorder**: left → root → right
// * **Recursive Preorder**: root → left → right
// * **Recursive Postorder**: left → right → root
// * **Non-recursive Inorder**: simulates recursion with a stack

// ---

// ### 🔍 Tree Comparison

// ```cpp
// static bool isEqual(Node* a, Node* b);
// ```

// * Compares structure and data recursively.
// * Returns `true` only if both trees are **structurally identical** and have **same values**.

// ---

// ### 🔎 Sample Run (Given Input)

// Input:

// ```
// Tree 1: 10 5 20 3 7
// Tree 2: 10 5 20 3 7
// ```

// Constructed BST:

// ```
//       10
//      /  \
//     5    20
//    / \
//   3   7
// ```

// Output:

// ```
// Recursive Inorder: 3 5 7 10 20
// Recursive Preorder: 10 5 3 7 20
// Recursive Postorder: 3 7 5 20 10
// Non-Recursive Inorder: 3 5 7 10 20

// Are both trees equal? Yes
// ```

// ---

// ## ❌ What's Missing: *Inorder Threaded Binary Tree*

// An **inorder-threaded binary tree** replaces `nullptr` child pointers with special pointers that point to the **inorder predecessor or successor**.

// So for example:

// * `left == nullptr` becomes a **thread** to inorder predecessor.
// * `right == nullptr` becomes a **thread** to inorder successor.

// It enables **inorder traversal without recursion or stack**.

// ---

// ## ✅ Do You Want This Instead?

// If you're trying to write a **Threaded BST** and not a regular one, you'd need:

// 1. A modified `Node` structure with flags:

//    ```cpp
//    bool leftThread, rightThread;
//    ```

// 2. An insertion method that correctly sets up those threads.

// 3. A **thread-aware inorder traversal** like:

//    ```cpp
//    void inorderThreaded(Node* root);
//    ```

// ---

// ### 🔁 Next Step?

// Would you like me to **rewrite your code into an actual Inorder Threaded BST** with proper thread insertion and traversal (without stack or recursion)?
