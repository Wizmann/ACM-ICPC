#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 123456;
const int LOGN = 18;

int n;
vector<int> g[N];
int depth[N];
int weight[N];
int tarjan[LOGN][N];

void dfs1_depth(int pre, int cur, int d) {
    depth[cur] = d;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }
        dfs1_depth(cur, next, d + 1);
    }
}

int dfs2_weight(int pre, int cur) {
    int w = 1;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }
        w += dfs2_weight(cur, next);
    }
    return weight[cur] = w;
}

void dfs3_tarjan(int pre, int cur) {
    tarjan[0][cur] = cur;
    tarjan[1][cur] = pre;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }
        dfs3_tarjan(cur, next);
    }
}

void make_tarjan() {
    for (int i = 2; i < LOGN; i++) {
        for (int j = 1; j <= n; j++) {
            int up = tarjan[i - 1][j];
            if (up == -1) {
                continue;
            }
            tarjan[i][j] = tarjan[i - 1][up];
        }
    }
}

int move_up(int cur, int dis) {
    for (int i = 1; i < LOGN; i++) {
        if (dis & (1 << (i - 1))) {
            cur = tarjan[i][cur];
        }
    }
    return cur;
}

int lca(int a, int b) {
    int l = 0;
    int r = n;
    int delta = depth[a] - depth[b];
    if (delta > 0) {
        a = move_up(a, delta);
    } else {
        b = move_up(b, -delta);
    }
    while (l <= r) {
        int m = (l + r) >> 1;
        int aa = move_up(a, m);
        int bb = move_up(b, m);
        if (aa == bb) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    int p = move_up(a, l);
    assert(p != -1);
    return p;
}

int get_dis(int a, int b) {
    int p = lca(a, b);
    return depth[a] - depth[p] + depth[b] - depth[p];
}

int main() {
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1_depth(-1, 1, 0);
    dfs2_weight(-1, 1);
    
    memset(tarjan, -1, sizeof(tarjan));
    dfs3_tarjan(-1, 1);
    make_tarjan();

    int q;
    input(q);

    while (q--) {
        scanf("%d%d", &a, &b);
        int dis = get_dis(a, b);
        if (dis % 2 == 1) {
            printf("0\n");
        } else {
            if (depth[a] > depth[b]) {
                swap(a, b);
            }
            int res = 0;
            int p = move_up(b, dis / 2);
            if (a == b) {
                res = n;
            } else if (p == lca(a, b)) {
                int q1 = move_up(a, dis / 2 - 1);
                int q2 = move_up(b, dis / 2 - 1);
                res = n - weight[q1] - weight[q2];
            } else {
                int q = move_up(b, dis / 2 - 1);
                res = weight[p] - weight[q];
            }
            printf("%d\n", res);
        }
    }

    return 0;
}
