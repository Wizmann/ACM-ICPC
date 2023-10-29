#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

struct State {
    llint cnt = 0;
    llint length = 0;
};

int main() {
    int n;
    input(n);
    vector<int> ns(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
        mp[ns[i]] = -1;
    }

    int m = mp.size();
    int idx = 1;
    for (auto& p : mp) {
        p.second = idx++;
    }
    for (int i = 1; i <= n; i++) {
        assert(mp.count(ns[i]));
        ns[i] = mp[ns[i]];
    }

    vector<State> dp = vector<State>(m + 2);
    for (int i = 0; i <= m + 1; i++) {
        dp[i].cnt = 0;
    }

    for (int i = 1; i <= n; i++) {
        llint maxlen = 0;
        llint maxcnt = 0;
        for (int j = ns[i] + 1; j <= m + 1; j++) {
            llint curlen = dp[j].length + 1;
            llint curcnt = dp[j].cnt;
            if (curcnt == 0) {
                curcnt = 1;
            }

            if (curlen > maxlen) {
                maxlen = curlen;
                maxcnt = curcnt;
            } else if (curlen == maxlen) {
                if (dp[j].cnt > 0) {
                    maxcnt += curcnt;
                } else {
                    maxcnt = max(maxcnt, 1LL);
                }
            }
        }
        if (maxlen == dp[ns[i]].length) {
            maxcnt -= dp[ns[i]].cnt;
        }
        // print(i, maxlen, maxcnt);
        if (dp[ns[i]].length < maxlen) {
            dp[ns[i]].length = maxlen;
            dp[ns[i]].cnt = maxcnt;
        } else if (dp[ns[i]].length == maxlen) {
            dp[ns[i]].cnt += maxcnt;
        }
    }

    llint maxlen = 0;
    for (int i = 1; i <= m; i++) {
        maxlen = max(maxlen, dp[i].length);
    }

    llint maxcnt = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[i].length == maxlen) {
            maxcnt += dp[i].cnt;
        }
    }
    
    print(maxlen, maxcnt);

    return 0;
}

/*

^^^TEST^^^
12
68 69 54 64 68 64 70 67 78 62 98 87
-----
4 2
$$$TEST$$$

^^^TEST^^^
3
4 2 2
-----
2 1
$$$TEST$$$

*/
