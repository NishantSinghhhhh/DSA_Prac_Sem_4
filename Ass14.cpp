// You have a business with several offices; you want to lease phone lines to connect them up
// with each other; and the phone company charges different amounts of money to connect
// different pairs of cities. You want a set of lines that connects all your offices with a minimum
// total cost. Solve the problem by suggesting appropriate data structures (Prim’s algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int V = 9; // Total vertices in graph (0 to 8)

// Prim’s Algorithm function
void primMST(vector<pair<int, int>> adj[]) {
    vector<bool> inMST(V, false);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int totalCost = 0;
    pq.push({0, 0}); // {weight, vertex}

    cout << "Edges in MST:\n";

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += weight;

        // Print the selected edge (except for starting node 0)
        if (weight != 0)
            cout << "Include node: " << u << " with cost: " << weight << "\n";

        for (auto [v, w] : adj[u]) {
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    vector<pair<int, int>> adj[V];

    // Graph from the image (undirected)
    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 8});
    adj[1].push_back({7, 11});
    adj[2].push_back({1, 8});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[2].push_back({8, 2});
    adj[3].push_back({2, 7});
    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});
    adj[4].push_back({5, 10});
    adj[5].push_back({4, 10});
    adj[5].push_back({6, 2});
    adj[5].push_back({2, 4});
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 6});
    adj[7].push_back({0, 8});
    adj[7].push_back({1, 11});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 7});
    adj[8].push_back({2, 2});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});

    primMST(adj);

    return 0;
}


// You're solving a **Minimum Spanning Tree (MST)** problem using **Prim’s Algorithm** — a classic greedy algorithm used to connect all nodes (offices) with **minimum total cost**, given a **weighted undirected graph**.

// Let’s break this down clearly:

// ---

// ## ✅ Problem Summary

// > You have `V = 9` offices (nodes 0 to 8), and want to connect them with phone lines such that:

// * Every office is reachable from every other office (i.e., the graph is connected),
// * The **total wiring/connection cost is minimized**,
// * **No cycles** are allowed (i.e., it must be a tree).

// This is a classic **MST problem**, and **Prim’s Algorithm** is a perfect choice.

// ---

// ## 🔍 What is Prim’s Algorithm?

// Prim's Algorithm:

// * Starts from any node (here, node 0),
// * Grows a **tree by adding the minimum weight edge** that connects a new node to the tree,
// * Repeats until all nodes are included.

// ---

// ## 🧱 Code Walkthrough

// ### 1. **Graph Representation**

// ```cpp
// vector<pair<int, int>> adj[V];
// ```

// Each `adj[u]` stores a list of `{v, weight}` pairs (undirected edges).

// Example:

// ```cpp
// adj[0].push_back({1, 4});
// adj[1].push_back({0, 4});
// ```

// means there's an edge between node 0 and node 1 with cost 4.

// ---

// ### 2. **Priority Queue (Min-Heap)**

// ```cpp
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
// ```

// * Stores `{cost, vertex}`.
// * Always picks the **smallest edge cost** first.

// ---

// ### 3. **Prim’s MST Algorithm**

// ```cpp
// vector<bool> inMST(V, false); // To track which nodes are already in the MST
// pq.push({0, 0});              // Start with node 0, cost = 0
// ```

// Now the main loop:

// ```cpp
// while (!pq.empty()) {
//     auto [weight, u] = pq.top();
//     pq.pop();

//     if (inMST[u]) continue;     // Already added? Skip

//     inMST[u] = true;            // Mark node u as added to MST
//     totalCost += weight;

//     // Print the included node and cost (except for root)
//     if (weight != 0)
//         cout << "Include node: " << u << " with cost: " << weight << "\n";

//     for (auto [v, w] : adj[u]) {
//         if (!inMST[v]) {
//             pq.push({w, v});   // Consider this edge
//         }
//     }
// }
// ```

// This loop:

// * Adds the cheapest available edge that connects a new node to the MST,
// * Ensures no cycles by checking `inMST[]`.

// ---

// ### 4. **Final Output**

// It prints:

// * Each node as it’s added to the MST,
// * The **cost of adding that node**, and
// * The **total cost** after all nodes are connected.

// ---

// ## 🧪 Example Output (Simplified)

// You’ll see output like:

// ```
// Edges in MST:
// Include node: 1 with cost: 4
// Include node: 7 with cost: 8
// Include node: 6 with cost: 1
// Include node: 5 with cost: 2
// Include node: 2 with cost: 4
// Include node: 8 with cost: 2
// Include node: 3 with cost: 7
// Include node: 4 with cost: 9
// Total cost of MST: 37
// ```

// These edges form the **Minimum Spanning Tree**, and total cost = `37`.

// ---

// ## 🧠 Summary

// | Concept         | Description                              |
// | --------------- | ---------------------------------------- |
// | Data Structure  | Adjacency list + Min-Heap Priority Queue |
// | Algorithm Used  | Prim's Algorithm                         |
// | Output          | List of MST edges and total cost         |
// | Cycle Avoidance | Tracked using `inMST[]`                  |
// | Optimization    | Always picks next cheapest edge          |

// ---

// Would you like a visual diagram of how Prim’s algorithm builds the MST step by step?
