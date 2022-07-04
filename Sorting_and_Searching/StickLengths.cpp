#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost(ll len, vector<ll>& v) {
	ll sum = 0;
	for (auto &a : v) {
		sum += abs(a - len);
	}
	return sum;
}

void solve() {
	int N;
	cin >> N;
	vector<ll> v(N);
	ll mx = 0;
	for (auto &a : v) {
		cin >> a;
		mx = max(mx, a);
	}
	// ternary search solution
	ll lhs = 0, rhs = mx, ans = 1e16;
	while (lhs <= rhs) {
		ll mid = lhs + (rhs - lhs) / 2;
		ll cost1 = cost(mid, v), cost2 = cost(mid + 1, v);
		ans = min(ans, min(cost1, cost2));
		if (cost1 < cost2) {
			rhs = mid - 1;
		} else {
			lhs = mid + 1;
		}
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

