#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int N;
	cin >> N;
	vector<ll> v(N);
	for (auto &a : v) {
		cin >> a;
	}
	ll best = v[0], ans = v[0];
	for (int i = 1; i < N; i++) {
		if (v[i] + best >= v[i]) {
			best += v[i];
		} else {
			best = v[i];
		}
		ans = max(ans, best);
	}
	cout << ans << '\n';
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

