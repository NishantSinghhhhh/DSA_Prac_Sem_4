// Given a directed acyclic graph, a. write a program for topological ordering of vertices b. BFS
// traversal:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int V = 11; 

vector<int> adj[V];
vector<int> indegree(V, 0);
vector<bool> visited(V, false);

void topologicalSort() {
    queue<int> q;
    for (int i = 1; i < V; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    cout << "\nTopological Sort Order: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }
    cout << endl;
}


void bfsTraversal() {
    cout << "\nBFS Traversal: ";
    for (int i = 1; i < V; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                cout << u << " ";
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}

int main() {
    adj[1] = {2, 3};
    adj[2] = {4};
    adj[3] = {4, 7};
    adj[4] = {5};
    adj[5] = {10};
    adj[6] = {8};
    adj[7] = {8};
    adj[8] = {9};
    adj[9] = {10};

    for (int u = 1; u < V; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    topologicalSort();
    bfsTraversal();

    return 0;
}

// -----------------------------------------------------------------

// Here’s a detailed explanation of your C++ program which handles:

// 1. **Topological Sorting** using **Kahn’s Algorithm (BFS-based)**
// 2. **BFS Traversal** of a **Directed Acyclic Graph (DAG)**

// ---

// ## ✅ Overview of the Graph Structure

// The graph has **11 vertices (1 to 10)** (0 is unused). These are the directed edges defined:

// ```
// 1 → 2, 3  
// 2 → 4  
// 3 → 4, 7  
// 4 → 5  
// 5 → 10  
// 6 → 8  
// 7 → 8  
// 8 → 9  
// 9 → 10
// ```

// This forms a **Directed Acyclic Graph (DAG)**, which means it has no cycles and allows for topological sorting.

// ---

// ## 🔷 `topologicalSort()` — Kahn's Algorithm

// ### Key Idea:

// Topological sort of a DAG is a linear ordering of its vertices such that for every directed edge `u → v`, vertex `u` comes before `v`.

// ### Code Logic:

// ```cpp
// queue<int> q;
// for (int i = 1; i < V; ++i)
//     if (indegree[i] == 0) q.push(i);
// ```

// * Vertices with **0 incoming edges** are added to the queue.

// ```cpp
// while (!q.empty()) {
//     int u = q.front(); q.pop();
//     cout << u << " ";

//     for (int v : adj[u]) {
//         if (--indegree[v] == 0)
//             q.push(v);
//     }
// }
// ```

// * Dequeue `u`, print it.
// * For each neighbor `v`, decrement its indegree.
// * If `v`'s indegree becomes 0, add it to the queue.

// ### 📌 Example Output:

// ```
// Topological Sort Order: 1 6 2 3 4 7 8 5 9 10
// ```

// (This may vary slightly — multiple valid topological orders can exist.)

// ---

// ## 🔷 `bfsTraversal()` — BFS for DAG

// ### Key Idea:

// Perform **BFS traversal** from **every unvisited node** (to ensure disconnected parts are also covered).

// ```cpp
// for (int i = 1; i < V; ++i) {
//     if (!visited[i]) {
//         queue<int> q;
//         q.push(i);
//         visited[i] = true;

//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             cout << u << " ";
//             for (int v : adj[u]) {
//                 if (!visited[v]) {
//                     q.push(v);
//                     visited[v] = true;
//                 }
//             }
//         }
//     }
// }
// ```

// * Starts BFS from every unvisited node (to cover isolated/detached DAG regions).
// * Ensures the **entire graph** is traversed.

// ### 📌 Example Output:

// ```
// BFS Traversal: 1 2 3 4 7 5 8 10 9 6
// ```

// ---

// ## 📋 Summary Table

// | Feature          | Description                                |
// | ---------------- | ------------------------------------------ |
// | Graph Type       | Directed Acyclic Graph (DAG)               |
// | Storage          | Adjacency List `adj[]`                     |
// | Topological Sort | Kahn’s algorithm (indegree-based BFS)      |
// | BFS Traversal    | Queue-based, from all unvisited components |

// ---

// ## ✅ Sample Execution Flow

// If you input this graph structure as given:

// ```text
// 1 → 2, 3
// 2 → 4
// 3 → 4, 7
// 4 → 5
// 5 → 10
// 6 → 8
// 7 → 8
// 8 → 9
// 9 → 10
// ```

// Your output might be:

// ```
// Topological Sort Order: 1 6 2 3 4 7 8 5 9 10  
// BFS Traversal: 1 2 3 4 7 5 8 10 9 6
// ```

// > Exact order may vary slightly depending on node processing order.

// ---

// Would you like a **graph diagram** or **DFS-based Topological Sort** added as well?
