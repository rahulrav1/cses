#include <bits/stdc++.h>
using namespace std;


void solve() {
	int A, B;
	cin >> A >> B;
	vector<vector<int>> dp(A + 1, vector<int>(B + 1, INT_MAX));
	for (int j = 1; j <= B; j++) {
		dp[1][j] = j - 1;
	}	
	for (int i = 2; i <= A; i++) {
		for (int j = 1; j <= B; j++) {
			if (i == j) dp[i][j] = 0;
			else {
				for (int k = 1; k < max(i, j); k++) {
					if (i > j) {
						dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
					}
					else {
						dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
					}
				}
				for (int k = 1; k < min(i, j); k++) {
					if (i < j) {
						dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
					} else {
						dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
					}
				}
			}
		}
	}
	cout << dp[A][B];
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

