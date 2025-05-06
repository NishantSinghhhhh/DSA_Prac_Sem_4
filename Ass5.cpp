// Write a C++ program to construct binary search tree with n nodes and implement following
// operations:
// Insert a node b. all traversals (recursive and nonrecursive) c: Construct Tree from given Inorder
// and Preorder traversals
// Inorder: 2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20
// Preorder: 15,6,3,2,4,7,13,9,18,17,20

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build tree from inorder and preorder
Node* buildFromInPre(int preorder[], int inorder[], int inStart, int inEnd, unordered_map<int, int>& inMap, int& preIndex) {
    if (inStart > inEnd) return nullptr;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = inMap[rootVal];

    root->left = buildFromInPre(preorder, inorder, inStart, inIndex - 1, inMap, preIndex);
    root->right = buildFromInPre(preorder, inorder, inIndex + 1, inEnd, inMap, preIndex);

    return root;
}

// Recursive traversals
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
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
    int inorder[]  = {2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};
    int preorder[] = {15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    unordered_map<int, int> inMap;
    for (int i = 0; i < n; ++i)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    Node* root = buildFromInPre(preorder, inorder, 0, n - 1, inMap, preIndex);

    cout << "\nTree constructed from Inorder and Preorder.\n";

    cout << "\nRecursive Inorder: ";
    inorderTraversal(root);

    cout << "\nRecursive Preorder: ";
    preorderTraversal(root);

    cout << "\nRecursive Postorder: ";
    postorder(root);

    cout << "\nNon-recursive Inorder: ";
    inorderIterative(root);

    cout << endl;
    return 0;
}
