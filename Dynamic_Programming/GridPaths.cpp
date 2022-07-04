#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int N;
	cin >> N;
	vector<vector<char>> v(N, vector<char>(N));
	for (auto &a : v) {
		for (auto &b : a) cin >> b;
	}
	vector<vector<int>> dp(N, vector<int>(N, 0));
	for (int i = 0; i < N && v[i][0] != '*'; i++) {
		dp[i][0] = 1; 
	}
	for (int j = 0; j < N && v[0][j] != '*'; j++) {
		dp[0][j] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (v[i][j] != '*') dp[i][j] = (dp[i][j] + (dp[i - 1][j] + dp[i][j - 1]) % MOD) % MOD;
		}
	}
	cout << dp[N - 1][N - 1];
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

