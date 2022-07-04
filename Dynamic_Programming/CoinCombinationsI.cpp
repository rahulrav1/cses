#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int N, X;
	cin >> N >> X;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	vector<int> dp(X + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= X; i++) {
		for (auto &a : v) if (i >= a) dp[i] = (dp[i] + dp[i - a]) % MOD; 
	}
	cout << dp[X];
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

