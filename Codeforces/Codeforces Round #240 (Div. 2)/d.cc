#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE = 2048;
const llint MOD = 1000000007LL;

int n, m;
llint dp[2][SIZE];

int main()
{
    input(n >> m);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }
    
    int ptr = 1;
    for (int i = 1; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[ptr][j] = 0;
        }
        for (int j = 1; j <= n; j++) {
           for (int k = 1; j * k < SIZE; k++) {
               dp[ptr][j * k] += dp[ptr^1][j];
               dp[ptr][j * k] %= MOD;
            }
        }
        ptr ^= 1;
    }

    llint ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[ptr^1][i];
        ans %= MOD;
    }
    print (ans);
    return 0;
}

