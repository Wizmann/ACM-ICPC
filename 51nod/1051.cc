#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n, m;
vector<vector<llint> > dp;

int main() {
    freopen("input.txt", "r", stdin);
    input(m >> n);
    dp = vector<vector<llint> >(n, vector<llint>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &dp[i][j]);
            if (j - 1 >= 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    
    llint ans = numeric_limits<llint>::min();
    for (int i = 0; i < m; i++) {
        for (int j = 1; i + j - 1 < m; j++) {
            int l = i;
            int r = i + j - 1;
            llint sum = 0;
            for (int k = 0; k < n; k++) {
                llint u = dp[k][r] - (l - 1 >= 0? dp[k][l - 1]: 0);
                if (sum < 0) {
                    sum = 0;
                }
                sum += u;
                ans = max(ans, sum);
            }
        }
    }
    print(ans);
    return 0;
}
