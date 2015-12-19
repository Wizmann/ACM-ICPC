#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 51234;

int dp[SIZE];
int n, w;

int main() {
    input(n >> w);
    int a, b, c;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        input(a >> b);
        for (int k = w; k >= 0; k--) {
            if (dp[k] == -1) {
                continue;
            }
            int u = k + a;
            if (u >= SIZE) {
                continue;
            }
            dp[u] = max(dp[u], dp[k] + b);
        }
    }
    
    int ans = 0;
    for (int i = w; i >= 0; i--) {
        ans = max(ans, dp[i]);
    }
    print(ans);
    return 0;
}
