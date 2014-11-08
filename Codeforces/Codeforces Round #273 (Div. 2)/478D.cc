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

const int SIZE = 212345;
const int LEVEL = 2048;
const int MOD = 1000000000 + 7;

llint dp[2][SIZE];

int cnt_level(int r, int g) {
    int sum = 0;
    for (int i = 1; i < LEVEL; i++) {
        sum += i;
        if (sum > r + g) {
            return i - 1;
        }
    }
    return -1;
}

int main()
{
    int r, g;
    input(r >> g);
    memset(dp, 0, sizeof(dp));
    do {
        int lv = cnt_level(r, g);
        int ptr = 0;
        dp[0][1] = 1;
        dp[0][0] = 1;
        for (int i = 2; i <= lv; i++) {
            int next = ptr ^ 1;
            memset(dp[next], 0, sizeof(dp[next]));
            for (int j = 0; j < SIZE; j++) {
                if (dp[ptr][j]) {
                    dp[next][j] = (dp[next][j] + dp[ptr][j]) % MOD;
                    if (j + i < SIZE) {
                        dp[next][j + i] = (dp[next][j + i] + dp[ptr][j]) % MOD;
                    }
                }
            }
            ptr = next;
        }
        int ans = 0;
        int tot = (1 + lv) * lv / 2;
        for (int i = 0; i <= SIZE; i++) {
            int a = i, b = tot - i;
            if (a <= r && b <= g) {
                ans += dp[ptr][i];
                ans %= MOD;
            }
        }
        print(ans);
    } while (0);
    return 0;
}
