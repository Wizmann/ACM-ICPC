#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 21;
const int M = 101;

int n, m;

int dp[2][1 << N];
int diffi[M];

short reverse_num(int j, int cur) {
    int cnt = 0;
    for (int i = cur; i < N; i++) {
        if (j & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

int solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int p = 1;
    for (int i = 1; i <= m; i++) {
        int cur = diffi[i];
        int q = p ^ 1;
        for (int j = 0; j < (1 << n); j++) {
            if (dp[q][j] == -1) {
                continue;
            }
            dp[p][j] = max(dp[p][j], dp[q][j]);
            if (j & (1 << cur)) {
                continue;
            }
            int next = j | (1 << cur);
            dp[p][next] = max(dp[p][next], dp[q][j] + reverse_num(j, cur));
            //print(i << ' ' << next << ' ' << dp[i][next]);
        }
        p = q;
        memset(dp[p], -1, sizeof(dp[p]));
    }
    return p ^ 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int u;
    input(n >> m);
    for (int i = 1; i <= m; i++) {
        input(u);
        diffi[i] = u - 1;
    }

    int p = solve();
    print(dp[p][(1 << n) - 1]);

    return 0;
}
