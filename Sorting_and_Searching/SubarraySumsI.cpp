#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
	int N; ll X;
	cin >> N >> X;
	vector<ll> v(N); unordered_map<ll, int> mp;
   	mp.reserve(1024); mp.max_load_factor(0.25);	
	for (int i = 0; i < N; i++) cin >> v[i];
/*	ll sum = 0; mp[0]++;
	for (int i = 0; i < N; i++) {
		sum += v[i];
		if (mp.count(sum - X)) {
			// this doesnt work because hwne sum = 2 * X
			// we are counting mp[2 * X - X] = mp[X] 
			// accidentally even if it may not exist
			mp[X]++;
		}
		if (X != sum) {
			mp[sum]++;
		}
	}
	cout << mp[X] << '\n'; */
	ll ans = 0, sum = 0; mp[0]++;
	for (int i = 0; i < N; i++) {
		sum += v[i];
		if (mp.count(sum - X)) {
			ans++;
		}
		mp[sum] = 1;
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
 

