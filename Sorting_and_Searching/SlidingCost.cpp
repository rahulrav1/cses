#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
 *	let m = median
 *
 *	left = sum of m - v[i] for all v[i] <= m
 *	right = sum of v[i] - m for all v[i] > m
 *	cost = left + right
 *
 *	now median = m + 2
 *	left = sum of m + 2 - v[i] = 2 * # of v[i] <= m + sum of m - v[i]
 *	right = sum of v[i] - m - 2 = sum of v[i] - m - 2 * # of v[i] > m
 *
 *
 *	bot multiset always has K/2 or K/2 + 1 elements
 *	top multiset always has K/2 or K/2 - 1 elements
 *
 *
 *	8 3
 *	2 4 3 5 8 1 2 1
 *
 *	m = 3
 *	[2, 4, 3]
 *	left = 1
 *	right = 1
 *	ans = 3
 *
 *	[4, 3, 5]
 *	left = left - 1 = 0, left = left + 
 *	right = right + 2 = 3
 *
 */

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (auto &a : v) cin >> a;
	multiset<int> bot, top;	 
	for (int i = 0; i < K; i++) bot.insert(v[i]), top.insert(v[i]);
	for (int i = 0; i < K / 2; i++) bot.erase(--bot.end()), top.erase(top.begin());
	if (K % 2 != 0) top.erase(top.begin());
	ll left = 0, right = 0, med = *bot.rbegin();
	for (auto &a : bot) left += med - a;
	for (auto &a : top) right += a - med;
	cout << (left + right) << '\n';
	for (int i = K; i < N; i++) {
		if (v[i] <= *bot.rbegin()) {
			if (bot.find(v[i - K]) != bot.end()) {	
				left -= (med - v[i - K]);
				bot.erase(bot.lower_bound(v[i - K]));
				bot.insert(v[i]);
				left += (med - v[i]);
			} else {
				right -= (v[i - K] - med);
				top.erase(top.lower_bound(v[i - K]));
				left += (med - v[i]);
				bot.insert(v[i]);
				top.insert(*bot.rbegin());
				right += (*bot.rbegin() - med);
				left -= (med - *bot.rbegin());
				bot.erase(--bot.end());
			}
		} else {
			if (top.find(v[i - K]) != top.end()) {
				right -= (v[i - K] - med);
				top.erase(top.lower_bound(v[i - K]));
				right += (v[i] - med);
				top.insert(v[i]);
			} else {
				left -= (med - v[i - K]);
				bot.erase(bot.lower_bound(v[i - K]));
				right += (v[i] - med);
				top.insert(v[i]);
				left += (med - *top.begin());
				right -= (*top.begin() - med);
				bot.insert(*top.begin());
				top.erase(top.begin());
			}
		}
		ll diff = *bot.rbegin() - med;
		left += diff * bot.size();
		right -= diff * top.size();
		med = *bot.rbegin();
		cout << (left + right) << '\n';
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

