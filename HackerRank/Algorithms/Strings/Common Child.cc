#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5555;

int dp[SIZE][SIZE];
string a, b;
int n, m;

int main() {
    input(a);
    input(b);
    
    n = a.length();
    m = b.length();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c1 = a[i - 1];
            char c2 = b[j - 1];
            
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (c1 == c2));
        }
    }
    print(dp[n][m]);
    return 0;
}
