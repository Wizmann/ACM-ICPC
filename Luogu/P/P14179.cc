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

llint n, D, m;
vector<llint> ns;
vector<llint> ms;

int main() {
    int T;
    input(T);

    while (T--) {
        scanf("%lld%lld%lld", &n, &D, &m);

        ns.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &ns[i]);
        }

        ms = vector<llint>(n + 1, -1);

        int ptr = 1;
        llint mini = 0;

        while (ptr <= n && m > 0) {
            if (ns[ptr] == 0) {
                ms[ptr] = mini;
                if (ms[ptr] % D == 0) {
                    ms[ptr]++;
                }
            } else {
                if (mini % D) {
                    mini = (mini / D + 1) * D;
                }
                ms[ptr] = mini;
            }
            mini = ms[ptr];
            m -= ms[ptr];
            ptr++;
        }

        if (m < 0) {
            puts("No");
            continue;
        }

        ms[n] += m;
        m = 0;

        llint maxi = ms[n];
        ptr = n;
        while (ptr > 0 && m >= 0) {
            if (ns[ptr] == 1) {
                if (ms[ptr] % D) {
                    int rem = ms[ptr] % D;
                    m += rem;
                    ms[ptr] -= rem;
                } else {
                    int diff = min(m, maxi - ms[ptr]);
                    diff = (diff / D) * D;
                    ms[ptr] += diff;
                    m -= diff;
                }
            } else {
                int diff = min(m, maxi - ms[ptr]);
                if ((ms[ptr] + diff) % D == 0) {
                    diff--;
                }
                ms[ptr] += diff;
                m -= diff;
            }
            maxi = ms[ptr];
            ptr--;
        }

        if (m) {
            puts("No");
            continue;
        }

        for (int i = 1; i <= n; i++) {
            printf("%lld ", ms[i]);
        }
        puts("");
    }

    return 0;
}

/*

^^^TEST^^^
2
5 2 10
1 0 1 0 1
5 2 11
1 0 1 1 0
-----
0 1 2 3 4
No
$$$TEST$$$

^^^TEST^^^
3
3 3 12
0 1 0
3 3 13
0 1 0
3 3 12
0 1 1
-----
1 3 8
2 3 8
No
$$$TEST$$$

^^^TEST^^^
1
4 79 200
0 1 0 1
-----
No
$$$TEST$$$

^^^TEST^^^
6
4 2 10
0 1 0 1
4 2 11
0 1 0 1
4 2 12
0 1 0 1
4 2 12
0 0 0 0
4 2 13
0 0 0 0
4 2 13
0 0 0 1
-----
1 2 3 4
No
1 2 3 6
1 1 1 9
No
1 1 1 10
$$$TEST$$$

^^^^^TEST^^^^^
4
1 2 2
1
1 2 2
0
1 2 100
1
1 2 101
1
----------
2
No
100
No
$$$$$TEST$$$

^^^^^TEST^^^^^
6
2 2 100
1 1
2 2 101
1 1
3 2 101
1 0 1
3 2 101
1 1 0
5 2 102
1 1 0 0 1
8 2 10001
1 1 0 0 1 1 0 1
----------
0 100
No
0 1 100
0 0 101
0 0 1 1 100
0 0 1 1 2 2 3 9992
$$$$$TEST$$$

^^^^^TEST^^^^^
2
3 1000 1000
1 1 1
4 99 11001
1 1 0 1
----------
0 0 1000
0 0 12 10989
$$$$$TEST$$$
*/
