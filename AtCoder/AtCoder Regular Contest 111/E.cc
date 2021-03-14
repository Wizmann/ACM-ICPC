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

llint floor_sum(llint n, llint m, llint a, llint b) {
    llint ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    llint y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);

        llint maxi = (1LL * d - 2) / (c - b);

        llint u = floor_sum(maxi + 1, d, c, a);
        llint v = floor_sum(maxi + 1, d, b, a - 1);

        print(maxi - (u - v));
    }

    return 0;
}

/*

^^^TEST^^^
2
3 1 2 5
99 101 103 105
-----
1
25
$$$TEST$$$

*/
