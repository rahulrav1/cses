#include <bits/stdc++.h>
#define f first
#define s second
#define sz(a) ((int)a.size())
#define INF 1000000009
using namespace std;
using pi = pair<int, int>;


// answer should just be k largest disjoint intervals
// we want the movies that end the earliest, sort by end time

bool cmp(const pi& a, const pi& b) {
	return a.s == b.s ? a.f <= b.f : a.s <= b.s;
}	

void solve() {
	int N, K;
	cin >> N >> K;
	vector<pi> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].f >> v[i].s;
	sort(begin(v), end(v), cmp);
	int ans = 0; multiset<int> q; // NOTE: set doesn't work since there could be duplicate end times
	for (int i = 0; i < N; i++) {
		auto it = q.lower_bound(v[i].f);
		if (sz(q) == 0) q.insert(v[i].s), ans++;
		else if (it == end(q) || (*it > v[i].f && it != begin(q))) {
			q.erase(--it), q.insert(v[i].s), ans++;
		}
		else if (*it == v[i].f) q.erase(it), q.insert(v[i].s), ans++;
	  	else if (sz(q) < K) q.insert(v[i].s), ans++;	
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

