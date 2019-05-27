#include <cstdio>
#include <map>
#include <vector>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int JOKER = 2;
const int SUIT = 13;
const double inf = 1e100;
const int PRIME = 14;
const int MOD = 3345679;

const vector<int> MAXV = {13, 13, 13, 13};
vector<double> dp;

int myhash(const vector<int>& cur) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int v = cur[i];
        res = (1LL * res * PRIME + v) % MOD;
    }

    for (int i = 0; i < 4; i++) {
        int v = cur[i + 4];
        res = (1LL * res * 3 + v) % MOD;
    }
    return res;
}

double dfs(const vector<int>& ub, vector<int>& cur) {
    int key = myhash(cur);
    if (dp[key] >= 0) {
        return dp[key];
    }

    int delta = 0;
    for (int i = 0; i < 4; i++) {
        delta += max(ub[i] - cur[i] - cur[i + 4], 0);
    }
    if (delta == 0) {
        return dp[key] = 0;
    }

    double res = 0;

    int tot = 54 - accumulate(cur.begin(), cur.end(), 0);
    for (int i = 0; i < 4; i++) {
        int rem = MAXV[i] - cur[i];
        if (rem == 0) {
            continue;
        }
        assert(rem > 0);
        double p = 1.0 * rem / tot;
        cur[i]++;
        assert(cur[i] <= MAXV[i]);
        res += p * (dfs(ub, cur) + 1);
        cur[i]--;
    }

    double mini = inf;
    for (int i = 0; i < 4; i++) {
        int rem = 2 - accumulate(cur.begin() + 4, cur.end(), 0);
        if (rem <= 0) {
            continue;
        }
        assert(rem > 0);
        double p = 1.0 * rem / tot;
        cur[i + 4]++;
        mini = min(mini, p * (dfs(ub, cur) + 1));
        cur[i + 4]--;
    }
    if (mini >= inf) {
        mini = 0;
    }
    res += mini;
    return dp[key] = res;
}

void init() {
    dp = vector<double>(MOD, -1);
}

int main() {
    int T;
    int a, b, c, d;
    input(T);
    int case_ = 0;
    while (T--) {
        init();
        input(a >> b >> c >> d);
        vector<int> ub = {a, b, c, d};
        double res = 0;
        int delta = max(0, a - 13) + max(0, b - 13) + max(0, c - 13) + max(0, d - 13);
        if (a + b + c + d > 54) {
            res = -1;
        } else if (delta > 2) {
            res = -1;
        } else {
            vector<int> status(8, 0);
            res = dfs(ub, status);
        }
        if (res >= 0) {
            printf("Case %d: %.7f\n", ++case_, res);
        } else {
            printf("Case %d: -1\n", ++case_);
        }
    }
    return 0;
}
