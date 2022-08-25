#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& comp) {
	vis[u] = true;
	comp.push_back(u);
	for (int &v : adj[u]) {
		if (!vis[v]) {
			dfs(v, adj, vis, comp);
		}
	}
}

void solve() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(N + 1, false);
	vector<vector<int>> comps;
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			vector<int> comp;
			dfs(i, adj, vis, comp);
			comps.push_back(comp);
		}
	}
	cout << comps.size() - 1 << '\n';
	for (int i = 1; i < (int)comps.size(); i++) {
		cout << comps[i][0] << " " << comps[i - 1][0] << '\n';
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
//	cin >> T;	
	while (T--) {
		solve();
	}
}

