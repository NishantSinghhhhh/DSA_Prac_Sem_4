// Write a C++ program to construct binary search tree with n nodes and implement following
// operations
// Insert a node b. all traversals and nonrecursive inorder c. Check whether two trees are equal.

#include <iostream>
#include <stack>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST Class
class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void displayRecursiveTraversals() {
        cout << "\nInorder (recursive): ";
        inorder(root);
        cout << "\nPreorder (recursive): ";
        preorder(root);
        cout << "\nPostorder (recursive): ";
        postorder(root);
        cout << endl;
    }

    void inorderIterative() {
        cout << "\nInorder (non-recursive): ";
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
        cout << endl;
    }

    Node* getRoot() {
        return root;
    }

    // Compare two trees
    static bool isEqual(Node* a, Node* b) {
        if (!a && !b) return true;
        if (a && b)
            return (a->data == b->data &&
                    isEqual(a->left, b->left) &&
                    isEqual(a->right, b->right));
        return false;
    }
};

int main() {
    BST tree1, tree2;
    int n, val;

    cout << "Enter number of nodes for Tree 1: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree1.insert(val);
    }

    cout << "Enter number of nodes for Tree 2: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree2.insert(val);
    }

    cout << "\n--- Tree 1 Traversals ---";
    tree1.displayRecursiveTraversals();
    tree1.inorderIterative();

    cout << "\n--- Tree 2 Traversals ---";
    tree2.displayRecursiveTraversals();
    tree2.inorderIterative();

    if (BST::isEqual(tree1.getRoot(), tree2.getRoot()))
        cout << "\n✅ The two BSTs are equal.\n";
    else
        cout << "\n❌ The two BSTs are NOT equal.\n";

    return 0;
}

// Enter number of nodes for Tree 1: 5  
// Enter values:  
// 50 30 70 20 40  
// Enter number of nodes for Tree 2: 5  
// Enter values:  
// 50 30 70 20 40  

// Here’s a detailed explanation of how this **sequential file-based student management system** works in C++:

// ---

// ## 🎯 Objective

// Maintain student records with fields:

// * `RollNo`
// * `Name`
// * `Division`
// * `Address`

// And support operations like:

// 1. Add
// 2. Display
// 3. Search
// 4. Edit
// 5. Delete
//    ...using **sequential file storage** (`students.txt`).

// ---

// ## 📦 Structure Definition

// ```cpp
// struct Student {
//     int rollNo;
//     string name;
//     string division;
//     string address;
// };
// ```

// Two helper methods:

// * `to_string()` – converts a `Student` to a CSV string
// * `from_string()` – parses a line from the file back into a `Student` object

// ---

// ## 💾 File Used

// ```cpp
// const string FILE_NAME = "students.txt";
// ```

// Stores all student records **line by line** in CSV format:

// ```
// 1,John,A,Pune
// 2,Sara,B,Mumbai
// ```

// ---

// ## 🔧 Core Functions

// ### 1. `addStudent()`

// Appends a student record to the file:

// ```cpp
// ofstream file(FILE_NAME, ios::app);
// file << s.to_string() << endl;
// ```

// ---

// ### 2. `displayAll()`

// Reads each line from the file, converts to a `Student` and prints it:

// ```cpp
// ifstream file(FILE_NAME);
// while (getline(file, line)) {
//     Student s = Student::from_string(line);
//     // print s
// }
// ```

// ---

// ### 3. `searchStudent(int roll)`

// Reads each line and checks if `rollNo` matches. If found, it prints the record.

// ---

// ### 4. `deleteStudent(int roll)`

// * Opens the original file for reading.
// * Writes every line **except the one to delete** into a temp file.
// * Replaces the original file with the temp file.

// This simulates deletion in a sequential file.

// ---

// ### 5. `editStudent(int roll, Student newDetails)`

// Same as delete, but:

// * If roll matches, write the **new details**.
// * Else, copy the old line as-is.

// ---

// ## 🧪 Sample I/O

// ### Adding:

// ```
// Roll No: 1
// Name: John
// Division: A
// Address: Pune
// ```

// Saved as:

// ```
// 1,John,A,Pune
// ```

// ### Searching:

// ```
// Enter RollNo to search: 1
// Record Found:
// RollNo: 1
// Name: John
// Division: A
// Address: Pune
// ```

// ---

// ## 🧠 Notes

// * File is **sequential**: appending is easy, but searching/editing/deleting needs reading the whole file.
// * Temporary file is used to simulate editing or deleting.
// * Easy to port into C++ classes if needed.

// ---

// ## ✅ Summary Table

// | Operation   | Method            | File Handling Type  |
// | ----------- | ----------------- | ------------------- |
// | Add         | `addStudent()`    | Append (`ios::app`) |
// | Display All | `displayAll()`    | Read (`ifstream`)   |
// | Search      | `searchStudent()` | Read (`ifstream`)   |
// | Delete      | `deleteStudent()` | Read+Write via temp |
// | Edit        | `editStudent()`   | Read+Write via temp |

// ---

// Would you like a version of this that uses **binary file storage** for better performance and fixed-size records?
