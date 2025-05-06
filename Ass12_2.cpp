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