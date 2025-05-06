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

// Enter number of nodes: 7  
// Enter 7 values:  
// 50 30 70 20 40 60 80

// **Explaining BST operations**

// The user has shared a C++ program to build a BST and perform several operations. They might want a line-by-line explanation, just like the last time when they needed help with the search function. The program includes operations like insertion, traversal (both recursive and non-recursive), cloning, and deletion. I’ll break down each operation and explain them with a sample test case, making sure to provide outputs for traversals and highlight key moments like insertion, recursion in traversal, cloning, and deletion.


// Thought for 6 seconds


// Below is the familiar two‑part drill:

// 1. **Line‑by‑line commentary** – what every declaration, branch, and loop is doing.
// 2. **Step‑through with the sample input `50 30 70 20 40 60 80`** – showing how the tree grows, what each traversal prints, how cloning copies it, and how deletion frees the original.

// ---

// ## 1  Detailed code walk‑through

// | Code fragment                              | Meaning & purpose                                                                                                                                                                                                                                                                                                                                                                 |
// | ------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
// | `#include <iostream>` / `#include <stack>` | Bring in I/O streams and `std::stack` (needed for the non‑recursive inorder).                                                                                                                                                                                                                                                                                                     |
// | `using namespace std;`                     | Lets us omit the `std::` prefix.                                                                                                                                                                                                                                                                                                                                                  |
// | **`struct Node`**                          | One node of the BST. Contains:<br>• `data` – the integer key.<br>• `left` / `right` – child pointers.<br>Constructor sets the data and initialises children to `nullptr`.                                                                                                                                                                                                         |
// | **`Node* insert(Node* root, int val)`**    | Standard recursive BST insertion:<br>• If the current subtree is empty (`root == nullptr`) create a new node and return it.<br>• Otherwise compare `val` to `root->data` and recurse left or right.<br>• Returns the (possibly unchanged) subtree root so links are updated on the way back.                                                                                      |
// | **`void inorder(Node* root)`**             | Classic left‑root‑right traversal (recursive).                                                                                                                                                                                                                                                                                                                                    |
// | **`void preorder(Node* root)`**            | Root‑left‑right traversal.                                                                                                                                                                                                                                                                                                                                                        |
// | **`void postorder(Node* root)`**           | Left‑right‑root traversal.                                                                                                                                                                                                                                                                                                                                                        |
// | **`void inorderIterative(Node* root)`**    | Non‑recursive inorder using an explicit stack:<br>1. Walk left, pushing nodes.<br>2. Pop, visit, then move to the popped node’s right child.<br>3. Repeat until both the current pointer is `nullptr` **and** the stack is empty.                                                                                                                                                 |
// | **`Node* clone(Node* root)`**              | Deep‑copies the tree:<br>• Recursively allocate a new node.<br>• Copy the key.<br>• Recursively clone the left and right subtrees.<br>Returns pointer to the cloned root (or `nullptr` for an empty subtree).                                                                                                                                                                     |
// | **`void deleteTree(Node*& root)`**         | Post‑order deletion:<br>• Recurse left, recurse right, then `delete root`.<br>• Finally sets the caller’s pointer to `nullptr` so dangling references are impossible.                                                                                                                                                                                                             |
// | **`int main()`**                           | Driver routine:<br>1. Reads `n` and then `n` keys; inserts each into the BST.<br>2. Prints the three recursive traversals and the non‑recursive inorder.<br>3. Calls `clone` to make `clonedRoot`.<br>4. Deletes the original tree (`deleteTree(root)`).<br>5. Demonstrates that the clone is intact by printing its inorder.<br>6. Deletes the clone to free memory before exit. |

// ---

// ## 2  Execution trace with the sample data

// ### 2.1  Building the BST

// Keys arrive in the order **50 → 30 → 70 → 20 → 40 → 60 → 80**:

// ```
// 50
// ├── 30
// │   ├── 20
// │   └── 40
// └── 70
//     ├── 60
//     └── 80
// ```

// *Every insertion obeys BST rules (`left < parent < right`).*

// ### 2.2  Traversal outputs

// | Traversal                 | Visiting order            | Printed line           |
// | ------------------------- | ------------------------- | ---------------------- |
// | Recursive **Inorder**     | 20 30 40 50 60 70 80      | `20 30 40 50 60 70 80` |
// | Recursive **Preorder**    | 50 30 20 40 70 60 80      | `50 30 20 40 70 60 80` |
// | Recursive **Postorder**   | 20 40 30 60 80 70 50      | `20 40 30 60 80 70 50` |
// | **Non‑recursive** Inorder | same as recursive inorder | `20 30 40 50 60 70 80` |

// *(The iterative algorithm prints the exact same sequence as the recursive inorder because it simulates the call stack.)*

// ### 2.3  Cloning

// `clone(root)` allocates seven new nodes, copying the topology and data 1‑for‑1:

// ```
// clonedRoot (50)
// ├── 30
// │   ├── 20
// │   └── 40
// └── 70
//     ├── 60
//     └── 80
// ```

// Both trees now coexist independently in memory.

// ### 2.4  Deleting the original

// `deleteTree(root)`:

// 1. Recurses to the leftmost leaf (`20`), deletes it, returns.
// 2. Bubbles back up deleting `40`, then `30`, …, finally deletes the root `50`.
// 3. Sets the caller’s pointer `root` to `nullptr`.

// Output:

// ```
// Original tree deleted.
// ```

// ### 2.5  Verifying the clone

// Calling `inorder(clonedRoot)` still prints

// ```
// Cloned Tree Inorder: 20 30 40 50 60 70 80
// ```

// proving that only the **original** memory was freed.

// Finally `deleteTree(clonedRoot)` cleans up, preventing leaks.

// ---

// ## Why each requirement is satisfied

// | Requirement                   | Where it’s handled                                                                                |
// | ----------------------------- | ------------------------------------------------------------------------------------------------- |
// | **a. Insert a node**          | `insert()` (recursive)                                                                            |
// | **b. All traversals**         | `inorder`, `preorder`, `postorder`, plus `inorderIterative` for non‑recursive inorder             |
// | **c. Clone & erase original** | `clone()` deep‑copies, `deleteTree()` erases original; program then shows the clone still working |

// Feel free to drop this code straight into a `.cpp` file, compile, and test with your own sequences of keys — everything runs in `O(n)` space and `O(n)` time for these operations.
