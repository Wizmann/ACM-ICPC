#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

int n, m;
vector<int> cost;
vector<int> g[SIZE];
vector<bool> visit;

int dfs(int u) {
    int res = cost[u];
    visit[u] = true;
    for (auto next: g[u]) {
        if (visit[next]) {
            continue;
        }
        res = min(res, dfs(next));
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);

    input(n >> m);
    cost = vector<int>(n + 1);
    visit = vector<bool>(n + 1, false);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    llint ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            continue;
        }

        ans += dfs(i);
    }
    print(ans);

    return 0;
}
