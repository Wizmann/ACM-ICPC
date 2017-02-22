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

const int Q = 0;
const int UQ = 1;

const int CITY_A = 0;
const int CITY_B = 1;

const int SIZE = 123456;
const llint MOD = 1000000000LL + 7;

int n;
llint dp[SIZE][2][2];
vector<int> g[SIZE];

void dfs(int cur, int pre) {
    int cnt = 0;
    for (auto next: g[cur]) {
        if (next != pre) {
            dfs(next, cur);
            cnt++;
        }
    }

    if (cnt == 0) {
        dp[cur][Q][CITY_A] = dp[cur][Q][CITY_B] = 0;
        dp[cur][UQ][CITY_A] = dp[cur][UQ][CITY_B] = 1;
        return;
    }

    dp[cur][Q][CITY_A] = dp[cur][Q][CITY_B] = 1;
    dp[cur][UQ][CITY_A] = dp[cur][UQ][CITY_B] = 1;
    llint qa = 1;
    llint qb = 1;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }

        dp[cur][Q][CITY_A] = (dp[cur][Q][CITY_A] * (dp[next][Q][CITY_A] + dp[next][Q][CITY_B] + dp[next][UQ][CITY_A]) % MOD) % MOD;
        dp[cur][Q][CITY_B] = (dp[cur][Q][CITY_B] * (dp[next][Q][CITY_A] + dp[next][Q][CITY_B] + dp[next][UQ][CITY_B]) % MOD) % MOD;
        dp[cur][UQ][CITY_A] = (dp[cur][UQ][CITY_A] * dp[next][Q][CITY_B]) % MOD;
        dp[cur][UQ][CITY_B] = (dp[cur][UQ][CITY_B] * dp[next][Q][CITY_A]) % MOD;

        qa = (qa * dp[next][Q][CITY_A]) % MOD;
        qb = (qb * dp[next][Q][CITY_B]) % MOD;
    }

    dp[cur][Q][CITY_A] = ((dp[cur][Q][CITY_A] - qb) % MOD + MOD) % MOD;
    dp[cur][Q][CITY_B] = ((dp[cur][Q][CITY_B] - qa) % MOD + MOD) % MOD;
}

int main() {
    int a, b;
    input(n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    llint ans = dp[1][Q][CITY_A] + dp[1][Q][CITY_B];
    print(ans % MOD);

    return 0;
}
