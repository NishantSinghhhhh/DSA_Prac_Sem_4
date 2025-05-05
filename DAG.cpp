#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V + 1); // Assuming 1-based indexing
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Topological Sort using Kahn's Algorithm
    void topologicalSort() {
        vector<int> inDegree(V + 1, 0);

        for (int u = 1; u <= V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= V; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        cout << "\nTopological Sort: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
        cout << endl;
    }

    // BFS traversal from each component
    void BFS() {
        vector<bool> visited(V + 1, false);
        cout << "\nBFS Traversal from all components: ";

        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    cout << u << " ";

                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // 10 nodes as per the diagram
    Graph g(10);

    // Edges from the test case image
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(5, 1);
    g.addEdge(5, 6);
    g.addEdge(6, 8);
    g.addEdge(3, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 10);
    g.addEdge(9, 4);
    g.addEdge(9, 10);

    g.topologicalSort();
    g.BFS();

    return 0;
}
