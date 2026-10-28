#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e4 + 5;
int n, m, u, v, w, a[SZ][SZ];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = -1;
		}
	}
	while (m--) {
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == -1) a[i][j] = 1e9;
			if (i == j) a[i][j] = 0;
		}
	}
	for (int via = 1; via <= n; via++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][via] + a[via][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1e9) a[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
