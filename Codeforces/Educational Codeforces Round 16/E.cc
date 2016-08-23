#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (decltype(n) i = 0; i < n; i++)

typedef long long llint;

const int SIZE = 10001111;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

struct Solution {
    llint dp[SIZE * 2 + 1];
    int n, x, y;

    llint init() {
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        dp[1] = x;
    }

    llint solve(int w) {
        if (w > SIZE * 2) {
            return INF;
        }
        if (dp[w] != INF) {
            return dp[w];
        }
        if (w % 2 == 1) {
            dp[w] = min(dp[w], x + min(solve(w + 1), solve(w - 1)));
        } else {
            dp[w] = min(dp[w], min(solve(w / 2) + 1LL * x * w / 2, solve(w / 2) + y));
        }
        return dp[w];
    }
};

void test() {
    Solution* S = new Solution();
    S->n = 8;
    S->x = 1;
    S->y = 1;
    S->init();
    assert(S->solve(S->n) == 4);

    S->n = 8;
    S->x = 1;
    S->y = 10;
    S->init();
    assert(S->solve(S->n) == 8);

    delete S;
    print("OK");
}

int main() {
    // test();
    Solution* S = new Solution();
    input(S->n >> S->x >> S->y);
    S->init();
    print(S->solve(S->n));
    return 0;
}
