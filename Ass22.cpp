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
