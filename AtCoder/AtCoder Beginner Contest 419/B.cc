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
    int Q;
    input(Q);

    int a, b;
    multiset<int> st;
    while (Q--) {
        scanf("%d", &a);

        if (a == 1) {
            scanf("%d", &b);
            st.insert(b);
        } else {
            printf("%d\n", *st.begin());
            st.erase(st.begin());
        }
    }

    return 0;
}

/*

^^^TEST^^^
5
1 6
1 7
2
1 1
2
-----
6
1
$$$TEST$$$

^^^TEST^^^
8
1 5
1 1
1 1
1 9
2
2
1 2
2
-----
1
1
2
$$$TEST$$$

*/
