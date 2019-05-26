#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123;
const double finf = -1e100;
const double e = exp(1);

struct Edge {
    int dest;
    double p;
};

int n, m, S, K;
vector<Edge> g[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
}

double spfa() {
    vector<bool> visit(SIZE, false);
    vector<double> dis(SIZE, finf);
    queue<int> q;

    dis[0] = 0;
    q.push(0);
    visit[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visit[cur] = false;

        for (auto nxt: g[cur]) {
            int dest = nxt.dest;
            double p = log(nxt.p);

            if (dis[dest] < dis[cur] + p) {
                dis[dest] = dis[cur] + p;

                if (!visit[dest]) {
                    visit[dest] = true;
                    q.push(dest);
                }
            }

        }
    }

    return pow(e, dis[n - 1]);
}

double solve(double p) {
    return 2.0 * S * K / p;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    int case_ = 0;
    while (T--) {
        init();

        input(n >> m >> S >> K);

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back({b, c / 100.});
            g[b].push_back({a, c / 100.});
        }

        double p = spfa();

        printf("Case %d: ", ++case_);
        printf("%.7f\n", solve(p));
    }
    return 0;
}
