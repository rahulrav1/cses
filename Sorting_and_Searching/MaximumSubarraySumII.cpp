#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<ll> v(N), psums(N, 0);
	for (auto &a : v) cin >> a;
	psums[0] = v[0];
	for (int i = 1; i < N; i++) psums[i] = psums[i - 1] + v[i];
	ll ans = LLONG_MIN, sum = 0, r = 0; multiset<ll> ms;
	for (int i = 0; i < N; i++) {
		sum += v[i];
		if (i + 1 >= A) {
			ans = max(ans, max(sum, sum - (ms.empty() ? 0 : *ms.begin() - r)));
			ms.insert(psums[i + 1 - A]);
		}
		if (i + 1 >= B) {
			sum -= v[i + 1 - B], r += v[i + 1 - B];
			ms.erase(ms.lower_bound(psums[i + 1 - B]));
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

