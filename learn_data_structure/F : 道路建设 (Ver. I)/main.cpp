#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int INF = 1e9;
int dist[MAXN][MAXN];
bool visited[MAXN];
int minDist[MAXN];

int prim(int N) {
    fill(minDist, minDist + N + 1, INF);
    fill(visited, visited + N + 1, false);
    minDist[1] = 0;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int v = -1;
        for (int u = 1; u <= N; ++u) {
            if (!visited[u] && (v == -1 || minDist[u] < minDist[v])) v = u;
        }
        if (v == -1) break;
        visited[v] = true;
        res += minDist[v];
        for (int u = 1; u <= N; ++u) {
            minDist[u] = min(minDist[u], dist[v][u]);
        }
    }
    return res;
}

int main() {
    int N;
    while (cin >> N) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> dist[i][j];
            }
        }
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int a, b;
            cin >> a >> b;
            dist[a][b] = dist[b][a] = 0;
        }
        cout << prim(N) << endl;
    }
    return 0;
}