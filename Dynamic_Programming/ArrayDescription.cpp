#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	vector<vector<int>> dp(N, vector<int>(M + 1, 0)); // num arrays formed by placing an
													  // j at position i
	if (v[0] == 0) {
		for (int j = 1; j <= M; j++) {
			dp[0][j] = 1;
		}
	} else {
		dp[0][v[0]] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			if (v[i] != 0) {
				for (int k = v[i] - 1; k <= v[i] + 1; k++) {
					if (k >= 1 && k <= M) {
						dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][k]) % MOD;
					}
				}
				break;
			}
			for (int k = j - 1; k <= j + 1; k++) {
				if (k >= 1 && k <= M) {
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int j = 1; j <= M; j++) {
		ans = (ans + dp[N - 1][j]) % MOD;
		if (ans >= MOD) ans -= MOD;
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

