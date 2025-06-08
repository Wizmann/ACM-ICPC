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

const int SIZE = 312345;

int n, k;
vector<llint> ns;

int main() {
    input(n, k);

    ns = vector<llint>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &ns[i]);
    }

    for (int i = n - 1; i > 0; i--) {
        ns[i] += ns[i + 1];
    }

    sort(ns.begin() + 2, ns.end(), greater<llint>());

    llint res = ns[1];
    for (int i = 2; i <= k; i++) {
        res += ns[i];
    }
    print(res);

    return 0;
}

/*

^^^TEST^^^
2 2
1 1
-----
3
$$$TEST$$$

^^^TEST^^^
5 2
-1 -2 5 -4 8
-----
15
$$$TEST$$$

^^^TEST^^^
7 6
-3 0 -1 -2 -2 -4 -1
-----
-45
$$$TEST$$$

^^^TEST^^^
4 1
3 -1 6 0
-----
8
$$$TEST$$$
*/
