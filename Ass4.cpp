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

// Enter number of nodes: 7  
// Enter 7 values:  
// 50 30 70 20 40 60 80

// Thought for 5 seconds


// Below is the same “**explain first, demo second**” format you liked before.

// ---

// ## 1  Line‑by‑line walkthrough

// | Code fragment                              | What it does / why it matters                                                                 |
// | ------------------------------------------ | --------------------------------------------------------------------------------------------- |
// | `#include <iostream>` / `#include <stack>` | Bring in the C++ streams and the stack container (needed for the non‑recursive inorder walk). |
// | `using namespace std;`                     | Lets us write `cout` instead of `std::cout`.                                                  |

// ### `struct Node`

// | Field                | Purpose                                                   |
// | -------------------- | --------------------------------------------------------- |
// | `int data`           | The key stored in the node.                               |
// | `Node *left, *right` | Pointers to the left and right children.                  |
// | **Constructor**      | Initialises the key and sets child pointers to `nullptr`. |

// ### `insert`

// * Recursively drops a new value into its correct Binary‑Search‑Tree position.
// * Returns the subtree root to keep parent links intact.

// ### Traversal helpers

// | Function    | Order visited                               |
// | ----------- | ------------------------------------------- |
// | `inorder`   | Left, Root, Right (sorted order for a BST). |
// | `preorder`  | Root, Left, Right.                          |
// | `postorder` | Left, Right, Root.                          |

// ### `inorderIterative`

// * Does the same Left‑Root‑Right walk **without recursion**.
// * Uses an explicit `stack<Node*>` to mimic the call stack.

// ### `height`

// ```cpp
// int height(Node* root) {
//     if (!root) return 0;
//     return max(height(root->left), height(root->right)) + 1;
// }
// ```

// * Definition: the number of nodes on the longest root‑to‑leaf path.
// * Recursively asks “what’s the taller subtree?” and adds 1 for the current node.

// ### `mirror`

// ```cpp
// void mirror(Node* root) {
//     if (!root) return;
//     mirror(root->left);
//     mirror(root->right);
//     swap(root->left, root->right);
// }
// ```

// * Recursively visits every node **post‑order** so children are mirrored first.
// * Swaps each node’s left and right pointers ⇒ full mirror image of the tree.

// ### `main`

// 1. Reads `n` and then `n` integers; inserts each into the BST.
// 2. Prints four traversals (three recursive + one iterative).
// 3. Prints the tree’s height.
// 4. Calls `mirror`, then prints an inorder to prove the mirror worked.

// `return 0;` ends the program (automatic cleanup by the OS).

// ---

// ## 2  Step‑by‑step with the sample input

// ### 2.1  Tree construction

// Keys: **50 → 30 → 70 → 20 → 40 → 60 → 80**

// ```
//         50
//       /    \
//     30      70
//    /  \    /  \
//  20  40  60   80
// ```

// ### 2.2  Traversal output

// | Prompt text               | Printed sequence                                        |
// | ------------------------- | ------------------------------------------------------- |
// | **Recursive Inorder**     | `20 30 40 50 60 70 80`                                  |
// | **Recursive Preorder**    | `50 30 20 40 70 60 80`                                  |
// | **Recursive Postorder**   | `20 40 30 60 80 70 50`                                  |
// | **Non‑recursive Inorder** | `20 30 40 50 60 70 80` (identical to the recursive one) |

// ### 2.3  Height

// *Longest root‑to‑leaf path*: 50 → 70 → 80 (or 50 → 70 → 60 etc.) → **3 nodes**
// Program prints

// ```
// Height of the tree: 3
// ```

// ### 2.4  Mirroring

// `mirror` swaps every left/right pair:

// ```
//         50
//       /    \
//     70      30
//    /  \    /  \
//  80  60  40   20
// ```

// New **inorder** (Left‑Root‑Right on the mirrored tree) is the *reverse* of the original:

// ```
// Inorder after mirroring: 80 70 60 50 40 30 20
// ```

// Everything else in memory is the same nodes, just rewired.

// ---

// ### Quick recap of each new feature

// | Requirement               | Code that fulfils it                          |
// | ------------------------- | --------------------------------------------- |
// | **Height**                | `height()` – returns the max depth in nodes.  |
// | **Mirror image**          | `mirror()` – recursive swaps.                 |
// | **Non‑recursive inorder** | `inorderIterative()` using an explicit stack. |

// Feel free to compile, run, and play with different input orders to watch how the height and mirrored traversal change.
