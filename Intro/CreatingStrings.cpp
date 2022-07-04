#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> freq;
vector<char> order;
vector<string> ans;

void f(string curr, int N) {
	if ((int)curr.length() == N) {
		ans.push_back(curr);
		return;
	}
	for (auto& a : order) {
		if (freq[a] > 0) {
			freq[a]--;
			f(curr + string(1, a), N);
			freq[a]++;
		}
	}
}


void solve() {
	string s;
	cin >> s;
	for (auto& a : s) {
		freq[a]++;
		if (freq[a] == 1) {
			order.push_back(a);
		}
	}
	sort(begin(order), end(order));
	f("", (int)s.length());
	cout << ans.size() << '\n';
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

