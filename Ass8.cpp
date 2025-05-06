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

// ### 📘 What is an **Inorder Threaded Binary Search Tree (Threaded BST)?**

// An **Inorder Threaded Binary Search Tree** is a special type of Binary Search Tree (BST) that uses otherwise unused `nullptr` pointers to store **"threads"** — links to the **inorder predecessor or successor** of a node.

// This makes **inorder traversal** possible **without recursion or a stack**, making it faster and more memory-efficient.

// ---

// ## ✅ Why do we need it?

// In a normal BST:

// * Each node has two child pointers: `left` and `right`.
// * Many of those pointers (especially for leaves) are `nullptr`.
// * Inorder traversal requires **recursion** or an **explicit stack** to backtrack.

// **In a Threaded BST:**

// * We replace `nullptr` pointers with **threads** that point to the node’s **inorder neighbor**.
// * We also add boolean flags `lthread` and `rthread` to tell whether a pointer is a thread or a real child.

// ---

// ## 📌 Example

// ### Normal BST

// ```
//        50
//      /    \
//    30      70
//   /  \    /
// 20   40  60
// ```

// **Inorder Traversal**: `20 30 40 50 60 70`

// ### Threaded BST

// Now add **threads** where child pointers would be null:

// ```
//        50
//      /    \
//    30      70
//   /  \    /
// 20   40  60
// ```

// | Node | Left Thread | Right Thread |
// | ---- | ----------- | ------------ |
// | 20   | nullptr     | → 30         |
// | 40   | ← 30        | → 50         |
// | 60   | ← 50        | → 70         |
// | 70   | ← 60        | nullptr      |

// Now:

// * `20.right` points to `30`
// * `40.right` points to `50`
// * `60.right` points to `70`
// * `30.left` points to `20` (if left child is null)
// * etc.

// ---

// ## 🧠 Structure of a Node

// ```cpp
// struct Node {
//     int data;
//     Node* left, *right;
//     bool lthread, rthread;
// };
// ```

// * If `lthread == true`, then `left` is not a child — it's a **thread to inorder predecessor**.
// * If `rthread == true`, then `right` is a **thread to inorder successor**.

// ---

// ## 🚶 Inorder Traversal Logic (No recursion or stack)

// 1. Start at the **leftmost** node.
// 2. Print the current node.
// 3. If `rthread == true`, follow it.
// 4. Else, go to the **leftmost node in the right subtree**.

// ---

// ## ✅ Advantages of Threaded BST

// | Benefit                   | Why it matters                |
// | ------------------------- | ----------------------------- |
// | 💡 No recursion/stack     | Saves memory, simplifies code |
// | 🚀 Fast inorder traversal | O(n) with no extra space      |
// | 📈 Efficient use of space | Reuses unused `nullptr` links |

// ---

// ## 🚫 Limitation

// * Insertion and deletion become **more complex** — you must maintain thread consistency.
// * You must **track whether a pointer is a thread** or a real child.

// ---

// ## 🔁 Summary

// | Feature                       | In Threaded BST      |
// | ----------------------------- | -------------------- |
// | Unused `nullptr` pointers     | Used as threads      |
// | Traversal                     | No stack/recursion   |
// | Node metadata                 | `lthread`, `rthread` |
// | Extra complexity in insertion | Yes                  |

// ---

// Would you like a **diagram** showing threads visually or want to see **how insertions work in a threaded BST directly**?
