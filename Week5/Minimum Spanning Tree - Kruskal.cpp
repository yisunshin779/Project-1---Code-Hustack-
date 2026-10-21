#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
	int u, v, weight;
};

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

const int SZ = 1e5 + 5;
int parent[SZ], rank1[SZ];

void MakeSet(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank1[i] = 0;
	}
}

int find(int u) {
	if (u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

void UnionSets(int u, int v) {
	int pu = find(u);
	int pv = find(v);
	if (rank1[pu] < rank1[pv]) parent[pu] = pv;
	else if (rank1[pu] > rank1[pv]) parent[pv] = pu;
	else {
		parent[pv] = pu;
		rank1[pu]++;
	}
}

int Kruskal(int n, vector<Edge>& edges) {
	sort(edges.begin(), edges.end(), cmp);
	MakeSet(n);
	int mst_weight = 0;
	vector<Edge> mst;
	for (Edge e : edges) {
		if (find(e.u) != find(e.v)) {
			mst.push_back(e);
			mst_weight += e.weight;
			UnionSets(e.u, e.v);
		}
	}
	return mst_weight;
}

signed main() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	int totalweight = Kruskal(n, edges);
	cout << totalweight << "\n";
}