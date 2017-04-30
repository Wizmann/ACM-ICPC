#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, k;
vector<vector<int> > g;
vector<bool> visit;
vector<int> pre;

bool deal(int cur) {
    for (size_t i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        if (!visit[next]) {
            visit[next] = true;

            if (pre[next] == -1 || deal(pre[next])) {
                pre[next] = cur;
                return true;
            }

        }
    }
    return false;
}

int hungary() {
    int sum = 0;
    fill(pre.begin(), pre.end(), -1);
    for (int i = 0; i < n; i++) {
        fill(visit.begin(), visit.end(), false);
        if (deal(i)) {
            sum++;
        }
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        scanf("%d%d", &k, &n);

        g.clear();
        g.resize(n);
        visit.resize(n);
        pre.resize(n);

        int m, x;
        for (int i = 0; i < k; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &x);
                g[i].push_back(x - 1);
            }
        }

        puts(hungary() == k? "YES": "NO");
    }
    return 0;
}
