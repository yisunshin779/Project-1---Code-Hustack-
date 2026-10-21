#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e5 + 5;
vector<int> adj[SZ];
int n, m, u, v;
bool visited[SZ] = {false};
void DFS(int start) {
    visited[start] = true;
    cout << start << " ";
    for (auto x : adj[start]) {
        if (!visited[x]) DFS(x);
    }
}
signed main() {
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
    	sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 1; i <= n; i++) {
    	if (!visited[i]) {
    		DFS(i);
    	}
    }
}