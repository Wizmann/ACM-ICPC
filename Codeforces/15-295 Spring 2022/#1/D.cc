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

const int SIZE = 2020;

int main() {
    int n, m;
    input(n, m);
    vector<int> ns(n);
    vector<int> ms(m);

    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &ms[i]);
    }

    input(x);

    vector<int> dp(SIZE * SIZE, 0);

    for (int i = 0; i < m; i++) {
        int tot = 0;
        for (int j = i; j < m; j++) {
            tot += ms[j];
            int len = j - i + 1;

            dp[tot] = max(dp[tot], len);
        }
    }

    for (int i = 1; i < SIZE * SIZE; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int tot = 0;
        for (int j = i; j < n; j++) {
            tot += ns[j];
            int y = min(SIZE * SIZE - 1, x / tot);
            int len_a = j - i + 1;
            int len_b = dp[y];
            // print(i, j, y, len_a, len_b);
            res = max(res, len_a * len_b);
        }
    }

    print(res);

    return 0;
}

/*

^^^TEST^^^
3 3
1 2 3
1 2 3
9
-----
4
$$$TEST$$$

^^^TEST^^^
5 1
5 4 2 4 5
2
5
-----
1
$$$TEST$$$

^^^TEST^^^
1 5
2
5 4 2 4 5
5
-----
1
$$$TEST$$$

^^^TEST^^^
1 1
1
1
1
-----
1
$$$TEST$$$

^^^TEST^^^
2 2
1 123
234 456
2000000000
-----
4
$$$TEST$$$

^^^TEST^^^
1 1
1
2
1
-----
0
$$$TEST$$$

^^^TEST^^^
3 3
9 9 9
1 1 2
18
-----
2
$$$TEST$$$

^^^TEST^^^
3 3
9 9 9
1 1 2
36
-----
4
$$$TEST$$$

^^^TEST^^^
3 3
1 1 2
9 9 9
17
-----
1
$$$TEST$$$

*/
