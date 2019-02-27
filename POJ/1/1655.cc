#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 23456;
const int INF = 0x3f3f3f3f;

int n;
vector<int> g[SIZE];
int mini, minb;

int dfs(int pre, int cur) {
    int maxsub = 0;
    int tot = 0;

    for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        if (next == pre) {
            continue;
        }
        int s = dfs(cur, next);
        maxsub = max(maxsub, s);
        tot += s;
    }

    maxsub = max(maxsub, n - tot - 1);
    if (maxsub < minb || (maxsub == minb && mini > cur)) {
        mini = cur;
        minb = maxsub;
    }

    return tot + 1;
}

void solve() {
    dfs(-1, 1);
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(n);
        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }

        mini = -1;
        minb = INF;

        int a, b;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        solve();
        printf("%d %d\n", mini, minb);
    }
    return 0;
}
