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

int main() {
    int T;
    input(T);

    while (T--) {
        int n;
        input(n);

        llint tot = 0;
        int mini = INF;
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
            tot += ns[i];
            mini = min(mini, ns[i]);
        }

        int l = 0;
        int r = mini;

        while (l <= r) {
            int m = (l + r) / 2;

            int delta = 0;
            bool flag = true;
            for (int i = 0; i < n - (n & 1); i++) {
                int cur = ns[i] - delta;
                if (cur < m) {
                    flag = false;
                    break;
                } else {
                    delta = cur - m;
                }
            }

            if (flag && n % 2 == 0 && delta) {
                flag = false;
            } else if (flag && n % 2 == 1) {
                int cur = ns[n - 1] - delta;
                if (cur < m) {
                    flag = false;
                }
            }

            if (flag) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (r == -1) {
            puts("-1");
        } else {
            print(tot - 1LL * r * n);
        }
    }

    return 0;
}

/*

^^^TEST^^^
5
3
8 10 5
6
4 6 4 4 6 4
3
0 1 0
2
1 2
3
10 9 9
-----
14
16
-1
-1
-1
$$$TEST$$$

*/
