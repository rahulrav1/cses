#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
 
void solve() {
	int N, X;
	cin >> N >> X;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	vector<pi> dp(1 << N, {N, X});
	dp[0] = {0, X};
	for (int m = 0; m < (1 << N); m++) {
		for (int i = 0; i < N; i++) {
			if (!(m & (1 << i))) {
				pair<int, int> cand = dp[m];
				if (dp[m].second + v[i] <= X) {
					cand.second += v[i];
				} else {
					cand.first += 1;
					cand.second = v[i];
				}	
				if (cand.first < dp[m | (1 << i)].first 
						|| (cand.first == dp[m | (1 << i)].first 
							&& cand.second < dp[m | (1 << i)].second)) {
					dp[m | (1 << i)] = cand;
				}
			}
		}
	}
	cout << dp[(1 << N) - 1].first;
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
 
