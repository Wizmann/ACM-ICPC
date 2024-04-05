#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

const llint MOD = 998244353LL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 21234;

int main()
{
    int n;
    input(n);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    unordered_map<int, llint> dp[N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int delta = ns[i] - ns[j];
            dp[i][delta] = (dp[i][delta] + dp[j][delta] + 1) % MOD;
        }
    }
    llint ans = n;
    for (int i = 0; i < n; i++) {
        for (const auto& p: dp[i]) {
            ans = (ans + p.second) % MOD;
        }
    }
    print(ans);

    return 0;
}

/*
^^^TEST^^^
3
1 2 3
---
7
$$$TEST$$$
^^^TEST^^^
8
13 14 6 20 27 34 34 41 
---
50
$$$TEST$$$

^^^TEST^^^
100
90 1004 171 99 1835 108 81 117 141 126 135 144 81 153 193 81 962 162 1493 171 1780 864 297 180 532 1781 189 1059 198 333 1593 824 207 1877 216 270 225 1131 336 1875 362 234 81 288 1550 243 463 1755 252 406 261 270 279 288 1393 261 1263 297 135 333 872 234 881 180 198 81 225 306 180 90 315 81 81 198 252 81 297 1336 1140 1238 81 198 297 661 81 1372 469 1132 81 126 324 333 342 81 351 481 279 1770 1225 549 
---
11153
$$$TEST$$$
 */
