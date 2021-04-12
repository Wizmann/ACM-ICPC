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

const int SIZE = 212345;

int n;
vector<int> g[SIZE];


int main() {
    input(n);

    int x, c;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &c);
        g[c].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    g[n + 1].push_back(0);

    map<int, llint> dp[2];

    dp[0][0] = 0;
    int p = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (g[i].empty()) {
            continue;
        }
        int q = p ^ 1;
        dp[q].clear();
        llint mini = *g[i].begin();
        llint maxi = *g[i].rbegin();
        for (const auto& pos : g[i]) {
            llint cur = INFLL;
            auto iter1 = dp[p].lower_bound(mini);
            {
                if (iter1 != dp[p].begin()) {
                    auto iter1_l = iter1;
                    iter1_l--;
                    cur = min(cur, iter1_l->second + (mini - iter1_l->first) + maxi - mini + maxi - pos);
                }
                if (iter1 != dp[p].end()) {
                    cur = min(cur, iter1->second + 2LL * (iter1->first - mini) + maxi - iter1->first + maxi - pos);
                }
            }

            auto iter2 = dp[p].upper_bound(maxi);
            {
                if (iter2 != dp[p].begin()) {
                    auto iter2_r = iter2;
                    iter2_r--;
                    cur = min(cur, iter2_r->second + 2LL * (maxi - iter2_r->first) + iter2_r->first - mini + pos - mini);
                }
                if (iter2 != dp[p].end()) {
                    cur = min(cur, iter2->second + (iter2->first - maxi) + maxi - mini + pos - mini);
                }
            }
            if (dp[q].count(pos) > 0) {
                dp[q][pos] = min(dp[q][pos], cur);
            } else {
                dp[q][pos] = cur;
            }
            // print(i, pos, cur);
        }
        p = q;
    }

    llint ans = INFLL;
    for (const auto& pr : dp[p]) {
        ans = min(ans, pr.second);
    }
    print(ans);

    return 0;
}

/*

^^^TEST^^^
5
2 2
3 1
1 3
4 2
5 3
----
12
$$$TEST$$$

^^^TEST^^^
9
5 5
-4 4
4 3
6 3
-5 5
-3 2
2 2
3 3
1 4
----
38
$$$TEST$$$

*/
