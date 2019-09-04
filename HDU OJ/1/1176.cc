#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 100001;
const int M = 10;

int n;
vector<int> g[N + 3];
int dp[2][M + 3];

int main() {
    while (input(n) && n) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }

        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            g[b].push_back(a);
        }

        memset(dp, -1, sizeof(dp));
        dp[0][5] = 0;

        int p = 0;
        for (int i = 0; i < N; i++) {
            int q = p ^ 1;
            memset(dp[q], -1, sizeof(dp[q]));

            for (int j = 0; j <= M; j++) {
                if (dp[p][j] == -1) {
                    continue;
                }
                if (j - 1 >= 0) {
                    dp[q][j - 1] = max(dp[q][j - 1], dp[p][j]);
                }
                if (j + 1 <= M) {
                    dp[q][j + 1] = max(dp[q][j + 1], dp[p][j]);
                }
                dp[q][j] = max(dp[q][j], dp[p][j]);
            }

            for (auto pie: g[i + 1]) {
                if (dp[q][pie] != -1) {
                    dp[q][pie]++;
                }
            }

            /*
            for (int j = 0; j <= M; j++) {
                printf("%d ", dp[q][j]);
            }
            puts("");
            */
            p = q;
        }

        int maxi = -1;
        for (int i = 0; i <= M; i++) {
            maxi = max(maxi, dp[p][i]);
        }
        printf("%d\n", maxi);
    }
    return 0;
}
