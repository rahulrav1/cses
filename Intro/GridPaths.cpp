#include <bits/stdc++.h>
using namespace std;

int ans = 0;

vector<vector<bool>> vis(7, vector<bool>(7, false));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dir[4] = {"R", "U", "L", "D"};

unordered_map<string, int> dirToIdx= {
	{"R", 0},
	{"U", 1},
	{"L", 2},
	{"D", 3}
};

bool works(int x, int y) {
	if (x < 0 || x >= 7 || y < 0 || y >= 7) {
		return false;
	}	
	if (vis[x][y]) {
		return false;
	}
	return true;
}

bool goal(int x, int y) {
	return x == 0 && y == 6;
}

bool valid(int x) {
	return x >= 0 && x < 7;
}

void f(int x, int y, string& original, int idx) {
	if (idx == 48) {
		if (goal(x, y)) {
			ans += 1;
		}
		return;
	}

	if (vis[0][6]) {
		return;
	}

	if (original[idx] == '?') {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (works(nx, ny)) {
				vis[nx][ny] = true;
				f(nx, ny, original, idx + 1);
				vis[nx][ny] = false;
			}
		}
	} else {
		int dirIdx = dirToIdx[string(1, original[idx])];
		int nx = x + dx[dirIdx], ny = y + dy[dirIdx];
		if (works(nx, ny)) {
			vis[nx][ny] = true;
			f(nx, ny, original, idx + 1);
			vis[nx][ny] = false;
		}
	}
}

void solve() {
	string s;
	cin >> s;
	f(0, 0, s, 0);
	cout << ans << '\n';
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

