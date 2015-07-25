#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int dp[SIZE][SIZE];
string str;

int main() {
    input(str);
    int n = str.size();
    memset(dp, INF, sizeof(dp));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            int l = j;
            int r = i + j;
            
            if (str[l] == str[r]) {
                if (r - l == 1) {
                    dp[l][r] = 0;
                } else {
                    dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
                }
            }
            dp[l][r] = min(dp[l][r], dp[l + 1][r] + 1);
            dp[l][r] = min(dp[l][r], dp[l][r - 1] + 1);
        }
    }
    print(dp[0][n - 1]);
    return 0;
}
