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

const int MAXN = 2222;
const int MAXP = 2222;

struct Day {
    int price_buy, price_sell, max_buy, max_sell;
};

int N, P, W;
vector<Day> days;

llint dp[MAXN][MAXP];

int main() {
    input(N, P, W);
    W++;

    days.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        days[i] = {a, b, c, d};
    }

    for (int i = 0; i < MAXP; i++) {
        dp[0][i] = -INFLL;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= P; j++) {
            dp[i][j] = -INFLL;
            if (i - W >= 0) {
                dp[i][j] = dp[i - W][j];
            }
            if (j <= days[i].max_buy) {
                dp[i][j] = max(dp[i][j], -1LL * days[i].price_buy * j);
            }
        }
        deque<pair<llint, int> > dq_buy, dq_sell;
        for (int j = 1; j <= min(P, days[i].max_sell); j++) {
            llint pre = i - W >= 0? dp[i - W][j]: -INFLL;
            llint p = pre + 1LL * j * days[i].price_sell;
            pair<llint, int> nxt = { p, j };

            while (!dq_sell.empty() && dq_sell.back() <= nxt) {
                dq_sell.pop_back();
            }
            dq_sell.push_back(nxt);
        }

        for (int j = 0; j <= P; j++) {
            while (!dq_sell.empty() && dq_sell.front().second <= j) {
                dq_sell.pop_front();
            }

            while (!dq_buy.empty() && j - dq_buy.front().second > days[i].max_buy) {
                dq_buy.pop_front();
            }

            llint p_sell = -INFLL;
            if (!dq_sell.empty()) {
                p_sell = dq_sell.front().first - 1LL * j * days[i].price_sell;
            }
            llint p_buy = -INFLL;
            if (!dq_buy.empty()) {
                p_buy = dq_buy.front().first - 1LL * j * days[i].price_buy;
            }

            if (i - 1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            dp[i][j] = max(dp[i][j], p_sell);
            dp[i][j] = max(dp[i][j], p_buy);
            // print(i, j, p_sell, p_buy, dp[i][j]);

            if (j + days[i].max_sell + 1 <= P && i - W >= 0) {
                int u = j + days[i].max_sell + 1;
                pair<llint, int> nxt = {
                    dp[i - W][u] + 1LL * u * days[i].price_sell,
                    u
                };
                while (!dq_sell.empty() && dq_sell.back() <= nxt) {
                    dq_sell.pop_back();
                }
                dq_sell.push_back(nxt);
            }
            if (i - W >= 0) {
                pair<llint, int> nxt = {
                    dp[i - W][j] + 1LL * j * days[i].price_buy,
                    j
                };
                while (!dq_buy.empty() && dq_buy.back() <= nxt) {
                    dq_buy.pop_back();
                }
                dq_buy.push_back(nxt);
            }
        }
        /*
        for (int j = 0; j <= P; j++) {
            printf("%lld ", dp[i][j]);
        }
        puts("");
        */
    }

    llint maxi = 0;
    for (int i = 0; i <= N; i++) {
        maxi = max(maxi, dp[i][0]);
    }
    print(maxi);

    return 0;
}

/*
^^^TEST^^^
2 2 0
2 1 1 1
2 1 1 1
-----
0
$$$TEST$$$$

^^^TEST^^^
3 2 0
2 1 1 1
2 1 1 1
3 100 1 1
-----
98
$$$TEST$$$$

^^^TEST^^^
5 2 0
2 1 1 1
2 1 1 1
3 2 1 1
4 3 1 1
5 4 1 1
-----
3
$$$TEST$$$

^^^TEST^^^
5 2 0
2 1 1 1
3 2 1 1
2 1 1 1
4 3 1 1
5 4 1 1
-----
3
$$$TEST$$$

*/
