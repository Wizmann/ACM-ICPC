#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int HEIGHT   = 2500;
const int BUILDING = 2500;

int dp[HEIGHT][BUILDING];
int people[HEIGHT][BUILDING];

int H, N, I;

int solve() {
    for (int i = H; i >= 0; i--) {
        int maxi = 0;
        for (int j = 0; j < N; j++) {
            maxi = max(maxi, dp[i + I][j]);
        }
        for (int j = 0; j < N; j++) {
            dp[i][j] = max(maxi, dp[i + 1][j]);
            dp[i][j] += people[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[0][i]);
    }
    return ans;
}

int main() {
    int a, b;
    memset(dp, 0, sizeof(dp));
    memset(people, 0, sizeof(people));
    
    input(N >> H >> I);
    for (int i = 0; i < N; i++) {
        input(a);
        for (int j = 0; j < a; j++) {
            input(b);
            people[b][i]++;
        }
    }
    print(solve());
    return 0;
}
