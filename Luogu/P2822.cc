#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 2222;

int dp1[N][N];
int dp2[N][N];

void init(int k) {
    memset(dp1, 0, sizeof(dp1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0) {
                dp1[i][j] = 1;
            } else {
                dp1[i][j] = (dp1[i - 1][j - 1] + dp1[i - 1][j]) % k;
            }
        }
    }

    memset(dp2, 0, sizeof(dp2));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp1[i][j] == 0) {
                dp2[i][j] += 1;
            }
            if (j - 1 >= 0) {
                dp2[i][j] += dp2[i][j - 1];
            }
        }
    }
}

int solve(int a, int b) {
    int tot = 0;
    for (int i = 0; i <= a; i++) {
        int j = min(b, i);
        tot += dp2[i][j];
    }
    return tot;
}

int main() {
    int n, k;
    input(n >> k);

    init(k);

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", solve(a, b));
    }
    return 0;
}
/*
^^TEST^^
1 2
3 3
---
1
$$TEST$$

^^TEST^^
2 5
4 5
6 7
---
0
7
$$TEST$$
*/
