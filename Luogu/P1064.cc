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

const int MAXN = 32123;

struct Item {
    int price, value, parent, id;
};

struct ItemGroup {
    Item parent;
    vector<Item> subitems;
};

map<int, ItemGroup> mp;
llint dp1[MAXN];
llint dp2[MAXN];

int main() {
    int n, m;
    input(n, m);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (c) {
            mp[c].subitems.push_back({a, b, c, i + 1});
        } else {
            mp[i + 1].parent = {a, b, c, i + 1};
        }
    }

    memset(dp1, -1, sizeof(dp1));
    dp1[0] = 0;

    for (const auto& p : mp) {
        const auto& parent = p.second.parent;
        const auto& subitems = p.second.subitems;
        memset(dp2, -1, sizeof(dp2));
        for (int i = n; i >= 0; i--) {
            if (dp1[i] < 0) {
                continue;
            }
            int nprice = i + parent.price;
            llint nvalue = 1LL * parent.price * parent.value;
            if (nprice <= n) {
                dp2[nprice] = dp1[i] + nvalue;
            }
        }

        for (const auto& item : subitems) {
            for (int i = n; i >= 0; i--) {
                if (dp2[i] < 0) {
                    continue;
                }
                int nprice = i + item.price;
                llint nvalue = 1LL * item.price * item.value;
                if (nprice <= n) {
                    dp2[nprice] = max(dp2[nprice], dp2[i] + nvalue);
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            dp1[i] = max(dp1[i], dp2[i]);
        }
    }

    llint maxi = 0;
    for (int i = n; i >= 0; i--) {
        /*
        if (dp[i] >= 0) {
            print(i, dp[i]);
        }
        */
        
        maxi = max(maxi, dp1[i]);
    }
    print(maxi);

    return 0;
}

/*

^^^TEST^^^
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
-----
2200
$$$TEST$$$

^^^TEST^^^
1000 1
800 2 0
-----
1600
$$$TEST$$$

^^^TEST^^^
1000 2
800 2 0
200 1 1
-----
1800
$$$TEST$$$

^^^TEST^^^
1000 3
800 2 0
200 1 1
200 2 1
-----
2000
$$$TEST$$$

^^^TEST^^^
1000 3
200 1 2
800 2 0
200 2 2
-----
2000
$$$TEST$$$

^^^TEST^^^
1000 4
200 1 2
800 2 0
1000 3 0
200 2 2
-----
3000
$$$TEST$$$

^^^TEST^^^
1000 4
200 1 2
800 2 0
1000 1 0
200 2 2
-----
2000
$$$TEST$$$

^^^TEST^^^
1000 4
200 2 2
800 2 0
1000 1 0
200 1 2
-----
2000
$$$TEST$$$

^^^TEST^^^
1000 3
200 1 2
500 2 0
200 2 2
-----
1600
$$$TEST$$$

^^^TEST^^^
1000 4
200 2 2
800 2 0
1000 1 0
200 1 2
-----
2000
$$$TEST$$$

^^^TEST^^^
1000 4
500 3 0
500 2 0
500 2 1
500 5 2
-----
3500
$$$TEST$$$

*/
