#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool works(int x, int y, vector<string>& grid, vector<vector<bool>>& vis) {
	if (x < 0 || x >= vis.size() || y < 0 || y >= vis[0].size()) return false;
	if (vis[x][y] || grid[x][y] == '#') return false;
	return true;
}

void dfs(int x, int y, vector<string>& grid,  vector<vector<bool>>& vis) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (works(nx, ny, grid, vis)) {
			dfs(nx, ny, grid, vis);
		}
	}
}


void solve() {
	int N, M;
	cin >> N >> M;
	vector<string> v(N);
	vector<vector<bool>> vis(N, vector<bool>(M, false));
	int ans = 0;
	for (auto &a : v) cin >> a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j] && v[i][j] == '.') {
				dfs(i, j, v, vis);
				ans++;
			}
		}
	}
	cout << ans;
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

