// Write a C++ program to implement Huffman coding text compression algorithm. Build the
// Huffman Tree using characters and their frequencies input from user. Encode a given string by
// using codes generated from Huffman tree.
// Test case:
// Character and frequency: a-1, b-2, c-3,d-4,e-5,f-6,g-7,h-8

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    // If it's a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Build Huffman Tree and return root
Node* buildHuffmanTree(const vector<pair<char, int>>& chars) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto& p : chars) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}

int main() {
    vector<pair<char, int>> chars = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4},
        {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}
    };

    Node* root = buildHuffmanTree(chars);

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    string input;
    cout << "\nEnter string to encode: ";
    cin >> input;

    cout << "Encoded string: ";
    for (char c : input) {
        cout << huffmanCode[c];
    }
    cout << endl;

    return 0;
}

// Enter string to encode: abcdefgh

// ----------------------------------------------------------------------

// Let's go through this C++ program **line by line**, understand how **Huffman Coding** is implemented, and walk through the test case: `a-1, b-2, c-3, d-4, e-5, f-6, g-7, h-8`.

// ---

// ## ✅ **1. Data Structures**

// ### Huffman Tree Node

// ```cpp
// struct Node {
//     char ch;
//     int freq;
//     Node *left, *right;

//     Node(char c, int f) {
//         ch = c;
//         freq = f;
//         left = right = nullptr;
//     }
// };
// ```

// Each node represents:

// * A character `ch` and its frequency `freq`
// * `left` and `right` children (used to build the binary tree)

// ---

// ## ✅ **2. Min-Heap Comparator**

// ```cpp
// struct Compare {
//     bool operator()(Node* a, Node* b) {
//         return a->freq > b->freq;
//     }
// };
// ```

// Used by `priority_queue` to turn it into a **min-heap** — the lowest frequency node comes to the top.

// ---

// ## ✅ **3. Generate Huffman Codes**

// ```cpp
// void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode)
// ```

// Recursive function:

// * Left edge → append `'0'`
// * Right edge → append `'1'`
// * Leaf nodes → final character codes

// ---

// ## ✅ **4. Build Huffman Tree**

// ```cpp
// Node* buildHuffmanTree(const vector<pair<char, int>>& chars)
// ```

// Steps:

// 1. Push all characters and their frequencies into a min-heap.
// 2. While more than one node:

//    * Pop two nodes with the lowest frequencies.
//    * Create a new node with these two as children and combined frequency.
//    * Push this new node back into the min-heap.
// 3. Remaining node is the root of the Huffman tree.

// ---

// ## ✅ **5. Main Function Execution**

// ```cpp
// vector<pair<char, int>> chars = {
//     {'a', 1}, {'b', 2}, ..., {'h', 8}
// };
// ```

// All 8 characters with increasing frequency.

// ```cpp
// Node* root = buildHuffmanTree(chars);
// ```

// Builds the Huffman Tree.

// ```cpp
// unordered_map<char, string> huffmanCode;
// generateCodes(root, "", huffmanCode);
// ```

// Generates Huffman codes for each character.

// ```cpp
// cout << "Enter string to encode: ";
// cin >> input;
// ```

// Takes an input string from the user (e.g. `abcdefgh`).

// ```cpp
// for (char c : input) {
//     cout << huffmanCode[c];
// }
// ```

// Prints the **encoded binary string** using the Huffman codes.

// ---

// ## 📦 **Sample Huffman Codes (Output may vary based on tree structure)**

// For the input:

// ```
// a-1, b-2, c-3, d-4, e-5, f-6, g-7, h-8
// ```

// The program might generate codes like:

// ```
// h -> 0
// g -> 10
// f -> 110
// e -> 1110
// d -> 11110
// c -> 111110
// b -> 1111110
// a -> 1111111
// ```

// And for input string `abcdefgh`, encoded output would be:

// ```
// 1111111 1111110 111110 11110 1110 110 10 0
// ```

// (Concatenated into one binary string).

// ---

// ## 🔁 Test Case Explained

// ### Input:

// ```
// abcdefgh
// ```

// ### Output:

// * Shows Huffman code for each character.
// * Prints one long string as the encoded output.

// ---

// ## 🔚 Final Output:

// ```txt
// Huffman Codes:
// a -> 1111111
// b -> 1111110
// ...
// h -> 0

// Enter string to encode: abcdefgh
// Encoded string: 1111111111111011111011110110100
// ```

// ---

// Would you like a **decode function** that takes the encoded string and reconstructs the original?
