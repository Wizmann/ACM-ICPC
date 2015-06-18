#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 1234567;
const int DIGIT = 20;

int dp[DIGIT][SIZE];
int n;

int main() {
    int x;
    input(n);
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        input(x);
        if (x & 1) {
            dp[0][x]++;
            dp[0][x ^ 1]++;
        } else {
            dp[0][x]++;
        }
    }

    for (int i = 1; i < DIGIT; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j & (1 << i)) {
                dp[i][j] = dp[i - 1][j];
            } else {
                int u = j | (1 << i);
                if (u < SIZE) {
                    dp[i][j] += dp[i - 1][u];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= 1000000; i++) {
        printf("%d\n", dp[19][i]);
    }
    return 0;
}
