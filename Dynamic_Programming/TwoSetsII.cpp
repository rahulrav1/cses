#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MOD_INV = 5e8 + 4; // modinv of 2 w.r.t MOD, calculated using planetcalc.com

// a/b % MOD = ((a % MOD) * (modular inverse of b % MOD)) % MOD 

void solve() {
	int N;
	cin >> N;
	vector<int> v(N);
	iota(begin(v), end(v), 1);
	int sum = (N * (N + 1)) / 2;
	if (sum % 2 != 0) {
		cout << 0;
		return;
	}
	sum /= 2;
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = sum - v[i]; j >= 0; j--) {
			dp[j + v[i]] = (dp[j] + dp[j + v[i]]) % MOD;
		}
	}
	cout << (ll)dp[sum] * (ll)MOD_INV % (ll)MOD;
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

