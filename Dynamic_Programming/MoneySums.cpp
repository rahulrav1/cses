#include <bits/stdc++.h>
using namespace std;


void solve() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	int sum = 0;
	for (auto &a : v) sum += a;
	vector<bool> dp(sum + 1, false);
	dp[0] = dp[v[0]] = true;
	for (int i = 1; i < N; i++) {
		for (int j = sum - v[i]; j >= 0; j--) {
			dp[j + v[i]] = dp[j] || dp[j + v[i]];
		}
	}
	cout << count(begin(dp), end(dp), true) - 1 << '\n';
	for (int j = 1; j <= sum; j++) {
		if (dp[j]) cout << j << '\n';
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

