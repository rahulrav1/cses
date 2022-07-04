#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int N, X;
	cin >> N >> X;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	vector<int> dp(X + 1, 0);
	for (int j = 0; j <= X; j++) {
		if (j % v[0] == 0) dp[j] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= X; j++) {
			if (j >= v[i]) {
				dp[j] += dp[j - v[i]];
				if (dp[j] >= MOD) dp[j] -= MOD;
			}
		}
	}
	cout << dp[X] << '\n';
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

