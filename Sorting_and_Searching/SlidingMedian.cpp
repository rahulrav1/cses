#include <bits/stdc++.h>
#define sz(a) (ll)a.size()
using namespace std;


void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
//	priority_queue<int> bot; priority_queue<int, vector<int>, greater<int>> top;
	multiset<int> bot, top;	// bot stores smallest K/2 or K/2 + 1 values 
						// and top stores largest K/2 or K/2 - 1 values
	for (int i = 0; i < K; i++) {
		bot.insert(v[i]), top.insert(v[i]);
	}
	for (int i = 0; i < K / 2; i++) {
		bot.erase(--bot.end()), top.erase(top.begin());
	}
	if (K % 2 != 0) top.erase(top.begin());
	cout << *bot.rbegin() << '\n';
	// set<int> lazy; // lazily delete elements from pq, messes with size of heaps
	for (int i = K; i < N; i++) {
		if (v[i] <= *bot.rbegin()) {
			// using lower_bound as opposed to find doesn't work here
			// since we are looking for an exact match,
			// lower_bound could still reutrn an iterator that isn't
			// equal to bot.end() if a value larger than v[i - K]
			// exists in bot, we only care if an exact match to v[i - K]
			// exists in the multiset
			if (bot.find(v[i - K]) != bot.end()) {	
				bot.erase(bot.lower_bound(v[i - K]));
				bot.insert(v[i]);
			} else {
				top.erase(top.lower_bound(v[i - K]));
				bot.insert(v[i]);
				top.insert(*bot.rbegin());
				bot.erase(--bot.end());
			}
		} else {
			if (top.find(v[i - K]) != top.end()) {
				top.erase(top.lower_bound(v[i - K]));
				top.insert(v[i]);
			} else {
				bot.erase(bot.lower_bound(v[i - K]));
				top.insert(v[i]);
				bot.insert(*top.begin());
				top.erase(top.begin());
			}
		}
		cout << *bot.rbegin() << '\n';
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

