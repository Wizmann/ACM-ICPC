#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        n = flights.size();
        if (n == 0) {
            return 0;
        }
        m = days[0].size();
        if (m == 0) {
            return 0;
        }

        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || flights[0][i]) {
                dp[0][i] = days[i][0];
            }
        }

        int ans = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] == -1) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (!flights[j][k]) {
                        continue;
                    }
                    dp[i][k] = max(dp[i][k], dp[i - 1][j] + days[k][i]);
                    if (i == m - 1) {
                        ans = max(ans, dp[i][k]);
                    }
                }
            }
        }
        return ans;
    }
private:
    int n;
    int m;
    int dp[111][111];
};

int main() {
    Solution S;

    vector<vector<int> > flights = {
        {0, 1, 1}, {1, 0, 1}, {1, 1, 0}
    };
    vector<vector<int> > days = {
        {1, 3, 1}, {6, 0, 3}, {3, 3, 3}
    };
    print(S.maxVacationDays(flights, days));
    return 0;
}
