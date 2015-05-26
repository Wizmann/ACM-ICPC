#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1234567;

int dp[SIZE];

int do_3n_plus_1(int x) {
    if (x == 1) {
        return 1;
    }
    if (x < SIZE && dp[x] == -1) {
        return x % 2 == 0? \
            dp[x] = 1 + do_3n_plus_1(x / 2): \
            dp[x] = 1 + do_3n_plus_1(3 * x + 1);
    } else if (x >= SIZE) {
        return x % 2 == 0? \
            1 + do_3n_plus_1(x / 2): \
            1 + do_3n_plus_1(3 * x + 1);
    }
    return dp[x];
}

int main() {
    int a, b;
    memset(dp, -1, sizeof(dp));
    while (input(a >> b)) {
        printf("%d %d ", a, b);
        if (a > b) {
            swap(a, b);
        }
        int ans = 0;
        for (int i = a; i <= b; i++) {
            ans = max(ans, do_3n_plus_1(i));
        }
        print(ans);
    }
    return 0;
}
