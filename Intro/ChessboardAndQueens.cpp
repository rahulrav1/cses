#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<string> v(N);

bool canPlace(int row, int col, vector<vector<bool>>& board) {
	if (v[row][col] == '*') {
		return false;
	}
	for (int i = 0; i < N; i++) {
		if (board[i][col]) {
			return false;
		}
	}
	for (int j = 0; j < N; j++) {
		if (board[row][j]) {
			return false;
		}
	}
	int sx = row - min(row, col);
	int sy = col - min(row, col);
	while (sx < N && sy < N) {
		if (board[sx][sy]) {
			return false;
		}
		sx++, sy++;
	}
	sx = row - min(row, N - col - 1);
	sy = col + min(row, N - col - 1);
	while (sx < N && sy >= 0) {
		if (board[sx][sy]) {
			return false;
		}
		sx++, sy--;
	}
	return true;
}

int f(int col, vector<vector<bool>>& board) {
	if (col == N) {
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (canPlace(i, col, board)) {
			board[i][col] = 1;
			ans += f(col + 1, board);
			board[i][col] = 0;
		}
	}
	return ans;
}

void solve() {
	for (auto &a : v) {
		cin >> a;
	}
	vector<vector<bool>> board(N, vector<bool>(N, false));
	cout << f(0, board) << '\n';
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

