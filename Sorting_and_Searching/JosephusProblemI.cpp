#include <bits/stdc++.h>
using namespace std;


void solve() {
	int N;
	cin >> N;
//	vector<int> v(N);
//	vector<bool> seen(N, false);
//	iota(begin(v), end(v), 1);
	if (N == 1) {
		cout << 1 << '\n';
		return;
	}
/*	int idx = 1, cnt = 0;
	while (cnt++ < N) {
		cout << v[idx] << '\n';
		if (cnt == N) break;
		seen[v[idx]] = true;
		while (seen[v[idx]]) idx = (idx + 1) % N; // takes to first person I havent seen
		idx = (idx + 1) % N;
		while (seen[v[idx]]) idx = (idx + 1) % N; // takes to second person I havent seen
	}*/
	set<int> s;
	for (int i = 1; i <= N; i++) s.insert(i);
	auto it = ++begin(s);
	while (!s.empty()) {
		if (it == end(s)) it = begin(s);
		cout << *it << '\n';
		s.erase(it++);
		if (s.empty()) break;
		if (it == end(s)) it = begin(s);
		it++;
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

