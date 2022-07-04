#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pi = pair<ll, int>;


void solve() {
	int N; ll X;
	cin >> N >> X;
	vector<pi> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].f, v[i].s = i + 1;
	sort(begin(v), end(v));
	for (int i = 0; i < N; i++) {
		int lhs = 0, rhs = N - 1;
		if (lhs == i) lhs++;
		if (rhs == i) rhs--;
		while (lhs < rhs) {
			ll sum = v[lhs].f + v[rhs].f + v[i].f;
			if (sum == X) {
				cout << v[lhs].s << " " << v[rhs].s << " " << v[i].s << '\n';
				return;
			}
			else if (sum < X) lhs++;
			else rhs--;
			if (lhs == i) lhs++;
			if (rhs == i) rhs--;
		}
	}

/*	unordered_map<ll, int> mp;
	mp.reserve(1024); // to prevent TLE when hashing large numbers
	mp.max_load_factor(0.25); // to prevent TLE when hashing large numbers
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ll diff = X - v[i].f - v[j].f;
			if (mp.count(diff)) {
				cout << v[i].s << " " << v[j].s << " " << mp[diff] << '\n';
				return;
			}
		}
		mp[v[i].f] = i + 1;
	}*/

	cout << "IMPOSSIBLE" << '\n';
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

