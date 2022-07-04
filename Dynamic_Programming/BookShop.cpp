#include <bits/stdc++.h>
using namespace std;


void solve() {
	int N, X;
	cin >> N >> X;
	vector<int> prices(N), pages(N);
	for (auto &a : prices) cin >> a;
	for (auto &a : pages) cin >> a;
	// top-down allows us to use only a 1-D array
	// whereas bottom-up forces us to use a 2-D array
	vector<int> dp(X + 1, 0);
	for (int j = prices[0]; j <= X; j++) {
		dp[j] = pages[0];
	}
	for (int i = 1; i < N; i++) {
		for (int j = X - prices[i]; j >= 0; j--) {
			dp[j + prices[i]] = max(dp[j + prices[i]], dp[j] + pages[i]);
		}
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

