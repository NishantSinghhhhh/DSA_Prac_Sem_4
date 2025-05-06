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
