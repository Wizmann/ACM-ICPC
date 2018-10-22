// 出题人没有小JJ。

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1234;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
    int dest, cost;
};

int n, m, s;
vector<Edge> g[SIZE];
vector<llint> dis;
vector<bool> visited;
vector<int> count;

bool spfa(int st) {
    queue<int> q;
    q.push(st);
    dis[st] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = false;
        count[cur]++;

        if (count[cur] > n + 1) {
            return false;
        }

        for (const auto& e: g[cur]) {
            int next = e.dest;
            int cost = e.cost;

            if (dis[next] > dis[cur] + cost) {
                dis[next] = dis[cur] + cost;
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> m >> s);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
    }

    dis = vector<llint>(n + 1, INF);
    visited = vector<bool>(n + 1, false);
    count = vector<int>(n + 1, 0);

    bool flag = true;
    vector<llint> res;
    if (spfa(s)) {
        res = dis;
        for (int i = 1; i <= n; i++) {
            if (dis[i] >= INF) {
                if (!spfa(i)) {
                    flag = false;
                    break;
                }
            }
        }
    } else {
        flag = false;
    }

    if (flag) {
        for (int i = 1; i <= n; i++) {
            if (res[i] < INF) {
                printf("%lld\n", res[i]);
            } else {
                puts("NoPath");
            }
        }
    } else {
        puts("-1");
    }

    return 0;
}
