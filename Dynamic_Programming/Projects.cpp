#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pi = pair<int, int>;
using pii = pair<pi, int>;
 
 
void solve() {
	int N;
	cin >> N;
	vector<pii> v(N);
	for (auto &a : v) {
		cin >> a.f.f >> a.f.s >> a.s;
	}
	sort(begin(v), end(v));
	vector<int> dp(N, 0);
	dp[0] = v[0].s;
	for (int i = 1; i < N; i++) {
		dp[i] = v[i].s;
		for (int j = 0; j < i; j++) {
			if (v[i].f.f > v[j].f.s) {
				dp[i] = max(dp[i], dp[j] + v[i].s);
			}
		}
		assert(dp[i] >= dp[i - 1]);
	}
	cout << *max_element(begin(dp), end(dp));
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
