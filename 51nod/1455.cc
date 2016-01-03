#pragma comment(linker, "/STACK:102400000,102400000")  
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 33333;
const int STEP = 500;
const int STEP_BASE = 250;
const int ISLAND = 30000;

int dp[STEP][SIZE];
int n, d;
int gem[SIZE];

int dfs(int cur, int step) {
    if (step <= 0) {
        return -1;
    }
    int s = step + STEP_BASE - d;
    if (cur > ISLAND) {
        return 0;
    }
    if (dp[s][cur] != -1) {
        return dp[s][cur];
    }
    
    dp[s][cur] = max(
        dp[s][cur], 
        dfs(cur + step - 1, step - 1) + gem[cur]);
    
    dp[s][cur] = max(
        dp[s][cur],
        dfs(cur + step, step) + gem[cur]);
        
    dp[s][cur] = max(
        dp[s][cur],
        dfs(cur + step + 1, step + 1) + gem[cur]);
    
    return dp[s][cur];
}

int main() {   
    freopen("input.txt", "r", stdin);
    input(n >> d);
    int x;
    memset(gem, 0, sizeof(gem));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        gem[x]++;
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(d, d);
    print(ans);
    return 0;
}
