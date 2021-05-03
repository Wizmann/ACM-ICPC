#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int LOGSIZE = 24;
const int TYPE = 55;

typedef long long llint;

struct Edge {
    int dest;
    int type;
};

int n, m;
vector<int> father;
vector<Edge> g[SIZE];
vector<int> depth;
vector<int> cnt;
vector<int> lca_skip[LOGSIZE];
vector<vector<int> > ts;

int dfs(int pre, int cur, int d) {
    int res = 0;
    depth[cur] = d;
    for (int i = 0; i < g[cur].size(); i++) {
        Edge edge = g[cur][i];
        int next = edge.dest;
        if (next == pre) {
            continue;
        }
        father[next] = cur;
        res += dfs(cur, next, d + 1);
    }
    cnt[cur] = res;
    return res + 1;
}

void lca_prepare() {
    for (int i = 1; i <= n; i++) {
        lca_skip[0][i] = father[i];
    }
    
    for (int i = 1; i < LOGSIZE; i++) {
        for (int j = 1; j <= n; j++) {
            int u = lca_skip[i - 1][j];
            if (u == -1) {
                lca_skip[i][j] = -1;
            } else {
                lca_skip[i][j] = lca_skip[i - 1][u];
            }
        }
    }
}

int lca_move(int cur, int step) {
    for (int i = 0; i < LOGSIZE; i++) {
        if (step & (1 << i)) {
            cur = lca_skip[i][cur];
        }
    }
    return cur;
}

int lca_query(int a, int b) {
    int da = depth[a];
    int db = depth[b];
    
    if (da > db) {
        swap(da, db);
        swap(a, b);
    }
    
    int l = 0;
    int r = da;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int fa = lca_move(a, da - mid);
        int fb = lca_move(b, db - mid);
        
        if (fa == fb) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return lca_move(a, da - r);
}

void dfs2(int pre, int cur, vector<int>& path) {
    ts[cur] = path;
    for (int i = 0; i < g[cur].size(); i++) {
        Edge edge = g[cur][i];
        if (edge.dest == pre) {
            continue;
        }
        path[edge.type]++;
        dfs2(cur, edge.dest, path);
        path[edge.type]--;
    }
}

void query_path(int cur, int u, vector<int>& ks) {
    for (int i = 0; i < TYPE; i++) {
        ks[i] += u * ts[cur][i];
    }
}

int main() {
    scanf("%d%d", &n, &m);

    int a, b, c;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back({i, b});
    }

    for (int i = 0; i < LOGSIZE; i++) {
        lca_skip[i].resize(SIZE);
    }

    depth = vector<int>(SIZE, 0);
    father = vector<int>(SIZE, 0);
    cnt = vector<int>(SIZE, 0);

    dfs(-1, 1, 0);
    lca_prepare();

    {
        ts.resize(SIZE);
        vector<int> tmp(TYPE, 0);
        dfs2(-1, 1, tmp);
    }

    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        int f = lca_query(a, b);

        vector<int> ks(TYPE, 0);
        query_path(a, +1, ks);
        query_path(b, +1, ks);
        query_path(f, -2, ks);

        int maxi = 0;
        for (int i = 0; i < TYPE; i++) {
            maxi = max(maxi, ks[i]);
            // printf("%d ", ks[i]);
        }
        // puts("");
        if (maxi >= c) {
            puts("y");
        } else {
            puts("n");
        }
    }

    return 0;
}

/*

^^^TEST^^^
8 4
1 2
1 3
1 4
2 1
2 2
4 2
7 1
2 4 2
2 5 2
1 4 1
1 4 2
-----
n
n
y
n
$$$TEST$$$

 */
