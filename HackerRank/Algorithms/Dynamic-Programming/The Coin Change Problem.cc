#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 333;

int n, m;
vector<int> cs;
llint dp[N];

llint solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < N; j++) {
            int u = cs[i];
            if (dp[j] && j + u < N) {
                dp[j + u] += dp[j];
            }
        }
    }
    return dp[n];
}

int main() {
    int coin;
    input(n >> m);
    for (int i = 0; i < m; i++) {
        input(coin);
        cs.push_back(coin);
    }
    print(solve());
    return 0;
}
