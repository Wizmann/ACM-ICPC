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
    int n;
    input(n);

    vector<llint> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ns[i]);
    }

    sort(ns.begin(), ns.end(), greater<llint>());

    for (int i = 1; i < n; i++) {
        ns[i] += ns[i - 1];
    }

    vector<int> mark(n + 2, 0);

    for (int i = 0; i < n - 2; i++) {
        llint cur = ns[i] - (i > 0 ? ns[i - 1]: 0);
        llint limit = 2LL * cur + (i > 0 ? ns[i - 1]: 0);
        auto iter = upper_bound(ns.begin() + i + 2, ns.end(), limit);
        if (iter == ns.end()) {
            continue;
        }
        int dis1 = iter - (ns.begin() + i) + 1;
        int dis2 = ns.end() - (ns.begin() + i);

        assert(dis1 >= 3);

        mark[dis1] += 1;
        mark[dis2 + 1] -= 1;
    }

    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        cnt += mark[i];
        if (cnt) {
            printf("%d ", i);
        }
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
6
3 11 4 20 35 3
-----
3 5 6
$$$TEST$$$

*/
