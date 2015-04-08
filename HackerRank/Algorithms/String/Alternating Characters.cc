#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int INF = 0x3f3f3f3f;

int n;
int dp[2][SIZE];
char word[SIZE];

int main() {
    int T;
    input(T);
    while (T--) {
        input(word);
        n = strlen(word);
        memset(dp, 0, sizeof(dp));

        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            char c = word[i - 1];
            if (c == 'A') {
                dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1]);
                dp[1][i] = dp[1][i - 1] + 1;
            } else {
                dp[1][i] = min(dp[1][i - 1] + 1, dp[0][i - 1]);
                dp[0][i] = dp[0][i - 1] + 1;
            }
        }
        print(min(dp[0][n], dp[1][n]));
    }
    return 0;
}
