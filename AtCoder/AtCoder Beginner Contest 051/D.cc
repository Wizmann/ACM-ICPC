#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
const int SIZE = 111;
const int INF = 0x3f3f3f3f;
 
int n;
int m;
int dp[SIZE][SIZE];
int g[SIZE][SIZE];
 
int main() {    
    int a, b, c;
    memset(g, INF, sizeof(g));
    memset(dp, INF, sizeof(dp));
    input(n >> m);
    
    for (int i = 1; i <= n; i++) {
        g[i][i] = dp[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        input(a >> b >> c);
        g[a][b] = g[b][a] = c;
        dp[a][b] = dp[b][a] = c;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] >= INF) {
                continue;
            }
            if (dp[i][j] < g[i][j]) {
                ans++;
                // print(i << ' ' << j);
            }
        }
    }
    print(ans / 2);
    return 0;
}
