#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;

void solve() {
	int N; ll X;
	cin >> N >> X;
	vector<ll> v(N);
	unordered_map<ll, queue<int>> mp;
	mp.reserve(1024); // to prevent TLE when hashing large numbers
	mp.max_load_factor(0.25); // ^
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (mp[v[i]].size() <= 1) {
			mp[v[i]].push(i + 1);
		}
	}
/*	sort(begin(v), end(v));
	int lhs = 0, rhs = N - 1;
	while (lhs < rhs) {
		if (v[lhs].f + v[rhs].f == X) {
			cout << v[lhs].s << " " << v[rhs].s << '\n';
			return;
		} else if (v[lhs].f + v[rhs].f < X) {
			lhs++;
		} else {
			rhs--;
		}
	}
*/
	for (int i = 0; i < N; i++) {
		if (mp.count(X - v[i])) {
			if (X == 2 * v[i] && mp[v[i]].size() > 1) {
				if (mp[v[i]].front() == i + 1) {
					mp[v[i]].pop();
				} 
				cout << (i + 1) << " " << mp[v[i]].front() << '\n';
				return;
			} else if (X != 2 * v[i]) {
				cout << (i + 1) << " " << mp[X - v[i]].front() << '\n'; 
				return;
			}
		}
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

