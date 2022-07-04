#include <bits/stdc++.h>
#define sz(a) ((ll)a.size())
using namespace std;
using ll = long long;

/*
 *	5 2
 *	1 2 3 1 1
 */

const int mxN = 200005;

vector<int> v(mxN, 0);

int N, K;

bool go(unordered_set<int>& s, int& r, int& K) {
	return ((sz(s) < K && !s.count(v[r + 1])) || (sz(s) <= K && s.count(v[r + 1])));
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	int r = -1; ll ans = 0;;
	unordered_map<int, int> mp; mp.reserve(1024); mp.max_load_factor(0.25);
	unordered_set<int> s; s.reserve(1024); s.max_load_factor(0.25);
	for (int i = 0; i < N; i++) {
		while (r < N - 1 && go(s, r, K)) {	// move right pointer as far as possible
			s.insert(v[++r]); mp[v[r]]++;
		}
		ans += r - i + 1;
		if (mp[v[i]] == 1) s.erase(v[i]);
		mp[v[i]]--;
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

