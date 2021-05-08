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

#define print(x) cout << x << endl
#define input(x) cin >> x

bool check(llint n) {
    llint m = n;
    while (m) {
        llint u = m % 10;
        m /= 10;
        if (u == 0) {
            continue;
        }
        if (n % u != 0) {
            return false;
        }
    }
    return true;
}

llint solve(llint n) {
    while (!check(n)) { n++; }
    return n;
}

int main() {
#ifndef __CPRUN__
    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);
#endif
    int T;
    input(T);

    llint n;
    while (T--) {
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }

    return 0;
}

/*

^^^TEST^^^
2
1
285
-----
1
288
$$$TEST$$$

^^^TEST^^^
4
2
10
13
23
---
2
10
15
24
$$$TEST$$$

^^^TEST^^^
2
109
190
---
110
200
$$$TEST$$$

^^^TEST^^^
1
14394732498
---
14394732660
$$$TEST$$$

*/
