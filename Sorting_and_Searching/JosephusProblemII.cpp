#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


/*
 *	Note: In order to get pbds to work when compiling, I can't compile inside of vim.
 *	Open terminal and compile using g++-11 like this:
 *	/usr/local/bin/g++-11 JosephusProblemII.cpp -o JosephusProblemII
 *	Then execute like so: ./JosephusProblemII
 */ 


void solve() {
	int N, K;
	cin >> N >> K;
//	K %= N;
	/* vector<int> prev(N + 1, 0), next(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		prev[i] = i - K - 1 <= 0 ? N - K + (i - 1) : i - K - 1, next[i] = ((i + K) % N) + 1;
	}
	int s = K + 1, cnt = 0;
	while (cnt++ < N) {
		cout << s << '\n';
		next[prev[s]] = next[s]; // similar to deleting a middle element in linkedlist and 
								 // changing pointers
		prev[next[s]] = prev[s];
		s = next[s];
	}*/
	ordered_set oset;
	for (int i = 1; i <= N; i++) oset.insert(i);
	int idx = K % N;
	while (!oset.empty()) {
		auto it = oset.find_by_order(idx);
		cout << *it << '\n';
		oset.erase(it);
		if (oset.empty()) break;
		idx = (idx + K) % (int)oset.size();
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

