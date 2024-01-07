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

struct Coin {
    int idx;
    int b, c;
};

int main() {
    int n;
    input(n);

    vector<Coin> coins(n);

    for (int i = 0; i < n; i++) {
        coins[i].idx = i;
        scanf("%d", &coins[i].b);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i].c);
    }

    int target;
    input(target);

    vector<int> dp(target + 1, INF);
    dp[0] = 0;

    for (const auto& coin : coins) {
        // print(coin.b, coin.c);
        int rem = coin.c;
        for (int i = 0; rem; i++) {
            int cur = min(1 << i, rem);
            rem -= cur;

            for (int j = target - cur * coin.b; j >= 0; j--) {
                if (dp[j] < INF) {
                    // print(j, dp[j], cur * coin.b);
                    if (dp[j + cur * coin.b] > dp[j] + cur) {
                        dp[j + cur * coin.b] = dp[j] + cur;
                    }
                }
            }
        }
    }

    print(dp[target]);

    /*
    for (int i = 0; i <= target; i++) {
        printf("%d ", dp[i]);
    }
    puts("");
    */

    vector<int> counts(n, 0);
    int cur = target;
    while (cur) {
        for (int i = 0; i < n; i++) {
            if (dp[cur] == dp[cur - coins[i].b] + 1) {
                counts[i]++;
                cur -= coins[i].b;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", counts[i]);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
3
2 3 5
2 2 1
10
-----
3
1 1 1
$$$TEST$$$

*/
