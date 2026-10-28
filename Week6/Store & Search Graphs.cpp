#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
string getWLHash(int n, int m, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (const auto& e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<ull> color(n);
    for (int i = 0; i < n; ++i) {
        color[i] = splitmix64(adj[i].size());
    }
    int iterations = 4;
    while (iterations--) {
        vector<ull> next_color(n);
        for (int u = 0; u < n; ++u) {
            vector<ull> neighbor_colors;
            neighbor_colors.reserve(adj[u].size());
            for (int v : adj[u]) {
                neighbor_colors.push_back(color[v]);
            }
            sort(neighbor_colors.begin(), neighbor_colors.end());
            ull h = splitmix64(color[u]);
            for (ull nc : neighbor_colors) {
                h = splitmix64(h ^ (nc + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2)));
            }
            next_color[u] = h;
        }
        color = move(next_color);
    }
    sort(color.begin(), color.end());
    ull final_hash = 0;
    for (ull c : color) {
        final_hash = splitmix64(final_hash ^ (c + 0x9e3779b97f4a7c15ULL + (final_hash << 6) + (final_hash >> 2)));
    }
    return to_string(n) + "" + to_string(m) + "" + to_string(final_hash);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    unordered_set<string> graph_db;
    for (int k = 0; k < N; ++k) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
            --edges[i].first;
            --edges[i].second;
        }
        graph_db.insert(getWLHash(n, m, edges));
    }
    string sep;
    cin >> sep; 
    int K;
    cin >> K;
    while (K--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
            --edges[i].first;
            --edges[i].second;
        }
        string q_key = getWLHash(n, m, edges);
        cout << (graph_db.count(q_key) ? 1 : 0) << "\n";
    }
}