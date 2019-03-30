#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111;

int dp[SIZE][SIZE];

class Solution {
public:
    Solution(const vector<int>& ns_) : ns(ns_), n(ns.size()) {
        // pass
    }

    int solve() {
        memset(dp, -1, sizeof(dp));
        return do_solve(0, n - 1);
    }

    int do_solve(int l, int r) {
        if (l > r) {
            return 0;
        }

        if (l == r) {
            return 1;
        }

        int& u = dp[l][r];
        if (u != -1) {
            return u;
        }

        int cur = ns[l];

        int ans = 1 + do_solve(l + 1, r);
        for (int i = l + 1; i <= r; i++) {
            int tot = 0;
            if (cur == ns[i]) {
                ans = min(ans, do_solve(l + 1, i) + do_solve(i + 1, r));
            }
        }
        return u = ans;
    }
private:
    const vector<int>& ns;
    const int n;
};

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        printf("Case %d: %d\n", ++case_, Solution(ns).solve());
    }
    return 0;
}

/*
Case1:
1
10
4 7 2 8 7 8 9 2 3 10 

Answer: 8
*/
