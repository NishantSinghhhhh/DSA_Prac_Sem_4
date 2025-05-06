// Given a directed acyclic graph, a. write a program for topological ordering of vertices b. DFS
// traversal 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int V = 11; // Vertex count (1-indexed, so size is 11)

// Graph represented as adjacency list
vector<int> graph[V];
vector<bool> visited(V, false);

// DFS utility for Topological Sort
void topoSortUtil(int v, stack<int>& Stack) {
    visited[v] = true;

    for (int u : graph[v]) {
        if (!visited[u])
            topoSortUtil(u, Stack);
    }

    Stack.push(v);
}

// Perform Topological Sort
void topologicalSort() {
    stack<int> Stack;
    fill(visited.begin(), visited.end(), false);

    for (int i = 1; i <= 10; i++) {
        if (!visited[i])
            topoSortUtil(i, Stack);
    }

    cout << "Topological Order: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

// Simple DFS Traversal
void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int u : graph[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {
    // Graph edges based on the image
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[3].push_back(6);
    graph[4].push_back(8);
    graph[5].push_back(7);
    graph[6].push_back(9);
    graph[7].push_back(8);
    graph[8].push_back(10);

    // a. Topological Sort
    topologicalSort();

    // b. DFS Traversal
    fill(visited.begin(), visited.end(), false);
    cout << "DFS Traversal starting from node 1: ";
    dfs(1);
    cout << endl;

    return 0;
}


// This C++ program solves two key problems on a **Directed Acyclic Graph (DAG)**:

// ---

// ## ✅ Problem Goals

// ### a. **Topological Sort**

// * Linear ordering of vertices such that for every directed edge `u → v`, `u` comes **before** `v` in the ordering.

// ### b. **Depth First Search (DFS) Traversal**

// * Visit all nodes starting from a source using recursive DFS.

// ---

// ## 🔍 Line-by-Line Explanation

// ### 📦 Global Declarations

// ```cpp
// const int V = 11;
// vector<int> graph[V];          // Adjacency list for graph
// vector<bool> visited(V, false); // Visited tracking array
// ```

// * `V = 11` (1-indexed: vertex 1 to 10)
// * `graph[v]` stores a list of vertices that `v` has outgoing edges to.

// ---

// ## 🔁 a. Topological Sort

// ### 🔧 Helper: `topoSortUtil(v, Stack)`

// ```cpp
// void topoSortUtil(int v, stack<int>& Stack)
// ```

// * Recursively visits all unvisited neighbors of `v`.
// * After all neighbors are processed, `v` is pushed onto the stack.

// This ensures that **dependencies** of `v` come before `v` in the stack.

// ### 🧠 Main: `topologicalSort()`

// ```cpp
// for (int i = 1; i <= 10; i++) {
//     if (!visited[i])
//         topoSortUtil(i, Stack);
// }
// ```

// * Visits each unvisited vertex in the graph.
// * Prints the **reverse order** of completion (by popping the stack).

// ✅ Guarantees a valid **topological ordering**.

// ---

// ## 🔁 b. DFS Traversal

// ```cpp
// void dfs(int v)
// ```

// * Prints the current node and recursively visits its unvisited neighbors.

// This gives a standard **depth-first traversal path** from a given source node.

// ---

// ## 🔗 Edges Used

// From the input:

// ```
// graph[1] → {3, 4}
// graph[2] → {4}
// graph[3] → {5, 6}
// graph[4] → {8}
// graph[5] → {7}
// graph[6] → {9}
// graph[7] → {8}
// graph[8] → {10}
// ```

// This builds a **DAG** like:

// ```
// 1 → 3 → 5 → 7 → 8 → 10
// |         |         ^
// → 4 →─────┘         |
// 2 ─────→ 4          |
// 3 → 6 → 9           |
//                     |
// ---------------------
// ```

// ---

// ## 🧪 Sample Output

// **Topological Order:**

// ```
// 2 1 4 3 6 9 5 7 8 10
// ```

// (One valid output; actual order may vary depending on DFS branch order — multiple valid topological sorts exist.)

// **DFS from node 1:**

// ```
// 1 3 5 7 8 10 6 9 4
// ```

// (DFS visits nodes deeply before backtracking.)

// ---

// ## ✅ Summary

// | Feature             | Description                                |
// | ------------------- | ------------------------------------------ |
// | Topological Sort    | ✅ Correct implementation using DFS + stack |
// | DFS Traversal       | ✅ Recursive DFS with visited array         |
// | DAG Structure       | ✅ Maintained via adjacency list            |
// | Edge handling       | ✅ Directed edges only                      |
// | Graph visualization | 👁️ Easy to trace based on adjacency setup |

// ---

// Would you like to also implement:

// * **Kahn’s Algorithm** for topological sort (using in-degrees)?
// * **Cycle detection** in a directed graph?

// Let me know!
// Absolutely! Let's break it down in simple, clear parts:

// ---

// ## 🔍 **What is DFS (Depth-First Search)?**

// ### 📌 Definition:

// DFS is a **graph traversal** algorithm that:

// * Starts at a source vertex.
// * Visits as **deep** as possible along each branch **before backtracking**.

// ### 🔄 How It Works:

// 1. Visit the current node.
// 2. Mark it as visited.
// 3. Recursively visit all its unvisited neighbors.

// ### ✅ Use Cases:

// * Traversing all nodes
// * Path finding
// * Cycle detection
// * Topological sorting (like in your code)

// ---

// ## 🧩 **Function: `dfs(int v)`**

// ```cpp
// void dfs(int v) {
//     visited[v] = true;
//     cout << v << " ";

//     for (int u : graph[v]) {
//         if (!visited[u])
//             dfs(u);
//     }
// }
// ```

// ### 💡 Step-by-step:

// * `visited[v] = true`: Marks `v` as visited.
// * `cout << v << " "`: Prints the current node.
// * `for (int u : graph[v])`: Loops over all neighbors of `v`.
// * `if (!visited[u]) dfs(u)`: Recursively explores each unvisited neighbor `u`.

// It prints the **DFS traversal path** starting from vertex `v`.

// ---

// ## 🧠 **What is Topological Sort?**

// ### 📌 Definition:

// Topological sorting is **ordering of vertices** in a **Directed Acyclic Graph (DAG)** such that:

// > For every directed edge `u → v`, **`u` comes before `v`** in the ordering.

// ### ✅ Use Cases:

// * Task scheduling
// * Build system dependencies (e.g., `make`)
// * Course prerequisite planning

// ---

// ## 🧩 **Function: `topoSortUtil(int v, stack<int>& Stack)`**

// ```cpp
// void topoSortUtil(int v, stack<int>& Stack) {
//     visited[v] = true;

//     for (int u : graph[v]) {
//         if (!visited[u])
//             topoSortUtil(u, Stack);
//     }

//     Stack.push(v);
// }
// ```

// ### 💡 Step-by-step:

// 1. **Mark node as visited**: `visited[v] = true`.
// 2. **Recurse on all unvisited neighbors**:

//    * For each edge `v → u`, if `u` is not visited, call `topoSortUtil(u)`.
// 3. **After visiting all children**, **push `v` onto the stack**.

// This ensures:

// * `v` is added **after** all nodes reachable from it.
// * The **stack will store reverse of the topological order**.

// ---

// ## 🧩 **Function: `topologicalSort()`**

// ```cpp
// void topologicalSort() {
//     stack<int> Stack;
//     fill(visited.begin(), visited.end(), false);

//     for (int i = 1; i <= 10; i++) {
//         if (!visited[i])
//             topoSortUtil(i, Stack);
//     }

//     cout << "Topological Order: ";
//     while (!Stack.empty()) {
//         cout << Stack.top() << " ";
//         Stack.pop();
//     }
//     cout << endl;
// }
// ```

// ### 💡 Step-by-step:

// 1. **Reset visited array**.
// 2. **Loop over all vertices** (1 to 10 in your case):

//    * If a vertex is unvisited, call `topoSortUtil(i, Stack)`.
// 3. After DFS finishes for all nodes, the **stack holds the topological order** (in reverse).
// 4. **Pop the stack** to print topological ordering.

// ---

// ## ✅ Example

// Given edges:

// ```
// 1 → 3 → 5 → 7 → 8 → 10
// 2 → 4 → 8
// ```

// One topological sort could be:

// ```
// 2 1 3 5 7 4 8 10
// ```

// (Any order that respects dependencies is valid.)

// ---

// ## 🔁 Summary

// | Concept                 | Role                                                 |
// | ----------------------- | ---------------------------------------------------- |
// | **DFS**                 | Visits nodes deeply before backtracking              |
// | **`dfs()`**             | Used to print nodes in DFS order                     |
// | **`topoSortUtil()`**    | Recursive helper to perform DFS for topological sort |
// | **`topologicalSort()`** | Initiates the sort and prints the final order        |

// ---

// Would you like a **diagram** showing how the graph is visited step-by-step during topological sort or DFS?
