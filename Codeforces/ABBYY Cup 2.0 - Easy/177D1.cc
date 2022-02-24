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
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);

    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
        if (i - 1 >= 0) {
            B[i] += B[i - 1];
        }
        // printf("%d ", B[i]);
    }

    for (int i = 0; i < n; i++) {
        int l = max(0, (m - 1) - ((n - 1) - i));
        int r = min(m - 1, i);

        int delta = B[r] - (l == 0? 0: B[l - 1]);

        A[i] = (A[i] + delta) % c;
        // print(i, l, r, delta);
        printf("%d ", A[i]);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
4 3 2
1 1 1 1
1 1 1
-----
0 1 1 0
$$$TEST$$$

^^^TEST^^^
3 1 5
1 2 3
4
-----
0 1 2
$$$TEST$$$

*/
