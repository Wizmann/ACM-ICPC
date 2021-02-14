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
#include <queue>

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


const int SIZE = 212345;

struct Value {
    int mini, maxi, last;
};

vector<Value> dp1, dp2;

int main() {
    int T;
    input(T);

    while (T--) {
        int n, q;
        input(n, q);

        string s;
        input(s);

        dp1.resize(n + 1);
        dp1[0] = {0, 0, 0};

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            int cur = dp1[i - 1].last;
            if (c == '+') {
                cur += 1;
            } else {
                cur -= 1;
            }
            dp1[i].mini = min(dp1[i - 1].mini, cur);
            dp1[i].maxi = max(dp1[i - 1].maxi, cur);
            dp1[i].last = cur;
        }

        dp2.resize(n + 2);
        dp2[n + 1] = {0, 0, 0};
        for (int i = n; i >= 1; i--) {
            char c = s[i - 1];
            int delta = 0;
            if (c == '+') {
                delta = 1;
            } else {
                delta = -1;
            }
            dp2[i].mini = min(delta, dp2[i + 1].mini + delta);
            dp2[i].maxi = max(delta, dp2[i + 1].maxi + delta);
        }

        int a, b;
        while (q--) {
            input(a, b);
            int mini = min(dp1[a - 1].mini, dp1[a - 1].last + dp2[b + 1].mini);
            int maxi = max(dp1[a - 1].maxi, dp1[a - 1].last + dp2[b + 1].maxi);
            print(maxi - mini + 1);
        }
    }

    return 0;
}

/*
^^^TEST^^^
2
8 4
-+--+--+
1 8
2 8
2 5
1 1
4 10
+-++
1 1
1 2
2 2
1 3
2 3
3 3
1 4
2 4
3 4
4 4
-------
1
2
4
4
3
3
4
2
3
2
1
2
2
2
$$$TEST$$$
*/
