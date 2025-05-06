// You have a business with several offices; you want to lease phone lines to connect them up
// with each other; and the phone company charges different amounts of money to connect
// different pairs of cities. You want a set of lines that connects all your offices with a minimum
// total cost. Solve the problem by suggesting appropriate data structures (Prim’s algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int V = 9; // Total vertices in graph (0 to 8)

// Prim’s Algorithm function
void primMST(vector<pair<int, int>> adj[]) {
    vector<bool> inMST(V, false);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int totalCost = 0;
    pq.push({0, 0}); // {weight, vertex}

    cout << "Edges in MST:\n";

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += weight;

        // Print the selected edge (except for starting node 0)
        if (weight != 0)
            cout << "Include node: " << u << " with cost: " << weight << "\n";

        for (auto [v, w] : adj[u]) {
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    vector<pair<int, int>> adj[V];

    // Graph from the image (undirected)
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

    primMST(adj);

    return 0;
}
