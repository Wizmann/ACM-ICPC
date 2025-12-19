#include <bits/stdc++.h>
using namespace std;

static const long long INF = (long long)1e10;
static const long long MOD = 998244353;

int n, m;
vector<int> colors;
vector<vector<int>> g;

long long dfs(int pre, int cur, int val) {
    if (colors[cur] != -1) return 0; 
    colors[cur] = val;
    long long res = 1;

    for (int nxt : g[cur]) {
        if (nxt == pre) continue;
        if (colors[nxt] == -1) {
            long long u = dfs(cur, nxt, val ^ 1);
            if (u < 0) return -INF;
            res += u;
        } 
        else if (colors[nxt] != (val ^ 1)) {
            return -INF;
        }
    }
    return res;
}

long long modpow(long long a, long long b) {
    long long r = 1;
    while (b > 0) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    colors.assign(n + 1, -1);
    g.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;  // python code did: a -= 1
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long free_cnt = 0, cnt = 0;
    bool bad = false;

    for (int i = 0; i <= n; i++) {
        if (i != 0 && g[i].empty()) {
            colors[i] = colors[i - 1];
            free_cnt++;
            continue;
        }

        if (colors[i] != -1) continue;

        int pre = 0;
        if (i - 1 >= 0) pre = colors[i - 1];

        long long u = dfs(-1, i, pre);
        if (u < 0) {
            bad = true;
            break;
        } else {
            if (i != 0) cnt++;
        }
    }

    if (bad) {
        cout << 0 << "\n";
        return 0;
    }

    long long ans = modpow(2, free_cnt + cnt);
    cout << ans << "\n";

    // 输出串 s
    for (int i = 1; i <= n; i++) {
        if (colors[i] == -1) colors[i] = 0;
        cout << (colors[i] ^ colors[i - 1]);
    }
    cout << "\n";

    return 0;
}
