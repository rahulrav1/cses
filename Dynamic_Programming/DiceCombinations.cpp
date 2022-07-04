#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int N;
	cin >> N;
	vector<int> dp(N + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= min(i, 6); j++) {
			dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
	}
	cout << dp[N] << '\n';
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

