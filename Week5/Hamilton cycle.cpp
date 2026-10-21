#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> adj;
vector<vector<int>> adjList;
vector<bool> visited;
bool dfs(int u, int count) {
    if (count == n) {
        return adj[u][1];
    }
    for (int v : adjList[u]) {
        if (!visited[v]) {
            visited[v] = true; 
            if (dfs(v, count + 1)) return true; 
            visited[v] = false; 
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    adj.assign(n + 1, vector<bool>(n + 1, false));
    adjList.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (!adj[u][v]) {
            adj[u][v] = adj[v][u] = true;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
    }
    if (n > 2) {
        for (int i = 1; i <= n; i++) {
            if (degree[i] < 2) {
                cout << 0 << "\n";
                return;
            }
        }
    }
    visited[1] = true;
    if (dfs(1, 1)) cout << 1 << "\n";
    else cout << 0 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; 
    while (t--) solve();
}