#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define sqr(x) ((x) * (x))
#define ABS(x) max(x, -x)
#define SB puts("sb");
#define L(i) (i << 1)
#define R(i) ((i << 1) | 1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int N = 10010;
const int M = 1;

char s[4][N];
int n, dp[N][8];
int sx, sy;

void find() {
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= n; ++j) if (s[i][j] == 'O') {
            sx = i, sy = j;
            return;
        }
}

int num(int j) {
    int ret = 0;
    for (int i = 1; i <= 3; ++i) if (s[i][j] != '.') {
        ret += (1 << (3 - i));
    }
    return ret;
}

int cal_mode(int i, int k) {
    if (k == 0) return dp[i - 1][7];
    if (k == 1) return dp[i - 1][6];
    if (k == 2) return dp[i - 1][5];
    if (k == 3) return (dp[i - 1][7] + dp[i - 1][4]) % MOD;
    if (k == 4) return dp[i - 1][3];
    if (k == 5) return dp[i - 1][2];
    if (k == 6) return (dp[i - 1][7] + dp[i - 1][1]) % MOD;
    if (k == 7) return ((dp[i - 1][0] + dp[i - 1][3]) % MOD + dp[i - 1][6]) % MOD;
    return 0;
}

int cal() {
    clr(dp, 0);
    dp[0][7] = 1;

    for(int i = 1; i <= n; ++i)
    {
        int k = num(i);
        for (int j = k; j <= 7; ++j) if((j & k) == k)
            dp[i][j] = cal_mode(i, j - k);
    }
    return dp[n][7];
}


int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= 3; ++i) scanf("%s", s[i] + 1);

    find();

    if (sx == 2) {
        int ans = 0;
        bool f1 = 0, f2 = 0;
        if (sy >= 3) {
            if (s[2][sy - 2] == '.' && s[2][sy - 1] == '.') {
                f1 = 1;
                s[2][sy - 2] = s[2][sy - 1] = 'X';
                ans += cal();
                s[2][sy - 2] = s[2][sy - 1] = '.';
            }
        }
        if (sy + 2 <= n) {
            if (s[2][sy + 2] == '.' && s[2][sy + 1] == '.') {
                f2 = 1;
                s[2][sy + 2] = s[2][sy + 1] = 'X';
                ans += cal();
                s[2][sy + 2] = s[2][sy + 1] = '.';
            }
        }
        if (f1 && f2) {
            s[2][sy - 2] = s[2][sy - 1] = 'X';
            s[2][sy + 2] = s[2][sy + 1] = 'X';
            ans -= cal();
        }
        if (ans < 0) ans += MOD;
        printf("%d\n", ans % MOD);
    }
    else
        printf("%d\n", cal());
    return 0;
}
