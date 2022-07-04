#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

void solve() {
	int N;
	cin >> N;
	vector<int> v(N), pos(N + 1);
	int ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		pos[v[i]] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (pos[i] < pos[i - 1]) {
			ans++;
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

