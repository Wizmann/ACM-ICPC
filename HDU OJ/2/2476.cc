#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 111;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

llint dp[SIZE][SIZE];

class Solution {
public:
    Solution(string A_, string B_): A(A_), B(B_), n(A.size()) {
        // pass
    }

    llint solve() {
        memset(dp, -1, sizeof(dp));
        llint ans[SIZE];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = A[i] == B[i]? 0: 1;
                continue;
            }

            if (A[i] == B[i]) {
                ans[i] = ans[i - 1];
            } else {
                ans[i] = do_solve(0, i);
                for (int j = 0; j < i; j++) {
                    ans[i] = min(ans[i], ans[j] + do_solve(j + 1, i));
                }
            }
        }
        return ans[n - 1];
    }

    llint do_solve(int l, int r) {
        assert(l <= r);
        if (l == r) {
            return 1;
        }
        llint& u = dp[l][r];
        if (u != -1) {
            return u;
        }

        llint res = 1 + do_solve(l + 1, r);

        for (int i = l + 1; i <= r; i++) {
            if (B[l] == B[i]) {
                llint cur = do_solve(l + 1, i);
                if (i + 1 <= r) {
                    cur += do_solve(i + 1, r);
                }
                res = min(res, cur);
            }
        }
        return u = res;
    }
private:
    string A, B;
    int n;
};

int main() {
    char A[SIZE], B[SIZE];

    while (scanf("%s%s", A, B) != EOF) {
        printf("%lld\n", Solution(A, B).solve());
    }

    return 0;
}
