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

int L;
int s, t, m;
vector<int> ns;

int main() {
    input(L);
    input(s, t, m);

    ns = vector<int>(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &ns[i]);
    }
    sort(ns.begin(), ns.end());

    map<int, int> mp1;
    map<int, int> mp2;
    set<int> st;

    for (int i = 1; i <= m; i++) {
        for (int j = -t; j <= t; j++) {
            if (0 <= ns[i] + j && ns[i] + j <= L + t) {
                mp1[ns[i] + j] = -1;
            }
        }
    }
    for (int i = 0; i <= t; i++) {
        mp1[0 + i] = -1;
        mp1[L + i] = -1;
        if (L - i >= 0) {
            mp1[L - i] = -1;
        }
    }

    vector<int> ps(mp1.size());

    int idx = 0;
    for (auto& p: mp1) {
        p.second = idx;
        ps[idx] = p.first;
        idx++;
    }
    assert(ps[0] == 0);
    assert(*ps.rbegin() == L + t);

    for (int i = 1; i <= m; i++) {
        st.insert(mp1[ns[i]]);
    }

    int ptr = 0;
    for (int i = 1; i < (int)ps.size(); i++) {
        while (ptr < (int)ns.size() && ps[i] > ns[ptr + 1]) {
            ptr++;
        }
        mp2[i] = ptr;
    }
    assert(ps[0] == 0);

    int n = ps.size();

    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int delta = st.count(i);
        for (int j = 0; j < i; j++) {
            if (s <= ps[i] - ps[j] && ps[i] - ps[j] <= t) {
                dp[i] = min(dp[i], dp[j] + delta);
            } else if (mp2[i] == mp2[j]) {
                int diff = ps[i] - ps[j];
                int u = diff / s;
                llint mini = u * s;
                llint maxi = u * t;
                if (mini <= diff && diff <= maxi) {
                    dp[i] = min(dp[i], dp[j] + delta);
                }
            }
        }
    }

#ifdef __CPRUN__
    for (int i = 0; i < (int)dp.size(); i++) {
        print(ps[i], dp[i], mp2[i], st.count(i));
    }
    puts("");
#endif

    int mini = INF;
    for (int i = (int)dp.size() - 1; i >= 0; i--) {
        if (ps[i] < L) {
            break;
        }
        mini = min(mini, dp[i]);
    }
    print(mini);

    return 0;
}

/*

^^^TEST^^^
10
2 3 5
2 3 5 6 7
-----
2
$$$TEST$$$

^^^TEST^^^
2
1 1 1
1
-----
1
$$$TEST$$$

^^^TEST^^^
3
1 1 2
1 2
-----
2
$$$TEST$$$

^^^TEST^^^
3
2 2 2
1 2
-----
1
$$$TEST$$$

^^^TEST^^^
3
2 100 2
1 2
-----
0
$$$TEST$$$

^^^TEST^^^
2
1 2 1
1
-----
0
$$$TEST$$$

^^^TEST^^^
1234567
1 10 1
123456
-----
0
$$$TEST$$$

*/
