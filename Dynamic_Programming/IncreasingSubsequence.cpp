#include <bits/stdc++.h>
using namespace std;


void solve() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	vector<int> LIS;
	for (int i = 0; i < N; i++) {
		auto it = lower_bound(begin(LIS), end(LIS), v[i]);
		if (it == end(LIS)) {
			LIS.push_back(v[i]);
		} else {
			LIS[it - begin(LIS)] = v[i];
		}
	}
	cout << LIS.size();
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

