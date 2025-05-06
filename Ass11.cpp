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

// You're solving the **Minimum Spanning Tree (MST)** problem using **Kruskal's Algorithm**, which is ideal for connecting **offices (nodes)** with **minimum total wiring cost (edge weights)**. Let me explain this **step-by-step**.

// ---

// ## 🧠 **Problem Context**

// You have:

// * Several **offices** (treated as graph **vertices**),
// * Possible **connections between offices** with costs (edges with weights),
// * You need to **connect all offices** such that:

//   * **Total connection cost is minimum**,
//   * **All offices are connected** (spanning),
//   * **No cycles** (it's a tree).

// This is exactly what **Kruskal’s Algorithm** solves — by building a **Minimum Spanning Tree (MST)**.

// ---

// ## ⚙️ **High-Level Algorithm Flow**

// ```plaintext
// 1. Sort all edges by weight (lowest first).
// 2. Use Union-Find (DSU) to avoid cycles.
// 3. Pick the smallest edge that connects two *different components*.
// 4. Repeat until you've added (V - 1) edges.
// ```

// ---

// ## 🔍 **Code Breakdown**

// ### 1. 🔗 `struct Edge`

// ```cpp
// struct Edge {
//     int src, dest, weight;
//     bool operator<(const Edge& other) const {
//         return weight < other.weight;
//     }
// };
// ```

// Represents an edge: from `src` to `dest` with a `weight` (cost).
// The `<` operator allows sorting edges by weight using `sort()`.

// ---

// ### 2. 🧩 `class DSU` (Disjoint Set Union)

// Helps detect cycles using **Union-Find**:

// ```cpp
// find(x) → returns root of x
// unite(x, y) → merges sets of x and y if they’re different
// ```

// It ensures:

// * We **only connect** components that are not already connected (no cycles).
// * Uses **path compression** and **union by rank** for performance.

// ---

// ### 3. 🚀 `kruskalMST(V, edges)`

// ```cpp
// sort(edges.begin(), edges.end());
// ```

// * Sorts all edges by their weight (lowest cost first).

// ```cpp
// for (const Edge& e : edges) {
//     if (dsu.find(e.src) != dsu.find(e.dest)) {
//         dsu.unite(e.src, e.dest);
//         print edge;
//         add to totalCost;
//     }
// }
// ```

// For each edge:

// * If it **doesn’t form a cycle**, add it to the MST.
// * Track total cost.

// ---

// ### 4. 🧾 Input Graph

// You're building a graph with **9 offices (0–8)** and **13 possible connections**.

// #### Sample Edge:

// ```cpp
// {0, 1, 4}
// ```

// Means: Office 0 and Office 1 can be connected at a cost of 4.

// ---

// ### 🧮 Sample Output (after Kruskal's Algorithm)

// The program prints:

// ```
// Edges in the Minimum Spanning Tree:
// 6 -- 7 == 1
// 2 -- 8 == 2
// 5 -- 6 == 2
// 0 -- 1 == 4
// 2 -- 5 == 4
// 2 -- 3 == 7
// 0 -- 7 == 8
// 3 -- 4 == 9
// Total Cost of MST: 37
// ```

// These are the **cheapest edges** that connect all offices **without forming any cycle**, and their **total cost is minimized (37)**.

// ---

// ## 📊 Visual Representation

// This forms a connected tree like:

// ```
// 0---1
// |   |
// 7   2---3---4
//     |   |
//     8   5---6
// ```

// (Note: Edges chosen may vary slightly depending on equal weights, but total cost remains optimal.)

// ---

// ## ✅ Summary

// | Part          | Purpose                                       |
// | ------------- | --------------------------------------------- |
// | `Edge` struct | Stores connection info (offices + cost)       |
// | `DSU` class   | Ensures no cycles using Union-Find            |
// | `kruskalMST`  | Implements the Kruskal algorithm to build MST |
// | `main()`      | Defines graph and runs the algorithm          |

// ---

// Would you like a **graph diagram image** or want to see a **step-by-step trace** of the algorithm with explanation of each edge choice?
