#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 16;
const int STATUS = 1 << SIZE;

struct Edge {
    int dest;
    int cost;
};

int n, m;
vector<Edge> g[SIZE];
double dp[SIZE][STATUS];

double dfs(int pos, int status) {
    if (dp[pos][status] >= 0) {
        return dp[pos][status];
    }

    vector<double> es;

    double res = 0;
    for (auto e: g[pos]) {
        int dest = e.dest;
        int cost = e.cost;
        if (status & (1 << dest)) {
            continue;
        }
        double u = dfs(dest, status | (1 << dest));
        if (u < 0) {
            continue;
        }
        es.push_back(u + cost);
    }

    if (es.size() >= 1) {
        int cnt = es.size() + 1;

        for (auto u: es) {
            res += 1.0 / cnt * u;
        }

        res += 5.0 / cnt;
        res = (res / (cnt - 1)) * cnt;
    } else if (status == (1 << n) - 1) {
        res = 0;
    } else {
        res = -1;
    }

    // print(pos << ' ' << status << ' ' << res);
    return dp[pos][status] = res;
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
        for (int j = 0; j < STATUS; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        input(n >> m);

        init();

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }

        double res = dfs(0, 1);
        if (res < 0) {
            res = 0;
        }

        printf("Case %d: %.9lf\n", ++case_, res);
    }
    return 0;
}
