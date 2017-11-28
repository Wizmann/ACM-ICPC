#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 444;
const int INF = 0x3f3f3f3f;

int n, m;
int g[SIZE][SIZE];
int dis[SIZE];
bool visit[SIZE];

int spfa(int mark) {
    memset(dis, INF, sizeof(dis));
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(1);
    dis[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        visit[cur] = false;
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (g[cur][i] != mark) {
                continue;
            }

            int cost = dis[cur] + 1;
            if (dis[i] > cost) {
                dis[i] = cost;
                if (!visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
    return dis[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int a, b;
    input(n >> m);
    memset(g, 0, sizeof(g));
    
    for (int i = 0; i < SIZE; i++) {
        g[i][i] = -1;
    }

    for (int i = 0; i < m; i++) {
        input(a >> b);
        g[a][b] = g[b][a] = 1;
    }

    int cc = spfa(0);
    int ct = spfa(1);

    if (cc == INF || ct == INF) {
        print(-1);
    } else {
        print(max(cc, ct));
    }
    
    return 0;
}
