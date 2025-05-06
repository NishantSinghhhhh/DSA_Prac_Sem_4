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
