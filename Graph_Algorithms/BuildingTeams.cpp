#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> color(100005, -1);
vector<bool> vis(100005, false);

bool dfs(int u, int c) {
    vis[u] = true;
    bool pos = true;
    if (color[u] != -1 && color[u] != c) return false;
    color[u] = c;
    for (int &v : adj[u]) {
        if (!vis[v]) {
           pos &= dfs(v, 3 - c);
        } else if (color[u] == color[v]) return false;
    }
    return pos;
}

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            bool pos = dfs(i, 1);
            if (!pos) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << color[i] << " \n"[i==N];        
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
//    cin >> T;   
    while (T--) {
        solve();
    }
}

