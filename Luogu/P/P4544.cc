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

const int MAXN = 555;
const int MAXK = 123456;

struct Shop {
    int pos, stock, price;
};

int K, E, N;

int main() {
    int K, E, N;
    input(K, E, N);

    vector<Shop> shops(N + 1);
    shops[0] = {0, 0, 0};

    for (int i = 1; i <= N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        shops[i] = {a, b, c};
    }
    shops.push_back({E, 0, 0});

    sort(shops.begin(), shops.end(), [](const Shop& s1, const Shop& s2) {
         return s1.pos < s2.pos;
    });

    vector<llint> dp[2];
    dp[1] = vector<llint>(MAXK, INFLL);
    dp[1][0] = 0;

    int p = 1;

    for (int i = 1; i <= N + 1; i++) {
        int q = p ^ 1;
        dp[q] = vector<llint>(MAXK, INFLL);

        int delta = shops[i].pos - shops[i - 1].pos;
        assert(delta >= 0);

        deque<pair<llint, int> > dq;

        for (int j = 0; j <= K; j++) {
            assert(j < MAXK);
            while (!dq.empty() && j - dq.front().second > shops[i].stock) {
                dq.pop_front();
            }
            if (dp[p][j] < INFLL) {
                pair<llint, int> nxt = {
                    dp[p][j] + 1LL * j * j * delta - 1LL * j * shops[i].price,
                    j};
                while (!dq.empty() && dq.back() >= nxt) {
                    dq.pop_back();
                }
                dq.push_back(nxt);
            }
            if (dq.empty()) {
                continue;
            }
            dp[q][j] = dq.front().first + 1LL * j * shops[i].price;
            // print(i, j, dp[q][j]);
            assert(dp[q][j] >= 0);
        }

        p ^= 1;
    }

    print(dp[p][K]);

    return 0;
}

/*
 
^^^^TEST^^^^
1 2 1
1 1 1
------
2
$$$TEST$$$

^^^TEST^^^
2 5 3
3 1 2
4 1 2
1 1 1
-----
9
$$$TEST$$$

*/
