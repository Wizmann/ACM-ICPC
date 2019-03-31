#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 111;

llint dp[SIZE][SIZE][SIZE];

class Solution {
public:
    Solution(const vector<int>& ns_): n(ns_.size()), ns(ns_) {
        // pass
    }

    llint solve() {
        memset(dp, -1, sizeof(dp));
        return do_solve(0, 0, n - 1);
    }

    llint do_solve(int nr, int l, int r) {
        assert(l <= r);
        if (l == r) {
            return 1LL * nr * ns[l];
        }
        llint& u = dp[nr][l][r];
        if (u != -1) {
            return u;
        }

        llint res = 1LL * nr * ns[l] + do_solve(nr + 1, l + 1, r);

        for (int i = l + 1; i <= r; i++) {
            int step = i - (l + 1) + 1;
            llint cur = do_solve(nr, l + 1, i);
            cur += 1LL * (nr + step) * ns[l];
            if (i + 1 <= r) {
                cur += do_solve(nr + step + 1, i + 1, r);
            }
            res = min(res, cur);
        }
        return u = res;
    }
private:
    int n;
    const vector<int>& ns;
};

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        printf("Case #%d: %lld\n", ++case_, Solution(ns).solve());
    }
    return 0;
}
