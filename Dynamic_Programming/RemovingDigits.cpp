#include <bits/stdc++.h>
using namespace std;


void solve() {
	int N;
	cin >> N;
	vector<int> dp(N + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= min(9, N); i++) dp[i] = 1; 
	for (int i = 10; i <= N; i++) {
		string s = to_string(i);
		for (char &c : s) {
			dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
		}	
	}
	cout << dp[N];
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

