#include <bits/stdc++.h>
using namespace std;

unordered_set<string> seen;
vector<string> ans;

void f(string curr, int N) {
	for (int i = curr.length() - 1; i >= 0; i--) {
		curr[i] = curr[i] == '1' ? '0' : '1';
		if (seen.count(curr)) {
			curr[i] = curr[i] == '1' ? '0' : '1';
		} else {
			ans.push_back(curr);
			seen.insert(curr);
			f(curr, N);
		}
	}		
}

void solve() {
	int N;
	cin >> N;
	string start(N, '0');
	ans.push_back(start);
	seen.insert(start);

/*	int count = 1;
	while (count < 1 << N) {
		string curr = ans[count - 1];
		for (int i = curr.length() - 1; i >= 0; i--) {
			curr[i] = curr[i] == '1' ? '0' : '1';
			if (seen.count(curr)) {
				curr[i] = curr[i] == '1' ? '0' : '1';
			} else {
				ans.push_back(curr);
				seen.insert(curr);
				count += 1;
				break;
			}
		}		
	}
*/

	f(start, N);

	for (auto& a : ans) {
		cout << a << '\n';
	}
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

