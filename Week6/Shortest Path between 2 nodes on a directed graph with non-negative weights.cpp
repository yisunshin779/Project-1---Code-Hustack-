#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e5 + 5;
int n, m, u, v, w, s, t;
vector<pair<int, int>> adj[SZ];
signed main() {
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> s >> t;
    vector<int> dist(n + 1, LLONG_MAX);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[t] << "\n";
}