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

const int SIZE = 111;

int n, p, q;

llint dp[SIZE][SIZE];
llint nums[SIZE];

llint dfs(int l, int r) {
    if (l == r) {
        return 0;
    }

    if (dp[l][r] != -INFLL) {
        return dp[l][r];
    }

    llint maxi = -INFLL;

    llint tot = 0;
    for (int i = l; i < r; i++) {
        tot += nums[i];
        maxi = max(maxi, tot - dfs(i + 1, r));
    }

    tot = 0;
    for (int i = r - 1; i >= l; i--) {
        tot += nums[i];
        maxi = max(maxi, tot - dfs(l, i));
    }

    // print(l, r, maxi);
    return dp[l][r] = maxi;
}

int main() {
    int n;
    while(input(n) && n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -INFLL;
            }
        }

        for (int i = 0; i < n; i++) {
            scanf("%lld", &nums[i]);
        }

        printf("%lld\n", dfs(0, n));
    }
    return 0;
}

/*

^^^TEST^^^
4
4 -10 -20 7
4
1 2 3 4
0
-----
7
10
$$$TEST$$$

*/
