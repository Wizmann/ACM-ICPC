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

const int MAXI = 2222;
const int SIZE = 111;
const int MOD = 1000000007;

int m, r, s;

llint dp[SIZE][MAXI];
llint x[SIZE];
vector<llint> A, B;

void solve(llint u) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = u; j >= 0; j--) {
            if (!dp[0][j]) {
                continue;
            }
            if (j + x[i] > u) {
                continue;
            }
            dp[0][j + x[i]] = 1;
            if (j == 0) {
                dp[1][j + x[i]] += 1;
                continue;
            }
            for (int k = 1; k <= m; k++) {
                if (dp[k][j]) {
                    dp[k + 1][j + x[i]] += dp[k][j];
                    dp[k + 1][j + x[i]] %= MOD;
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    input(m >> r >> s);
    for (int i = 0; i < m; i++) {
        input(x[i]);
    }

    if ((r + s) < 0 || 
            (r - s) < 0 ||
            (r + s) % 2 ||
            (r - s) % 2) {
        print(0);
        return 0;
    }

    int aa = (r + s) / 2;
    int bb = (r - s) / 2;
    
    solve(aa);
    for (int i = 1; i <= m; i++) {
        A.push_back(dp[i][aa]);
    }
    solve(bb);
    for (int i = 1; i <= m; i++) {
        B.push_back(dp[i][bb]);
    }
    
    llint ans = 0;
    for (int i = 0; i < m; i++) {
        //print(i << ' ' << A[i] << ' ' << B[i]);
        ans += (A[i] * B[i]) % MOD;
        ans %= MOD;
    }
    print(ans);
    return 0;
}
