// You have a business with several offices; you want to lease phone lines to connect them up
// with each other; and the phone company charges different amounts of money to connect
// different pairs of cities. You want a set of lines that connects all your offices with a minimum
// total cost. Solve the problem by suggesting appropriate data structures (Kruskal’s algorithm)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot) return;

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
};

// Kruskal's algorithm to find MST
void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);

    int totalCost = 0;
    cout << "Edges in the Minimum Spanning Tree:\n";

    for (const Edge& e : edges) {
        if (dsu.find(e.src) != dsu.find(e.dest)) {
            dsu.unite(e.src, e.dest);
            cout << e.src << " -- " << e.dest << " == " << e.weight << "\n";
            totalCost += e.weight;
        }
    }

    cout << "Total Cost of MST: " << totalCost << "\n";
}

int main() {
    int V = 9; // Total vertices (0 to 8)

    // All edges with weights from the image
    vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8},
        {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 5, 4}, {2, 8, 2},
        {3, 4, 9},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1}, {6, 8, 6},
        {7, 8, 7}
    };

    kruskalMST(V, edges);

    return 0;
}
