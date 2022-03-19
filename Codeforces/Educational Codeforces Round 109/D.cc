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

const int SIZE = 5555;

int dp[2][SIZE];

int main() {
    int n;
    input(n);

    vector<int> ns(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    memset(dp, 0, sizeof(dp));

    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (ns[i] == 0) {
            continue;
        }
        int q = p ^ 1;

        memset(dp[q], INF, sizeof(dp[q]));

        for (int j = 1; j <= n; j++) {
            if (ns[j] == 1) {
                dp[q][j] = dp[q][j - 1];
            } else {
                dp[q][j] = min(dp[q][j - 1], dp[p][j - 1] + abs(i - j));
            }
        }

        /*
        for (int j = 1; j <= n; j++) {
            printf("%d ", dp[q][j]);
        }
        puts("");
        */

        p = q;
    }

    print(dp[p][n]);

    return 0;
}

/*

^^^TEST^^^
7
1 0 0 1 0 0 1
-----
3
$$$TEST$$$

^^^TEST^^^
6
1 1 1 0 0 0
-----
9
$$$TEST$$$

^^^TEST^^^
5
0 0 0 0 0
-----
0
$$$TEST$$$

*/
