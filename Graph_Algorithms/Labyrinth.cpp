#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pi = pair<int, int>;

const int mxN = 1005;
const int mxM = 1005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};

vector<string> G(mxN);
vector<vector<bool>> vis(mxN, vector<bool>(mxM, false));

bool works(int& x, int& y, int& N, int &M) {
    return x >= 0 && x < N && y >= 0 && y < M && !vis[x][y] && G[x][y] != '#';
}

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> G[i];
    int sx = 0, sy = 0;
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) {
            if (G[i][j] == 'A') {
                sx = i, sy = j;
                break;
            }
        }
    }
    vector<int> ppoint(mxN * mxM + 1, -1);
    vector<char> pdir(mxN * mxM + 1, ' ');
    queue<pi> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int flatten = p.f * M + p.s;
        if (G[p.f][p.s] == 'B') {
            stack<char> path_dirs;
            while (ppoint[flatten] != -1) {
               path_dirs.push(pdir[flatten]);
               flatten = ppoint[flatten];
            }
            cout << "YES\n";
            cout << path_dirs.size() << '\n';
            while (!path_dirs.empty()) {
                cout << path_dirs.top();
                path_dirs.pop();
            }
            return;
        } 
        for (int i = 0; i < 4; i++) {
            int nx = p.f + dx[i], ny = p.s + dy[i];
            if (works(nx, ny, N, M)) {
                q.push({nx, ny});
                vis[nx][ny] = true;
                ppoint[nx * M + ny] = flatten; 
                pdir[nx * M + ny] = dir[i];
            }
        }
    }
    cout << "NO\n"; 
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
