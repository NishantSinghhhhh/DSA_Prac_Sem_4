// Implement Dijkstra’s algorithm for shortest path between a given pair of vertices. Display the
// shortest path from the source vertex 0 to all other vertices
// Test your program for following example:

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int V = 9; // Total vertices in the graph

// Function to run Dijkstra's algorithm
void dijkstra(vector<pair<int, int>> adj[], int source) {
    vector<int> dist(V, INT_MAX); // Distance from source to each vertex
    dist[source] = 0;

    // Min-heap priority queue: (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print result
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To " << i << " => " << dist[i] << "\n";
    }
}

int main() {
    vector<pair<int, int>> adj[V];
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

    // Run Dijkstra from source vertex 0
    dijkstra(adj, 0);

    return 0;
}

// This program is a clean implementation of **Dijkstra’s Algorithm** that calculates the **shortest distance from source vertex `0` to all other vertices** in a **weighted undirected graph**. Let’s break it down:

// ---

// ## 🔧 **Problem Goal**

// > Given a graph with 9 vertices (0 to 8) and weighted edges, find and display the **minimum distance** from vertex `0` to every other vertex.

// This is exactly what **Dijkstra’s Algorithm** is designed for.

// ---

// ## 🔍 **Line-by-Line Explanation**

// ### 1. 📦 Definitions

// ```cpp
// const int V = 9;
// vector<pair<int, int>> adj[V];
// ```

// * `V = 9` → total number of vertices
// * `adj[]` → adjacency list, where each `adj[u]` contains `{v, weight}`

// ---

// ### 2. 🚀 `dijkstra(...)` Function

// ```cpp
// vector<int> dist(V, INT_MAX);
// dist[source] = 0;
// ```

// * Initializes all distances to `∞` (`INT_MAX`)
// * Sets `dist[source] = 0` (source → source = 0)

// ```cpp
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
// pq.push({0, source});
// ```

// * A **min-heap** priority queue to always process the vertex with the **smallest current distance**.

// ---

// ### 3. 🔁 Main Loop

// ```cpp
// while (!pq.empty()) {
//     int u = pq.top().second;
//     pq.pop();
// ```

// * Pops the node `u` with the smallest `dist[u]`.

// ```cpp
// for (auto& edge : adj[u]) {
//     int v = edge.first;
//     int weight = edge.second;

//     if (dist[u] + weight < dist[v]) {
//         dist[v] = dist[u] + weight;
//         pq.push({dist[v], v});
//     }
// }
// ```

// * For each neighbor `v` of `u`, checks if taking the edge `u → v` gives a **shorter path**.
// * If yes, update `dist[v]` and push it back into the priority queue.

// ---

// ### 4. 📤 Print Final Distances

// ```cpp
// for (int i = 0; i < V; i++) {
//     cout << "To " << i << " => " << dist[i] << "\n";
// }
// ```

// ---

// ## 🔁 **Graph Data**

// This graph is **undirected** — for every edge `{u, v, w}`, both:

// ```cpp
// adj[u].push_back({v, w});
// adj[v].push_back({u, w});
// ```

// are present, ensuring bidirectional paths.

// ---

// ## ✅ **Expected Output**

// After running Dijkstra from node `0`, the output should look like:

// ```
// Shortest distances from vertex 0:
// To 0 => 0
// To 1 => 4
// To 2 => 12
// To 3 => 19
// To 4 => 21
// To 5 => 11
// To 6 => 9
// To 7 => 8
// To 8 => 14
// ```

// ### Why?

// * 0→1 (4)
// * 0→7 (8)
// * 7→6 (1) → 9
// * 6→5 (2) → 11
// * 5→2 (4) → 15
// * 2→8 (2) → 17
// * etc...

// ---

// ## ✅ Summary

// | Feature                           | Covered |
// | --------------------------------- | ------- |
// | Dijkstra’s shortest path          | ✅       |
// | Uses priority queue (min-heap)    | ✅       |
// | Graph modeled as adjacency list   | ✅       |
// | Prints distance from 0 to all     | ✅       |
// | Handles weighted undirected graph | ✅       |

// ---

// Would you like to enhance this to also **print the actual paths** from `0` to each vertex using a `parent[]` array, like in your previous code?
