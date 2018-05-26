#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int LOGSIZE = 24;

typedef long long llint;

int n, m;
vector<int> father;
vector<int> g[SIZE];
vector<int> depth;
vector<int> cnt;
vector<int> lca_skip[LOGSIZE];

int dfs(int pre, int cur, int d) {
    int res = 0;
    depth[cur] = d;
    for (auto next: g[cur]) {
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
    

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> m);
    
    father = vector<int>(n + 1, -1);
    depth = vector<int>(n + 1);
    cnt = vector<int>(n + 1);
    for (int i = 0; i < LOGSIZE; i++) {
        lca_skip[i].resize(n + 1);
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(-1, 1, 0);
    lca_prepare();


    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        
        int f = lca_query(a, b);

        if (f == a || f == b) {
            int delta = depth[b] - depth[a];
            int u = lca_move(b, delta - 1);
            
            int tot = n - cnt[u] - 1;
            print(1LL * tot * (cnt[b] + 1));
        } else {
            int ca = cnt[a] + 1;
            int cb = cnt[b] + 1;
            print(1LL * ca * cb);
        }
    }

    return 0;
}
