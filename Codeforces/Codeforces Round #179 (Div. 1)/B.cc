#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;
const int SIZE = 555;

llint dp[SIZE][SIZE];
int g[SIZE][SIZE];

int main() {
    int n;
    input(n);

    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            if (a == 0) {
                g[i][j] = INF;
            } else {
                g[i][j] = a;
            }
        }
    }

    memset(dp, INF, sizeof(dp));

    vector<int> qs(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &qs[i]);
        qs[i]--;
    }

    vector<int> ps;
    vector<llint> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int cur = qs[i];
        dp[cur][cur] = 0;
        ps.push_back(cur);

        for (auto next: ps) {
            dp[cur][next] = g[cur][next];
            dp[next][cur] = g[next][cur];
        }

        for (auto j: ps) {
            for (auto k: ps) {
                dp[cur][k] = min(dp[cur][k], dp[cur][j] + dp[j][k]);
                dp[k][cur] = min(dp[k][cur], dp[k][j] + dp[j][cur]);
            }
        }

        llint tot = 0;
        for (auto j: ps) {
            for (auto k: ps) {
                if (j == k) {
                    dp[j][k] = 0;
                }
                dp[j][k] = min(dp[j][k], dp[j][cur] + dp[cur][k]);
                if (dp[j][k] < INF) {
                    // print(j << ' ' << k << ' ' << dp[j][k]);
                    tot += dp[j][k];
                }
            }
        }
        ans[i] = tot;
        // puts("---");
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    puts("");
    return 0;
}

