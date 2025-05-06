// Implement Dijkstra’s algorithm for shortest path between a given pair of vertices. Display the
// shortest path from the source vertex 0 to all other vertices
// Test your program for following example:


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
vector<int> dist(MAXN, INT_MAX);
vector<int> parent(MAXN, -1);

// Standard Dijkstra with parent tracking
void dijkstra(int S, int n) {
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}


void print_shortest_path(int S, int F) {
    vector<int> path;
    int current = F;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    cout << "Shortest Path from " << S << " to " << F << ": ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    int S, F;
    cin >> S >> F;

    dijkstra(S, V);
   
    cout << "Shortest Distance from " << S << " to " << F << ": " << dist[F] << "\n";
    print_shortest_path(S, F);
    return 0;
}

// This C++ program implements **Dijkstra’s Algorithm** using a **priority queue (min-heap)** to find the **shortest path from a source node to a destination node** in a **directed weighted graph**.

// Here’s a **line-by-line explanation** followed by a **sample walkthrough**:

// ---

// ## 🧱 **Code Breakdown**

// ### 🔢 Constants and Global Variables

// ```cpp
// const int MAXN = 100005;
// vector<pair<int, int>> adj[MAXN];     // adjacency list: adj[u] = list of (v, weight)
// vector<int> dist(MAXN, INT_MAX);      // distance from source to each node
// vector<int> parent(MAXN, -1);         // to reconstruct shortest path
// ```

// ---

// ### 🚀 `dijkstra(int S, int n)`

// Performs **Dijkstra's algorithm** from source node `S`:

// ```cpp
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// ```

// A **min-heap** where `pq.top()` gives the node with the **smallest current distance**.

// #### Algorithm flow:

// 1. Start from `S`, mark `dist[S] = 0`.
// 2. Push `(0, S)` into the priority queue.
// 3. While the queue is not empty:

//    * Pop `(d, u)` — the current shortest known node.
//    * For every neighbor `v` of `u`, if `dist[v] > dist[u] + weight`:

//      * Update `dist[v]`
//      * Record `parent[v] = u`
//      * Push `(dist[v], v)` into the queue.

// This gives **optimal shortest path distances** from `S` to all other nodes.

// ---

// ### 🧭 `print_shortest_path(int S, int F)`

// Reconstructs the path from `S` to `F` by following the `parent[]` array.

// * Start from destination `F`.
// * Backtrack to `S` using `parent[]`.
// * Reverse the collected path to print it from source to destination.

// ---

// ### 🏁 `main()` function

// ```cpp
// int V, E;
// cin >> V >> E;
// ```

// Reads number of vertices and edges.

// ```cpp
// cin >> u >> v >> wt;
// adj[u].push_back({v, wt});
// ```

// Reads `E` edges (directed) and fills the adjacency list.

// ```cpp
// cin >> S >> F;
// ```

// Reads source `S` and final destination `F`.

// Then:

// ```cpp
// dijkstra(S, V);
// print_shortest_path(S, F);
// ```

// Runs Dijkstra's algorithm and prints the result.

// ---

// ## 🧪 Sample Input & Walkthrough

// ### 🔢 Input:

// ```
// 6 9
// 0 1 4
// 0 2 1
// 2 1 2
// 1 3 1
// 2 3 5
// 3 4 3
// 4 5 2
// 2 5 10
// 1 5 7
// 0 5
// ```

// ### 🔁 Graph Structure:

// ```
// 0 → 1 (4)
// 0 → 2 (1)
// 2 → 1 (2)
// 1 → 3 (1)
// 2 → 3 (5)
// 3 → 4 (3)
// 4 → 5 (2)
// 2 → 5 (10)
// 1 → 5 (7)
// ```

// ### ✅ Dijkstra (from 0 to 5):

// * `0 → 2 → 1 → 3 → 4 → 5`
// * Distance = `0 + 1 + 2 + 1 + 3 + 2 = 9`

// ### 🧾 Output:

// ```
// Shortest Distance from 0 to 5: 9
// Shortest Path from 0 to 5: 0 2 1 3 4 5
// ```

// ---

// ## ✅ Summary

// | Feature                   | Description                     |
// | ------------------------- | ------------------------------- |
// | ✅ Shortest path algorithm | Dijkstra using a priority queue |
// | ✅ Path reconstruction     | Using `parent[]` array          |
// | ✅ Handles edge weights    | Supports weighted graphs        |
// | ✅ Directed graph support  | Edges are one-directional       |
// | 🚀 Efficient              | Uses min-heap, O((V + E) log V) |

// ---

// ### 📌 Want more?

// Would you like to:

// * Add **support for undirected graphs**?
// * Allow **multiple queries** from the same source?
// * Output the full shortest distance table from `S` to all nodes?

// Let me know!
