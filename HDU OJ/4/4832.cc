// Result: 2014-05-28 18:01:12  Accepted    4832    781MS   4496K   2125B   G++ Wizmann
10814524    2014-05-28 17:56:50 Wrong Answer
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1024;
const int MOD = 9999991;
const int mv[] = {-2, -1, 1, 2};

int dpx[2][SIZE];
int dpy[2][SIZE];
llint sumx[SIZE], sumy[SIZE];
int cc[SIZE][SIZE];

int n, m, k, xx, yy;

void do_dp(int dp[2][SIZE], int sz, int st, int step, llint sum[])
{
    int ptr = 0;
    
    dp[ptr][st] = 1;
    ptr ^= 1;

    for (int s = 1; s <= step; s++) {
        for (int i = 0; i < sz; i++) {
            dp[ptr][i] = 0;
            for (int j = 0; j < 4; j++) {
                int pre = i + mv[j];
                if (pre < 0 || pre >= sz || !dp[ptr ^ 1][pre]) {
                    continue;
                }
                dp[ptr][i] += dp[ptr ^ 1][pre];
                dp[ptr][i] %= MOD;
            }
        }
        for (int i = 0; i < sz; i++) {
            sum[s] += dp[ptr][i];
            sum[s] %= MOD;
        }
        ptr ^= 1;
    }
}

llint C(int a, int b)
{
    return cc[b][a];
}

void init()
{
    cc[0][0] = 1;
    for (int i = 1; i < SIZE; i++) {
        cc[i][0] = cc[i][i] = 1;
        for (int j = 1; j < i; j++) {
            cc[i][j] = (cc[i - 1][j] + cc[i - 1][j - 1]) % MOD;
        }
    }
}
            

int main()
{
    freopen("input.txt", "r", stdin);
    int T, cas = 1;
    input(T);
    init();
    while (T--) {
        llint ans = 0;
        scanf("%d%d%d%d%d", &m, &n, &k, &xx, &yy);
        
        memset(sumx, 0, sizeof(sumx));
        memset(sumy, 0, sizeof(sumy));
        memset(dpx, 0, sizeof(dpx));
        memset(dpy, 0, sizeof(dpy));
        
        sumx[0] = sumy[0] = 1;
        xx--; yy--;
        do_dp(dpy, n, yy, k, sumy);
        do_dp(dpx, m, xx, k, sumx);
        for (int i = 0; i <= k; i++) {
            ans += C(i, k) * ((sumx[i] * sumy[k - i]) % MOD);
            ans %= MOD;
        }
        printf("Case #%d:\n", cas++);
        print(ans);
    }
    return 0;
}
