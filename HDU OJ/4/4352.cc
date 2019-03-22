#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int ST = 1 << 11;
const int KK = 12;
const int LEN = 20;

typedef long long llint;

llint dp[ST][LEN][KK];

pair<int, int> inc(int status, int x) {
    assert (x < 10 && x >= 0);
    if (status == 0 && x == 0) {
        return {0, 0};
    }
    if (status & (1 << x)) {
        return {status, 0};
    }
    int y = -1;
    for (int i = 0; i < 10; i++) {
        if (status & (1 << i)) {
            if (i > x) {
                y = i;
                break;
            }
        }
    }

    if (y == -1) {
        status |= 1 << x;
        return {status, 1};
    } else {
        status ^= 1 << y;
        status ^= 1 << x;
        return {status, 0};
    }
}

llint dfs(const string& num, int p, int k, int status, bool lt) {
    int len = num.size() - p;
    if (lt && dp[status][len][k] != -1) {
        return dp[status][len][k];
    }

    if (k < 0) {
        return 0;
    }

    if (p == num.size()) {
        return k == 0? 1: 0;
    }

    int cur = num[p] - '0';
    llint res = 0;
    for (int i = 0; i < 10; i++) {
        if (!lt && i <= cur) { 
            pair<int, int> pp = inc(status, i);
            int ns = pp.first;
            int delta = pp.second;
            res += dfs(num, p + 1, k - delta, ns, i < cur);
        }
        if (lt) {
            pair<int, int> pp = inc(status, i);
            int ns = pp.first;
            int delta = pp.second;
            res += dfs(num, p + 1, k - delta, ns, true);
        }
    }
    if (lt) {
        return dp[status][len][k] = res;
    } else {
        return res;
    }
}

int main() {
    int T;
    input(T);
    int case_ = 1;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        llint l, r;
        int k;

        scanf("%lld%lld%d", &l, &r, &k);

        string rs = to_string(r);
        llint rv = dfs(rs, 0, k, 0, false);

        llint lv = 0;
        if (l > 1) {
            string ls = to_string(l - 1);
            lv = dfs(ls, 0, k, 0, false);
        }

        printf("Case #%d: %lld\n", case_++, rv - lv);
    }
    return 0;
}
