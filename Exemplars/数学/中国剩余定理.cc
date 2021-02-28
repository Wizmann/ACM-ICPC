// ref: https://atcoder.jp/contests/abc193/tasks/abc193_e
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

llint exgcd(llint a, llint b, llint& x, llint& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    llint r = exgcd(b, a%b, x, y);
    llint t = y;
    y = x - (a / b) * y;
    x = t;
    return r;
}

llint fast_mul(llint a, llint b, llint p){
    llint res = 0;
    while (b) {
        if (b & 1) {
            res = (res + a) % p;
        }
        b >>= 1;
        a = (a + a) % p;
    }
    return (res % p + p) % p;
}

// Extended Chinese remainder theorem
// { x % a[i] == b[i] }
llint excrt(const vector<llint>& a, const vector<llint>& b) {
    const int n = a.size();
    assert(a.size() == b.size());
    llint a1 = a[0];
    llint b1 = b[0];
    for (int i = 1; i < n; i++) {
         llint a2 = a[i];
         llint b2 = b[i];

         llint k1,k2;
         llint d = exgcd(a1, a2, k1, k2);

         if ((b2 - b1) % d != 0) {
             return -1;
         }
         llint t = a2 / d;
         k1 = (k1 % t + t) % t;
         k1 = fast_mul((b2 - b1) / d, k1, t);
         b1 = k1 * a1 + b1;
         a1 = a1 / d * a2;
    }
    return b1;
}

llint solve(int x, int y, int p, int q) {
    llint res = INFLL;
    for (int yy = 0; yy < y; yy++) {
        for (int qq = 0; qq < q; qq++) {
            llint m1 = 2LL * x + 2LL * y;
            llint r1 = 1LL * x + yy;

            llint m2 = 1LL * p + q;
            llint r2 = 1LL * p + qq;

            llint cur = excrt({m1, m2}, {r1, r2});
            if (cur == -1) {
                continue;
            }
            res = min(res, cur);
        }
    }
    if (res >= INFLL) {
        return -1;
    }
    return res;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int x, y, p, q;
        input(x, y, p, q);

        llint res = solve(x, y, p, q);

        if (res == -1) {
            puts("infinity");
        } else {
            printf("%lld\n", res);
        }
    }

    return 0;
}

/*

^^^TEST^^^
3
5 2 7 6
1 1 3 1
999999999 1 1000000000 1
-----
20
infinity
1000000000999999999
$$$TEST$$$

*/
