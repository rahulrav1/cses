#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[19][10][2][2];

ll f(string& s, int idx, int prev, bool lt, bool lz) {
    if (idx == (int)s.length()) return 1;
    if (prev != -1 && dp[idx][prev][lt][lz] != -1) return dp[idx][prev][lt][lz];
    int ub = lt ? 9 : s[idx] - '0';
    long long ans = 0;
    for (int i = 0; i <= ub; i++) {
        if ((i == 0 && lz) || i != prev) {
            ans += f(s, idx + 1, i, lt || i < (s[idx] - '0'), i == 0 && lz);
        }
    }
    return prev != -1 ? dp[idx][prev][lt][lz] = ans : ans;
}

void solve() {
	ll A, B;
    cin >> A >> B;
    string str_a = to_string(A - 1), str_b = to_string(B);
    memset(dp, -1, sizeof(dp));
    ll left = f(str_a, 0, -1, 0, 1);
    memset(dp, -1, sizeof(dp));
    ll right = f(str_b, 0, -1, 0, 1);
    cout << right - left << '\n';
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

