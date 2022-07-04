#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pi = pair<int, int>;

void solve() {
	int N;
	cin >> N;
	vector<int> v(N), ans(N, 0); stack<int> s; s.push(v[0]);
	for (auto &a : v) cin >> a;
	for (int i = 1; i < N; i++) {
		while (!s.empty() && v[s.top()] >= v[i]) s.pop();
		if (!s.empty()) ans[i] = s.top() + 1;
		s.push(i);
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << '\n';
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

