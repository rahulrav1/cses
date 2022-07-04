#include <bits/stdc++.h>
#define pi pair<int, int>
#define f first
#define s second
using namespace std;

// stacks[i][0..2] contains order of stack from top to bottom

vector<pi> moves;

// this recursive solution works because we utilize the solution for N - 1 rods to obtain the solution
// for N rods
// we account for the Nth rod by simply moving it to the desired position after moving the N - 1 other
// rods to the other position

void find(int start, int end, int N) {
	if (N == 1) {
		moves.push_back({start + 1, end + 1});
		return;
	}
	int other = 3 - (start + end); // the other rod (the rod that isn't start or end)
	find(start, other, N - 1); // move N - 1 of the towers to the other rod
	moves.push_back({start + 1, end + 1}); // move the remaining tower to the end, its the biggest tower
	find(other, end, N - 1); // now move the N - 1 towers from the other rod to the end
}


void solve() {
	int N;
	cin >> N;
	find(0, 2, N);
	cout << moves.size() << '\n';
	for (auto& m : moves) {
		cout << m.f << " " << m.s << '\n';
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

