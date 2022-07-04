#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll N;
	cin >> N;
	vector<ll> v(N); unordered_map<ll, ll> mp;
	for (auto &a : v) cin >> a;
	ll sum = 0, ans = 0; mp[0]++;
	// figure out why negative numbers dont work
	for (int i = 0; i < N; i++) {
		sum += v[i]; 
		/*
		 *	If sum < N, then we can either remove sum from the current sum OR
		 *	we can take out sum - N (which will be negative) from the current sum
		 *	Taking out sum - N, since it is negative, increases the value of our sum
		 *	by -(sum - N)
		 *
		 *  If sum > N, then we can remove sum % N from the current sum OR
		 *  we can take out sum % N - N in order to increase our sum by
		 *  N - (sum % N - N) and make it divisble by N
		 */
		ans += mp[sum % N] + mp[sum % N  < 0 ? sum % N + N : sum % N - N];
		mp[sum % N]++;
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

