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
	for (int i = 0; i < N; i++) {
		cin >> v[i].f.f >> v[i].f.s;
		v[i].s = i;
	}

	// This is a special sort that propagates the
	// intervals with larger right endpoints forward
	// in the sorted array when the starting points of two intervals are equal
	//
	// What's the purpose of this?
	// It allows us to get rid of extra if statement logic such as manually setting
	// values in our answer arrays when v[i].f.f == v[i + 1].f.f or
	// v[i - 1].f.f == v[i].f.f
	//

	sort(begin(v), end(v), [&](pii x, pii y) {
		return x.f.f == y.f.f ? x.f.s > y.f.s : x.f.f < y.f.f; 		
	});

	vector<bool> contains(N, 0), contained(N, 0);
/*	multiset<int> left, right;

	for (int i = 0; i < N; i++) left.insert(v[i].f.s), right.insert(v[i].f.s);

	for (int i = 0; i < N; i++) {
		right.erase(right.lower_bound(v[i].f.s));
		auto it = right.lower_bound(v[i].f.s);
		if ((it != begin(right) && !right.empty())
				|| (it == begin(right) && *it <= v[i].f.s && !right.empty()) 
				|| (i - 1 >= 0 && v[i - 1].f.f == v[i].f.f)) {
			contains[v[i].s] = 1;
		} 
	}

	for (int i = N - 1; i >= 0; i--) {
		left.erase(left.lower_bound(v[i].f.s));
		auto it = left.lower_bound(v[i].f.s);
		if (it != end(left)
				|| (i + 1 < N && v[i].f.f == v[i + 1].f.f)) {
			contained[v[i].s] = 1;
		}
	} */


	int mn = INT_MAX, mx = INT_MIN;

	for (int i = N - 1; i >= 0; i--) {
		if (v[i].f.s >= mn) {
			contains[v[i].s] = 1;
		}
		mn = min(mn, v[i].f.s);
	}

	for (int i = 0; i < N; i++) {
		if (v[i].f.s <= mx) {
			contained[v[i].s] = 1;
		}
		mx = max(mx, v[i].f.s);
	}


	for (int i = 0; i < N; i++) {
		cout << contains[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << contained[i] << " ";
	}
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

