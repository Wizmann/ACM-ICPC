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

const int N = 555;
const int MOD = int(1e9 + 7);

vector<int> g[N];


class Solution {
public:
    int goodSubtreeSum(vector<int>& vals_, vector<int>& par) {
        n = par.size();
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int p = par[i];
            g[p].push_back(i);
        }

        vals = vals_;
        heavy = vector<int>(n + 1, 0);
        ans = vector<int>(n + 1, 0);

        dfs1(-1, 0);
        dfs2(-1, 0, false);

        int res = 0;
        for (int i = 0; i <= n; i++) {
            res = (1LL * res + ans[i]) % MOD;
            // print(ans[i]);
        }
        return res;
    }
private:
    int dfs1(int pre, int cur) {
        int cnt = 1;
        int maxi = -1;
        int maxv = -1;
        for (auto nxt : g[cur]) {
            if (pre == nxt) {
                continue;
            }
            int nxtcnt = dfs1(cur, nxt);
            if (nxtcnt > maxv) {
                maxi = nxt;
                maxv = nxtcnt;
            }
            cnt += nxtcnt;
        }
        heavy[cur] = maxi;
        return cnt;
    }

    int get_bits(int x) {
        int bits = 0;
        while (x) {
            int nxt = 1 << (x % 10);
            if (bits & nxt) {
                return 0;
            }
            bits |= nxt;
            x /= 10;
        }
        return bits;
    }

    void DoAdd(int pre, int cur, int skip) {
        int bits = get_bits(vals[cur]);
        if (bits) {
            for (int i = (1 << 10) - 1; i >= 0; i--) {
                if (i & bits) {
                    continue;
                }
                int nxtval = vals[cur] + mp[i];
                int nxtbits = bits | i;

                mp[nxtbits] = max(mp[nxtbits], nxtval);
            }
        }

        for (auto nxt : g[cur]) {
            if (nxt == pre || nxt == skip) {
                continue;
            }
            DoAdd(cur, nxt, skip);
        }
    }

    void dfs2(int pre, int cur, bool keep) {
        for (auto nxt : g[cur]) {
            if (pre == nxt || nxt == heavy[cur]) {
                continue;
            }
            dfs2(cur, nxt, false);
        }

        map<int, int> premp;
        if (!keep) {
            premp = mp;
        }

        if (heavy[cur] > 0) {
            dfs2(cur, heavy[cur], true);
        }

        DoAdd(pre, cur, heavy[cur]);
        ans[cur] = get_max();

        if (!keep) {
            mp = premp;
        }
    }

    int get_max() {
        int maxi = 0;
        for (auto p : mp) {
            maxi = max(maxi, p.second);
        }
        return maxi;
    }
private:
    int n;
    vector<int> vals;
    vector<int> heavy;
    vector<int> ans;
    map<int, int> mp;
};


