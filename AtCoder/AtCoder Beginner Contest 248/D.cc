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

const int N = 212345;

vector<int> ns[N];

int main() {
    int n;
    input(n);

    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ns[a].push_back(i);
    }

    int q;
    input(q);

    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        auto iter = lower_bound(ns[c].begin(), ns[c].end(), a);
        auto jter = upper_bound(ns[c].begin(), ns[c].end(), b);
        printf("%u\n", (int)distance(iter, jter));
    }

    return 0;
}

/*

^^^TEST^^^
5
3 1 4 1 5
7
1 5 1
2 4 3
1 5 2
1 3 3
1 1 3
10 10 100
2 4 1
-----
2
0
0
1
1
0
2
$$$TEST$$$

*/
