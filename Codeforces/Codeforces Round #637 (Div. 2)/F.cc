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

int n;
vector<int> g[N];
vector<pair<int, int> > ps;

int move(int cur, int a, int b) {
    assert(a >= 0 && b >= 0);
    // print("move" << ' ' << cur << ' ' << a << ' ' << b);
    if (a == b) {
        return b;
    }

    if (b == a + 1) {
        ps.push_back({cur, b});
    } else if (b < a) {
        ps.push_back({cur, b});
    } else {
        assert(false);
    }
    return b;
}

int dfs(int pre, int cur, int t, int maxd) {
    if (pre != -1) {
        assert(t != 0);
    }
    ps.push_back({cur, t});

    int tt = t;
    int rem = g[cur].size() - 1;
    
    for (auto nxt: g[cur]) {
        if (nxt == pre) {
            continue;
        }

        if (tt + 1 > maxd) {
            tt = move(cur, tt, t - rem - 1);
        }
        tt += 1;
        int nt = dfs(cur, nxt, tt, maxd);
        assert(nt == tt);
        tt = nt;
        ps.push_back({cur, tt});
        rem--;
    }

    if (cur != 1 && tt != t - 1) {
        tt = move(cur, tt, t - 1);
    }

    return t;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int maxd = 0;
    for (int i = 1; i <= n; i++) {
        maxd = max(maxd, (int)g[i].size());
    }

    dfs(-1, 1, 0, maxd);

    set<pair<int, int> > st;
    print(ps.size());
    int m = ps.size();
    for (int i = 0; i < m; i++) {
        const auto& p = ps[i];
        a = p.first;
        b = p.second;
        printf("%d %d\n", a, b);

        assert(st.count(p) == 0);
        st.insert(p);
    }

    return 0;
}
