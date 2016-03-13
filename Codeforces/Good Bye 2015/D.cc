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

const int SIZE = 5555;
const int MOD = 1000000000 + 7;

int n;
llint dp[SIZE][SIZE];
int lcp[SIZE][SIZE];

char nums[SIZE];

int main() {
    memset(dp, 0, sizeof(dp));
    memset(nums, 0, sizeof(nums));
    memset(lcp, 0, sizeof(lcp));
    nums[0] = 'x';
    input(n);
    scanf("%s", nums + 1);
    
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (nums[i] == nums[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            } else {
                lcp[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] += dp[i][j - 1];
            }
            
            if (nums[j + 1] == '0') {
                continue;
            }
            
            bool flag = false;
            int x = lcp[i][j + 1];
            if (x >= (j - i + 1)) {
                flag = true;
            } else if (nums[i + x] > nums[j + 1 + x]) {
                flag = true;
            }
            int k = j + 1 + (j - i);
            if (flag) {
                k++;
            }
            if (k > n) {
                continue;
            }
            dp[j + 1][k] += dp[i][j];
            dp[j + 1][k] %= MOD;
        }
    }
    
    llint ans = 0;
    for (int i = 1 ; i <= n; i++) {
        ans += dp[i][n];
        ans %= MOD;
    }
    
    print(ans);
    return 0;
}
