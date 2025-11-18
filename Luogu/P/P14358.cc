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
    int n, m;
    input(n, m);

    vector<int> ns(n * m);
    for (int i = 0; i < n * m; i++) {
        scanf("%d", &ns[i]);
    }

    int cnt = 0;
    for (int i = 1; i < n * m; i++) {
        if (ns[i] > ns[0]) {
            cnt++;
        }
    }

    int x = cnt / n;
    int y = (cnt % (2 * n));
    if (y >= n) {
        y = (n - 1) - (y - n);
    }

    print(x + 1, y + 1);

    return 0;
}

/*

^^^TEST^^^
2 2
99 100 97 98
-----
1 2
$$$TEST$$$

^^^TEST^^^
2 2
98 99 100 97
-----
2 2
$$$TEST$$$

^^^TEST^^^
3 3
94 95 96 97 98 99 100 93 92
-----
3 1
$$$TEST$$$

*/
