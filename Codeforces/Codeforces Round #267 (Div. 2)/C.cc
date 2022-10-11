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

vector<llint> ns;

int main() {
    int n, m, k;
    input(n, m, k);

    ns = vector<llint>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &ns[i]);
        ns[i] += ns[i - 1];
    }

    vector<llint> dp[2];
    dp[0] = vector<llint>(n + 1, 0);

    int p = 0;
    for (int i = 0; i < k; i++) {
        int q = p ^ 1;
        dp[q] = vector<llint>(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (j - m >= 0) {
                dp[q][j] = dp[p][j - m] + ns[j] - ns[j - m];
            }
            dp[q][j] = max(dp[q][j], dp[q][j - 1]);
        }
        p = q;
    }

    print(dp[p][n]);

    return 0;
}

/*

^^^TEST^^^
5 2 1
1 2 3 4 5
-----
9
$$$TEST$$$

^^^TEST^^^
7 1 3
2 10 7 18 5 33 0
-----
61
$$$TEST$$$

*/
