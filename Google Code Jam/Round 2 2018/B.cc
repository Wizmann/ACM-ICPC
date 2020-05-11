#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 555;
const int SQRTSIZE = 55;

int dp[SIZE][SIZE];

void init() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = -1;
    for (int i = 0; i < SQRTSIZE; i++) {
        for (int j = 0; j < SQRTSIZE; j++) {
            for (int rr = SIZE - 1; rr >= i; rr--) {
                for (int bb = SIZE - 1; bb >= j; bb--) {
                    dp[rr][bb] = max(dp[rr][bb], dp[rr - i][bb - j] + 1);
                }
            }

        }
    }
}

int main() {
    init();

    int T;
    input(T);

    int r, b;
    for (int case_ = 0; case_ < T; case_++) {
        input(r >> b);
        printf("Case #%d: %d\n", case_ + 1, dp[r][b]);
    }

    return 0;
}
