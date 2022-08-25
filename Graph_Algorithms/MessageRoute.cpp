#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;

vector<int> adj[200005];
vector<bool> vis(200005, false);
vector<int> comp(200005, -1);

void dfs(int& u, int cc) {
    vis[u] = true;
    comp[u] = cc;
    for (int &v : adj[u]) {
        if (!vis[v]) 
            dfs(v, cc);
    }
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
    int cc = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i, cc++);
        }
    }
    if (comp[1] != comp[N]) {
        cout << "IMPOSSIBLE\n";
        return;
    } 
    vector<int> dist(200005, INF);
    vector<int> prev(200005, -1);
    queue<int> q;
    q.push(1);
    prev[1] = -1;
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == N) {
            stack<int> s;
            while (u != -1) {
                s.push(u);
                u = prev[u];
            }
            cout << dist[N] + 1 << '\n';
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            return;
        }
        for (int &v : adj[u]) {
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            prev[v] = u;
            q.push(v);
        }
    }
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

