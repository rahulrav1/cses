#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int mxN = 200005;
const int mxM = 200005;

vector<int> v(mxN), pos(mxN + 1);
vector<pair<int, int>> swaps(mxM);

bool ordered(int t) {
	return pos[max(2, t)] > pos[max(2, t) - 1];
}

void solve() {
	int N, M;
	cin >> N >> M;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		pos[v[i]] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> swaps[i].f >> swaps[i].s;
	}
	for (int i = 2; i <= N; i++) {
		if (pos[i] < pos[i - 1]) {
			ans++;
		}
	}
	for (int i = 0; i < M; i++) {
		// when we swap a number j with a number k,
		// these are affected:
		// pos[j] vs pos[j - 1]
		// pos[j + 1] vs pos[j]
		// pos[k] vs pos[k - 1]
		// pos[k + 1] vs pos[k]
		auto curr = swaps[i];
		int v1 = v[curr.f - 1], v2 = v[curr.s - 1];

		bool a = ordered(v1), b = ordered(v1 + 1), c = ordered(v2), d = ordered(v2 + 1);
		swap(v[curr.f - 1], v[curr.s - 1]);
		pos[v2] = curr.f - 1; pos[v1] = curr.s - 1;

		bool a2 = ordered(v1), b2 = ordered(v1 + 1), c2 = ordered(v2), d2 = ordered(v2 + 1);
		bool blook = true, dlook = true;
		
		if (abs(v1 - v2) == 1) {
			if (v1 + 1 == v2) {
				blook = false;
			} else {
				dlook = false;
			}
		}

		if (a && !a2) ans += 1;
		else if (!a && a2) ans -= 1;
		if (b && !b2 && v1 != 1 && v1 != N && blook) ans += 1;
		else if (!b && b2 && v1 != 1 && v1 != N && blook) ans -= 1;
		if (c && !c2 && max(2, v2) != max(2, v1)) ans += 1;
		else if (!c && c2 && max(2, v2) != max(2, v1)) ans -= 1;
		if (d && !d2 && v2 != 1 && v2 != N && dlook) ans += 1;
		else if (!d && d2 && v2 != 1 && v2 != N && dlook) ans -= 1;
		
		cout << ans << '\n';
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


