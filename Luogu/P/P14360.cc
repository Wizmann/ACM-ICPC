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

const int MAXI = 5123;
const int MOD = 998244353;

int main() {
    int n;
    input(n);
    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    sort(ns.begin(), ns.end());

    vector<int> dp1(MAXI + 3, 0);
    vector<int> dp2(MAXI + 3, 0);

    llint cnt = 0;
    for (int i = 0; i < n; i++) {
        int cur = ns[i];
        for (int j = cur + 1; j <= MAXI; j++) {
            cnt = (cnt + dp2[j]) % MOD;
        }

        for (int j = MAXI; j >= 0; j--) {
            int nxt = min(MAXI, j + cur);
            dp2[nxt] = (1LL * dp2[nxt] + dp2[j] + dp1[j]) % MOD;
        }

        dp1[cur]++;
    }
    print(cnt);

    return 0;
}

/*

^^^TEST^^^
3
1 2 3
-----
0
$$$TEST$$$

^^^TEST^^^
3
1 2 2
-----
1
$$$TEST$$$

^^^TEST^^^
5
1 2 3 4 5
-----
9
$$$TEST$$$

^^^TEST^^^
5
2 2 3 8 10
-----
6
$$$TEST$$$

*/
