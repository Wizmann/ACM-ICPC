// https://codeforces.com/contest/1312/problem/E

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cassert>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
const int N = 555;
const int INF = 0x3f3f3f3f;
 
int n;
vector<int> ns;
 
int dp1[N][N];
int dp2[N];
 
int dfs1(int l, int r) {
    if (l == r) {
        return dp1[l][r] = ns[l];
    }
    if (dp1[l][r] != INF) {
        return dp1[l][r];
    }
 
    for (int i = l; i < r; i++) {
        int a = dfs1(l, i);
        if (a == -1) {
            continue;
        }
        int b = dfs1(i + 1, r);
        if (b == -1) {
            continue;
        }
 
        if (a == b) {
            return dp1[l][r] = a + 1;
        }
    }
    return dp1[l][r] = -1;
}
 
int main() {
    input(n);
    n++;
    ns = vector<int>(n);
    ns[0] = INF;
    for (int i = 1; i < n; i++) {
        scanf("%d", &ns[i]);
    }
 
    memset(dp1, INF, sizeof(dp1));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dp1[i][j] = dfs1(i, j);
            // print("dp1 " << i << ' ' << j << ' ' << dp1[i][j]);
        }
    }
 
    memset(dp2, -1, sizeof(dp2));
    dp2[0] = 1;
    for (int i = 1; i < n; i++) {
        int mini = INF;
        for (int j = 0; j < i; j++) {
            if (dp1[j + 1][i] != -1) {
                mini = min(mini, dp2[j] + 1);
            }
        }
        dp2[i] = mini;
    }
    print(dp2[n - 1] - 1);
 
    return 0;
}
