#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

// easier to visualize how to solve using recursion + memoization 
// as opposed to an iterative dp table

pl dp[5005][5005] = {};	// for memoization
pl dp2[5005][5005] = {};

pl find(int lhs, int rhs, int turn, vector<ll>& v) {
	if (rhs < lhs) return {0, 0};
	if (turn && dp[lhs][rhs] != make_pair(0LL, 0LL)) return dp[lhs][rhs];
	if (!turn && dp2[lhs][rhs] != make_pair(0LL, 0LL)) return dp2[lhs][rhs];
	pl take_left = find(lhs + 1, rhs, turn ^ 1, v), take_right = find(lhs, rhs - 1, turn ^ 1, v);

	if (turn) take_left.f += v[lhs], take_right.f += v[rhs];
	else take_left.s += v[lhs], take_right.s += v[rhs];

	if (turn) return dp[lhs][rhs] = max(take_left, take_right);
	else if (take_left.s > take_right.s) return dp2[lhs][rhs] = take_left;
	else return dp2[lhs][rhs] = take_right;
}

void solve() {
	int N;
	cin >> N;
	vector<ll> v(N);
	for (auto &a : v) cin >> a;
	cout << find(0, N - 1, 1, v).f;
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

