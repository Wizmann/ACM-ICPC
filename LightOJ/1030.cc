#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123;

int n;
double dp[SIZE];
int ns[SIZE];

double dfs(int cur) {
    if (dp[cur] >= 0) {
        return dp[cur];
    }

    int tot = 0;
    double e = 0;
    for (int i = 1; i <= 6; i++) {
        if (cur + i < n) {
            tot++;
            e += dfs(cur + i);
        }
    }
    if (tot == 0) {
        e = ns[cur];
    } else {
        e = e / tot + ns[cur];
    }
    return dp[cur] = e;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        fill(dp, dp + SIZE, -1);
        input(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        printf("Case %d: %.6lf\n", ++case_, dfs(0));
    }
    return 0;
}
