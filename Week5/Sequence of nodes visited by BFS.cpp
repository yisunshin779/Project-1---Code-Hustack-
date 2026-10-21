#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e5 + 5;
vector<int> adj[SZ];
int n, m, u, v;
bool visited[SZ] = {false};
void BFS(int start) {
	queue<int> q;
	q.push(start);
    visited[start] = true;
    while (!q.empty()) {
    	int u = q.front();
    	cout << u << " ";
    	q.pop();
    	for (auto x : adj[u]) {
    		if (!visited[x]) {
			    q.push(x);
                visited[x] = true;    		
    		}
    	}
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
    		BFS(i);
    	}
    }
}