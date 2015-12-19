#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

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
        scanf("%d%d%d", &a, &b, &c);
        vector<int> cap = {0};
        for (int i = 0; (1 << i) <= c; i++) {
            cap.push_back(1 << i);
        }
        *cap.rbegin() = c - *cap.rbegin() + 1;
        for (auto cc: cap) {
            for (int k = w; k >= 0; k--) {
                if (dp[k] == -1) {
                    continue;
                }
                int u = k + a * cc;
                if (u > w) {
                    continue;
                }
                dp[u] = max(dp[u], dp[k] + b * cc);
            }
        }
    }
    int ans = 0;
    for (int i = w; i >= 0; i--) {
        ans = max(ans, dp[i]);
    }
    print(ans);
    return 0;
}
