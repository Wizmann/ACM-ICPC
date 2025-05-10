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
    int T;
    input(T);

    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        multiset<int> st1;
        multiset<int> st2;

        for (int i = 0; i < n; i++) {
            st1.insert(ns[i]);
        }

        llint right = 0;
        for (int i = 0; i < n; i++) {
            llint cur = right + *st1.rbegin();
            printf("%lld ", cur);

            st2.insert(ns[n - i - 1]);
            right += ns[n - i - 1];
            st1.erase(st1.find(ns[n - i - 1]));
        }

        puts("");
    }

    return 0;
}

/*

^^^TEST^^^
4
7
13 5 10 14 8 15 13
6
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1
42
2
7 5
-----
15 28 42 50 63 73 78 
1000000000 2000000000 3000000000 4000000000 5000000000 6000000000 
42 
7 12 
$$$TEST$$$

*/
