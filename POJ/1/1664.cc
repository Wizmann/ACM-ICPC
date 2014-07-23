#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12;

int dp[SIZE][SIZE];
int n, m;

void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dp[i][j] = dp[i - 1][j] + (j - i >= 0? dp[i][j - i]: 0);
        }
    }
}

int main()
{
    int T;
    input(T);
    init();
    while (T--) {
        scanf("%d%d", &m, &n);
        printf("%d\n", dp[n][m]);
    }
    return 0;
}

