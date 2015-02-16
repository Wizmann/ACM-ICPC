#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;
const int SIZE = 555;

llint dp[SIZE][SIZE];
int n;
vector<int> outvec;

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            int l = j, r = j + i;
            if (l == r) {
                dp[l][r] = 1;
                continue;
            }
            if (outvec[l + 1] > outvec[l]) {
                dp[l][r] += dp[l + 1][r]; // <l + 1 ... r> are siblings
                dp[l][r] %= MOD;
            }
            dp[l][r] += dp[l + 1][r]; // <l + 1 .. r> are child nodes
            dp[l][r] %= MOD;

            for (int k = l + 2; k <= r; k++) {
                if (outvec[k] > outvec[l]) {
                    llint child   = dp[l + 1][k - 1];
                    llint sibling = dp[k][r];
                    dp[l][r] = (dp[l][r] + child * sibling) % MOD;
                }
            }
        }
    }
}

int main() {
    int x;
    input(n);
    if (n == 1) {
        print(1);
        exit(0);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        input(x);
        outvec.push_back(x);
    }
    solve();
    print(dp[1][n - 1] % MOD);
    return 0;
}
