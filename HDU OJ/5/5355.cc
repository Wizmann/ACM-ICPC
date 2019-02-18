#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 11;

vector<int> g[SIZE];
vector<llint> sum;
vector<bool> visit;
int n, m;

bool dfs(int cur, llint l, llint r, llint ave) {
    if (cur >= m) {
        return true;
    }

    r = min(r, ave - sum[cur]);

    for (int i = r; i >= l; i--) {
        if (visit[i]) {
            continue;
        }
        visit[i] = true;
        if (sum[cur] + i == ave) {
            sum[cur] += i;
            g[cur].push_back(i);
            return dfs(cur + 1, 1, n, ave);
        } else {
            sum[cur] += i;
            g[cur].push_back(i);

            bool res = dfs(cur, l, i - 1, ave);
            if (res) {
                return true;
            }

            sum[cur] -= i;
            g[cur].pop_back();
        }
        visit[i] = false;
    }
    return false;
}

bool solve() {
    llint tot = (1LL + n) * n / 2;
    if (tot % m != 0) {
        return false;
    }
    llint ave = tot / m;

    int u = n / 2 / m;
    if (u && n % (u * 2 * m) < 4 * m - 1) {
        u--;
    }

    int l = n - u * m * 2 + 1;
    int r = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < u; j++) {
            g[i].push_back(l);
            g[i].push_back(r);
            sum[i] += l + r;
            l += 1;
            r -= 1;
        }
    }

    n = n - u * m * 2;
    visit = vector<bool>(n + 1, false);
    return dfs(0, 1, n, ave);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }
        sum = vector<llint>(m, 0);

        bool res = solve();
        if (res) {
            puts("YES");
            for (int i = 0; i < m; i++) {
                printf("%d", g[i].size());
                for (int j = 0; j < g[i].size(); j++) {
                    printf(" %d", g[i][j]);
                }
                puts("");
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}
