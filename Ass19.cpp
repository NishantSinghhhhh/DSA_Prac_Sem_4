#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[v][i] && !visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFS(int start = 0) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start = 0) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < V; ++i) {
                if (adjMatrix[v][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Check how many connected components the graph has
    int countConnectedComponents() {
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFSUtil(i, visited);
                count++;
            }
        }

        return count;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.DFS();
    g.BFS();

    int components = g.countConnectedComponents();
    if (components == 1)
        cout << "The graph is connected.\n";
    else
        cout << "The graph is not connected. It has " << components << " connected components.\n";

    return 0;
}

// Enter number of vertices and edges: 6 4
// Enter 4 edges (u v):
// 0 1
// 1 2
// 3 4
// 4 5


// -----------------------------------------------------------

// This program implements an **undirected graph** using an **adjacency matrix**, and performs the following operations:

// * Add edges
// * Perform **DFS (Depth First Search)** traversal
// * Perform **BFS (Breadth First Search)** traversal
// * Count the number of **connected components**

// Let’s walk through each part in detail.

// ---

// ## 🔧 Code Explanation

// ### 1. **Graph Representation**

// ```cpp
// vector<vector<int>> adjMatrix;
// ```

// The graph is stored as an **adjacency matrix**:

// * If there’s an edge between node `u` and node `v`, `adjMatrix[u][v] = 1`.

// ### Constructor:

// ```cpp
// Graph(int vertices) {
//     V = vertices;
//     adjMatrix.resize(V, vector<int>(V, 0));
// }
// ```

// Initializes a V × V matrix filled with 0s.

// ---

// ### 2. **Adding an Edge**

// ```cpp
// void addEdge(int u, int v) {
//     adjMatrix[u][v] = 1;
//     adjMatrix[v][u] = 1; // Undirected graph
// }
// ```

// Adds a bi-directional (undirected) edge.

// ---

// ### 3. **DFS Traversal**

// ```cpp
// void DFSUtil(int v, vector<bool>& visited)
// ```

// * Recursively visits all unvisited adjacent nodes starting from `v`.

// ```cpp
// void DFS(int start = 0)
// ```

// * Initializes `visited[]`, then calls `DFSUtil`.

// **Example for input 6 4**:

// ```
// Edges: 0-1, 1-2, 3-4, 4-5
// DFS output: 0 1 2
// ```

// Only the first component starting from vertex 0 is printed in `DFS()` (unless you visit all from `countConnectedComponents()`).

// ---

// ### 4. **BFS Traversal**

// ```cpp
// void BFS(int start = 0)
// ```

// Uses a queue to explore nodes **level by level**.

// **Same input produces:**

// ```
// BFS output: 0 1 2
// ```

// ---

// ### 5. **Connected Components**

// ```cpp
// int countConnectedComponents()
// ```

// * Initializes all nodes as unvisited.
// * Calls `DFSUtil(i)` for each unvisited node.
// * Each DFS traversal from a new unvisited node represents a new **connected component**.

// **For input:**

// ```
// 6 vertices, 4 edges
// Edges: 0-1, 1-2 (Component 1), 3-4, 4-5 (Component 2)
// ```

// Output:

// ```
// The graph is not connected. It has 2 connected components.
// ```

// ---

// ## 🧪 Sample Run

// ```
// Enter number of vertices and edges: 6 4
// Enter 4 edges (u v):
// 0 1
// 1 2
// 3 4
// 4 5

// DFS Traversal: 0 1 2
// BFS Traversal: 0 1 2
// 3 4 5 The graph is not connected. It has 2 connected components.
// ```

// ---

// ## ✅ Summary Table

// | Operation            | Method Used           |
// | -------------------- | --------------------- |
// | Graph representation | Adjacency Matrix      |
// | Traversal (DFS)      | Recursion             |
// | Traversal (BFS)      | Queue                 |
// | Connectivity check   | DFS + component count |

// ---

// Would you like a **graph visualization diagram** of this input or want it implemented with an **adjacency list** instead?
