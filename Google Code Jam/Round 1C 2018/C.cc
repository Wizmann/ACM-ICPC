#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x


typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;
const int DPMAX = 200;

vector<llint> dp;

int solve(int n, const vector<int>& ns) {
    dp = vector<llint>(DPMAX + 1, INF);
    dp[0] = 0;

    int res = 0;

    for (auto ant: ns) {
        for (int i = DPMAX; i >= 0; i--) {
            if (1LL * ant * 6 >= dp[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i] + ant);
                res = max(res, i + 1);
            }
        }
    }

    return res;
}

int main() {
    int T;
    input(T);
    for (int case_ = 1; case_ <= T; case_++) {
        int n;
        input(n);
        vector<int> ns(n);

        printf("Case #%d: ", case_);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        print(solve(n, ns));
    }
    return 0;
}