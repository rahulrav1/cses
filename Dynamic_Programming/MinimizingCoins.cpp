#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int N; ll X;
	cin >> N >> X;
	vector<ll> v(N);
	for (auto &a : v) cin >> a;
	vector<ll> dp(X + 1, LLONG_MAX);
	dp[0] = 0;
	for (int i = 1; i <= X; i++) {
		for (auto &a : v) {
			if (a <= i && dp[i - a] != LLONG_MAX) dp[i] = min(dp[i], dp[i - a] + 1);
		}
	}
	cout << (dp[X] == LLONG_MAX ? -1 : dp[X]) << '\n';
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

