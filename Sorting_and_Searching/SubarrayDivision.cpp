#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int N, K;
 
const int mxN = 200005;
 
vector<ll> v(mxN, 0);
 
ll ans;

ll f(int idx, int subarrays, ll sum, ll rmax) {
	if (subarrays > K || subarrays + N - idx < K) {
		return LLONG_MAX;
	} else if (idx == N) {
		ans = min(ans, rmax);
		return rmax;
	} else if (sum >= ans || rmax >= ans) return LLONG_MAX;

	ll mn = LLONG_MAX;
	sum += v[idx];
	mn = min(f(idx + 1, subarrays, sum, max(rmax, sum)), 
				f(idx + 1, subarrays + 1, v[idx], max(rmax, v[idx])));
	return mn;
}

struct interval {
	int lo, hi; ll sum;
	bool operator<(const interval& y) const { return sum < y.sum; }
};
 
struct triple {
	int best; ll lsum, rsum;
};
 
 
triple split(int lo, int hi, ll sum) {
	ll diff = sum, lsum = 0, rsum = sum; int best = -1;
	ll best_lsum = 0, best_rsum = sum;
	for (int i = lo; i <= hi; i++) {
		lsum += v[i], rsum -= v[i];
		if (abs(lsum - rsum) < diff) {
			best_lsum = lsum, best_rsum = rsum;
			diff = abs(lsum - rsum);
			best = i;
		}
	}
	return {best, best_lsum, best_rsum};
}
 
void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	int cnt = 1; ll sum = 0;
	for (int i = 0; i < N; i++) sum += v[i];
	set<interval> s {{0, N - 1, sum}}; set<ll> elem {0};
	while (cnt++ < K) {
		int lo = s.rbegin() -> lo, hi = s.rbegin() -> hi;
		auto [best, lsum, rsum] = split(lo, hi, s.rbegin() -> sum);
		s.erase(--end(s));
		if (lo != best) s.insert({lo, best, lsum});
		else elem.insert({lsum});
		if (hi != min(best + 1, hi)) s.insert({best + 1, hi, rsum});
		else elem.insert({rsum});
	}
	ans = max(*elem.rbegin(), !s.empty() ? s.rbegin() -> sum : 0); // suboptimal ans
	f(0, 1, 0, 0);
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
 
