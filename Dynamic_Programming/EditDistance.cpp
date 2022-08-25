#include <bits/stdc++.h>
#define sz(a) (int(a.size()))
using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
    vector<vector<int>> dp(sz(s) + 1, vector<int>(sz(t) + 1, 0));
    dp[1][1] = s[0] != t[0];
    for (int i = 1; i <= sz(s); i++) {
        for (int j = 1; j <= sz(t); j++) {
            if (i > 1) dp[i][j] = dp[i - 1][j] + 1;
            if (j > 1) dp[i][j] = i > 1 ? min(dp[i][j], dp[i][j - 1] + 1) : dp[i][j - 1] + 1;
            if (i > 1 && j > 1) dp[i][j] = min(dp[i][j], (s[i - 1] != t[j - 1]) + dp[i - 1][j - 1]);
            else if (s[i - 1] == t[j - 1] && (i > 1 || j > 1)) dp[i][j] = max(i - 1, j - 1);
        }
    }
    cout << dp[sz(s)][sz(t)];
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

