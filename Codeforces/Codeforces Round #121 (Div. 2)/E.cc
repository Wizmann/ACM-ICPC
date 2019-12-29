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

typedef long long llint;

int n;
vector<int> father;
vector<int> g[SIZE];
vector<int> depth;
vector<int> cnt;
vector<int> lca_skip[LOGSIZE];

vector<int> vs;
vector<int> ps;
map<pair<int, int>, int> mp;

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

int dfs2(int pre, int cur) {
    int tot = 0;
    bool isLeaf = false;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        isLeaf = true;
        tot += dfs2(cur, nxt);
    }

    if (pre != -1) {
        pair<int, int> key = {min(pre, cur), max(pre, cur)};
        int idx = mp[key];
        ps[idx] = tot + vs[cur];
        return ps[idx];
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);

        mp[{min(a, b), max(a, b)}] = i;
    }

    for (int i = 0; i < LOGSIZE; i++) {
        lca_skip[i].resize(SIZE);
    }

    depth = vector<int>(SIZE, 0);
    father = vector<int>(SIZE, 0);
    cnt = vector<int>(SIZE, 0);

    dfs(-1, 1, 0);
    lca_prepare();

    vs = vector<int>(SIZE, 0);
    ps = vector<int>(SIZE, 0);

    int k;
    input(k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        int f = lca_query(a, b);
        // print(a << ' ' << b << ' ' << f);
        if (f == a) {
            vs[a] -= 1;
            vs[b] += 1;
        } else if (f == b) {
            vs[b] -= 1;
            vs[a] += 1;
        } else {
            vs[a] += 1;
            vs[b] += 1;
            vs[f] -= 2;
        }
    }

    dfs2(-1, 1);

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", ps[i]);
    }
    puts("");

    return 0;
}
