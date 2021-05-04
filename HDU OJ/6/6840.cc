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

int n, m, k;
vector<int> ns;

llint solve(const vector<int>& ns, int n, int m, int k) {
    int l = 0;
    int r = k - 1;
    llint res = 0;
    for (int i = m - 1; i < n; i++) {
        // print(">", ns[r]);
        res += ns[r];
        if ((i + 1) % m >= (m - k)) {
            l++;
            r++;
        }
    }
    return res;
}

int main() {
    int T;
    input(T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);

        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        sort(ns.begin(), ns.end());
        llint mini = solve(ns, n, m, m - k + 1);

        reverse(ns.begin(), ns.end());
        llint maxi = solve(ns, n, m, k);
        
        printf("%lld %lld\n", maxi, mini);
    }

    return 0;
}

/*
^^^TEST^^^
1
6 4 2
1 2 3 4 5 6
-----
15 10
$$$TEST$$$

^^^TEST^^^
1
5 4 2
1 2 3 4 5
----
8 6
$$$TEST$$$

^^^TEST^^^
1
5 2 2
1 2 3 4 5
----
10 6
$$$TEST$$$

^^^TEST^^^
2
5 4 3
1 2 3 4 5
8 4 3
1 2 3 4 5 6 7 8
----
6 4
24 13
$$$TEST$$$

*/

