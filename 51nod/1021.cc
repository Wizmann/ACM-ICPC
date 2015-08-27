#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 222;
const int INF = 0x3f3f3f3f;
int dp[SIZE][SIZE];
int sum[SIZE];
int n;

int do_sum(int a, int b) {
    b = sum[b];
    a = a == 0? 0: sum[a - 1];
    return b - a;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < n; i++) {
        input(dp[i][i]);
        sum[i] = dp[i][i];
        if (i - 1 >= 0) {
            sum[i] += sum[i - 1];
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            for (int k = j; k < j + i; k++) {
                int a = (j == k)? 0: dp[j][k];
                int b = (k + 1 == i + j)? 0: dp[k + 1][i + j];
                dp[j][i + j] = min(dp[j][i + j], do_sum(j, i + j) + a + b);
            }
        }
    }
    
    print(dp[0][n - 1]);
    
    return 0;
}
