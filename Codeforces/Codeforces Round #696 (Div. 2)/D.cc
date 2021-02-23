#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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


void do_dp(const vector<int>& ns, vector<int>& dp) {
    const int n = ns.size();
    dp = vector<int>(n, 0);

    int pre = 0;
    for (int i = 0; i < n; i++) {
        int cur = ns[i];
        if (cur < pre) {
            pre = INF;
            dp[i] = INF;
        } else {
            dp[i] = pre;
            cur -= pre;
            pre = cur;
        }
    }
}

bool solve(vector<int>& ns) {
    const int n = ns.size();

    vector<int> dp1;
    do_dp(ns, dp1);

    vector<int> dp2;
    reverse(ns.begin(), ns.end());
    do_dp(ns, dp2);

    reverse(ns.begin(), ns.end());
    reverse(dp2.begin(), dp2.end());

    /*
    for (int i = 0; i < n; i++) {
        printf("%d ", dp1[i]);
    }
    puts("");

    for (int i = 0; i < n; i++) {
        printf("%d ", dp2[i]);
    }
    puts("");
    */

    for (int i = 0; i < n; i++) {
        int a1 = dp1[i];
        int a2 = ns[i];
        int a3 = dp2[i];
        // print(a1, a2, a3);
        if (a2 == a1 + a3) {
            return true;
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        int a1 = i - 1 >= 0? ns[i - 1] - dp1[i - 1]: 0;
        int a2 = ns[i];
        int a3 = ns[i + 1];
        int a4 = i + 2 < n? ns[i + 2] - dp2[i + 2]: 0;

        // print(a1, a2, a3, a4);

        if (a1 < 0 || a4 < 0) {
            continue;
        }

        if (a2 - a1 >= 0 && a3 - a4 >= 0 && a2 - a1 == a3 - a4) {
            return true;
        }
        swap(a2, a3);
        if (a2 - a1 >= 0 && a3 - a4 >= 0 && a2 - a1 == a3 - a4) {
            return true;
        }
    }

    return false;
}

int main() {
    int T;
    input(T);

    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        puts(solve(ns)? "YES": "NO");
    }

    return 0;
}

/*
^^^TEST^^^
1
5
2 2 2 1 3
---
YES
$$$TEST$$$

^^^TEST^^^
5
3
1 2 1
3
1 1 2
5
2 2 2 1 3
5
2100 1900 1600 3000 1600
2
2443 2445
----
YES
YES
YES
YES
NO
$$$$TEST$$$
*/
