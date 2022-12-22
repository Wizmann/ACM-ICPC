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

llint square(llint cur, llint limit) {
    cur = cur * cur;
    while (cur >= limit) {
        cur /= 10;
    }
    return cur;
}

int main() {
    int n, S;

    while (input(n, S)) {
        vector<llint> ns(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &ns[i]);
            ns[i] += ns[i - 1];
        }

        int ans = INF;
        for (int i = 1; i <= n; i++) {
            llint u = ns[i] - S;

            auto iter = upper_bound(ns.begin(), ns.begin() + i, u);
            if (iter != ns.begin()) {
                --iter;
                int idx = iter - ns.begin();
                // print(i, idx, ns[i] - ns[idx]);
                ans = min(ans, i - idx);
            }
        }
        if (ans == INF) {
            ans = 0;
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*

^^^TEST^^^
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
2 9
5 4
2 9
10 8
-----
2
3
2
1
$$$TEST$$$

*/
