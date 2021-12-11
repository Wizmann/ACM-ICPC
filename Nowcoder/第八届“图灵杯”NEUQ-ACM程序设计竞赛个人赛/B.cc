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

int n, k;
vector<int> ns;

int solve() {
    map<int, int> mp;
    mp[0] = -1;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += ns[i];
        tot %= k;
        if (mp.count(tot)) {
            continue;
        }
        mp[tot] = i;
    }

    int res = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(tot)) {
            res = max(res, i - mp[tot]);
        }
        tot = ((tot - ns[i]) % k + k) % k;
    }
    if (res == 0) {
        res = -1;
    }
    return res;
}

int main() {
    int T;
    input(T);

    while (T--) {
        input(n, k);

        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        printf("%d", solve());
        if (T) {
            puts("");
        }
    }

    return 0;
}

/*
 *
^^^TEST^^^
1
3 3
1 2 3
-----
3
$$$TEST$$$

^^^TEST^^^
1
3 5
2 2 3
-----
2
$$$TEST$$$

^^^TEST^^^
1
10 5
2 2 2 2 2 2 2 2 4 5
-----
10
$$$TEST$$$

^^^TEST^^^
2
8 5
2 2 2 2 2 2 2 2
5 5
2 2 2 2 2
-----
5
5
$$$TEST$$$

^^^TEST^^^
4
3 3
1 2 3
3 5
1 2 3
3 7
1 2 3
1 6
5
-----
3
2
-1
-1
$$$TEST$$$

*/
