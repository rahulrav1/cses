#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
	int N; ll X;
	cin >> N >> X;
	vector<ll> v(N); unordered_map<ll, ll> mp;
   	mp.reserve(1024); mp.max_load_factor(0.25);	
	for (int i = 0; i < N; i++) cin >> v[i];
	ll ans = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		sum += v[i];
		if (mp.count(sum - X)) ans += mp[sum - X]; 
		if (sum == X) ans++;
		mp[sum]++;
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
 
