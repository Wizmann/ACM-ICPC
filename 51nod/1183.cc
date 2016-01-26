#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int dp[SIZE][SIZE];

int main() {
    string a, b;
    input(a >> b);
    
    int n1 = a.size();
    int n2 = b.size();
    
    memset(dp, INF, sizeof(dp));
    
    for (int i = 0; i <= n1; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n2; i++) {
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            char c1 = a[i - 1];
            char c2 = b[j - 1];
            
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            
            if (c1 == c2) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }
    
    print(dp[n1][n2]);
    return 0;
}
