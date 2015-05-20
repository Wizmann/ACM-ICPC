#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 555;
const int INF = 0x3f3f3f3f;


int MOD = 1000000000 + 7;
int n, m, bugs;
int dp[SIZE][SIZE];
vector<int> As;

int main() {
    int a;
    input(n >> m >> bugs >> MOD);
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        input(a);
        As.push_back(a);
    }

    for (int i = 0; i <= m; i++) {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= bugs; k++) {
                if (dp[j][k] && j + 1 <= m && k + As[i] <= bugs) {
                    dp[j + 1][k + As[i]] += dp[j][k];
                    dp[j + 1][k + As[i]] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= bugs; i++) {
        ans += dp[m][i];
        ans %= MOD;
    }
    print(ans);
    return 0;
}