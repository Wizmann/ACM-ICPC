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

int solve(const string& dest, const string& src) {
    int n = dest.size();
    int m = src.size();

    int p = 0;
    int q = 0;
    while (p < n && q < m) {
        if (src[q] == dest[p]) {
            p++;
            q++;
        } else {
            q++;
        }
    }

    if (p == n) {
        return m - n;
    } else {
        return -1;
    }
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        string cur, dest;
        input(dest, cur);

        int res = solve(dest, cur);

        printf("Case #%d: ", case_ + 1);
        if (res == -1) {
            puts("IMPOSSIBLE");
        } else {
            printf("%d\n", res);
        }
    }

    return 0;
}

/*

^^^TEST^^^
2
aaaa
aaaaa
bbbbb
bbbbc
-----
Case #1: 1
Case #2: IMPOSSIBLE
$$$TEST$$$

^^^^TEST^^^
2
Ilovecoding
IIllovecoding
KickstartIsFun
kkickstartiisfun
---------
Case #1: 2
Case #2: IMPOSSIBLE
$$$TEST$$$


*/
