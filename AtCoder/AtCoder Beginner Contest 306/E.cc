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
    int n, k, q;
    input(n, k, q);

    multiset<int> st1, st2;

    for (int i = 0; i < k; i++) {
        st1.insert(0);
    }
    for (int i = k; i < n; i++) {
        st2.insert(0);
    }

    llint left = 0;
    vector<int> ns(n, 0);

    int x, y;
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &x, &y);
        x--;
        int pre = ns[x];
        ns[x] = y;

        if (st1.find(pre) != st1.end()) {
            st1.erase(st1.find(pre));
            st1.insert(y);
            left = left - pre + y;
        } else if (st2.find(pre) != st2.end()) {
            st2.erase(st2.find(pre));
            st2.insert(y);
        }

        while (n != k && *st2.rbegin() > *st1.begin()) {
            int a = *st1.begin();
            int b = *st2.rbegin();

            st1.erase(st1.begin());
            st2.erase(--st2.end());

            st1.insert(b);
            st2.insert(a);

            left = left - a + b;
        }

        printf("%lld\n", left);
    }

    return 0;
}

/*

^^^TEST^^^
4 2 10
1 5
2 1
3 3
4 2
2 10
1 0
4 0
3 1
2 0
3 0
-----
5
6
8
8
15
13
13
11
1
0
$$$TEST$$$

*/
