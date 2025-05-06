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
