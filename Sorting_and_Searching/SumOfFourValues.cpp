#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pi = pair<ll, int>;
 
void update(int &i, int &j, int &lhs, int &rhs) {
	if (lhs == i) lhs++;
	if (lhs == j) lhs++;
	if (rhs == j) rhs--;
	if (rhs == i) rhs--;
}
 
void solve() {
	int N; ll X;
	cin >> N >> X;
	vector<ll> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
/*	vector<pi> v(N);
	sort(begin(v), end(v));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int lhs = 0, rhs = N - 1; ll base = v[i].f + v[j].f;
			update(i, j, lhs, rhs);
			while (lhs < rhs) {
				ll sum = base + v[lhs].f + v[rhs].f;
				if (sum == X) {
					cout << v[i].s << " " << v[j].s << " " 
						<< v[lhs].s << " " << v[rhs].s << '\n';
					return;
				} else if (sum < X) {
					lhs++;
				} else {
					rhs--;
				}
				update(i, j, lhs, rhs);
			}
		}
	} */
	unordered_map<ll, pi> mp;
	mp.reserve(1024);
	mp.max_load_factor(0.25);
 
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ll sum = v[i] + v[j];
			if (mp.count(X - sum)) {
				cout << (i + 1) << " " << (j + 1) << " "
						<< mp[X - sum].f << " " << mp[X - sum].s << '\n';
				return;
			}
		}
		// having j < i allows us to only store values to the left of i
		// and thus to the left of j in the map
		//
		// Purpose?
		// This allows us to access values in the map without having
		// if statement logic to check if any of the indices are the same.
		// The indices are guaranteed to not overlap with this approach. 
		for (int j = 0; j < i; j++) mp[v[i] + v[j]] = {i + 1, j + 1};
	}
 
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
