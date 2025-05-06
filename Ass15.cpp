// Given sequence k = k1<; k2<..... kn of n sorted keys, with a search probability pi for each
// key ki . Build the Binary search tree that has the least search cost given the access probability
// for each key. Display weight matrix, cost matrix and root matrix.
// test your program for following example:
// k1=do, k2=if, k3=read, k4= while
// p1 = 1, p2 = 3, p3 = 1, p4 = 3
// q0 = 1, q1 = 2, q2 = 1, q3= 1, q4 = 3

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

const int n = 4; // Number of keys

void buildOBST(vector<int> p, vector<int> q, vector<string> keys) {
    int cost[n + 2][n + 1] = {0};
    int weight[n + 2][n + 1] = {0};
    int root[n + 2][n + 1] = {0};

    // Initialization
    for (int i = 0; i <= n; i++) {
        cost[i + 1][i] = q[i];
        weight[i + 1][i] = q[i];
    }

    // Dynamic Programming
    for (int length = 1; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            weight[i][j] = weight[i][j - 1] + p[j - 1] + q[j];

            for (int r = i; r <= j; r++) {
                int c = cost[i][r - 1] + cost[r + 1][j] + weight[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    // Display Weight Matrix
    cout << "\nWeight Matrix:\n";
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            if (i <= j + 1)
                cout << setw(3) << weight[i][j] << " ";
            else
                cout << "    ";
        }
        cout << endl;
    }

    // Display Cost Matrix
    cout << "\nCost Matrix:\n";
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            if (i <= j + 1)
                cout << setw(3) << cost[i][j] << " ";
            else
                cout << "    ";
        }
        cout << endl;
    }

    // Display Root Matrix
    cout << "\nRoot Matrix:\n";
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            if (i <= j + 1)
                cout << setw(3) << root[i][j] << " ";
            else
                cout << "    ";
        }
        cout << endl;
    }

    cout << "\nMinimum cost of Optimal BST: " << cost[1][n] << endl;
}

int main() {
    vector<string> keys = {"do", "if", "read", "while"};
    vector<int> p = {1, 3, 1, 3};    // successful search probabilities
    vector<int> q = {1, 2, 1, 1, 3}; // unsuccessful search probabilities

    buildOBST(p, q, keys);

    return 0;
}
