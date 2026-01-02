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

llint n, k;
vector<int> ns;

int main() {
    input(n, k);
    ns.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        ns[i] *= 2;
    }
    sort(ns.begin(), ns.end());

    llint l = llint(-3e10);
    llint r = llint(3e10);

    const llint rank = 1LL * n * (n + 1) / 2 - k + 1;

    while (l <= r) {
        llint m = (l + r) / 2;

        llint cnt = upper_bound(ns.begin(), ns.end(), m) - ns.begin();
        // print(">>", m, cnt);

        int p = 0;
        int q = n - 1;
        while (p < q) {
            while (p < q && 1LL * ns[p] + ns[q] > m * 2) {
                q--;
            }
            cnt += q - p;
            // print(p, q);
            p++;
        }

        if (cnt >= rank) {
            r = m - 1;
        } else {
            l = m + 1;
        }
        // print("  ", m, cnt, rank);
    }

    if (l % 2 == 0) {
        print(l / 2);
        print(1);
    } else {
        print(l);
        print(2);
    }

    return 0;
}

/*

^^^TEST^^^
3 4
5 -2 3
-----
3
2
$$$TEST$$$

^^^TEST^^^
3 3
5 -2 3
-----
3
1
$$$TEST$$$

^^^TEST^^^
9 45
5 -1 2 -3 6 -9 7 3 2
-----
-9
1
$$$TEST$$$

*/
