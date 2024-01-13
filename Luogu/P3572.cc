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

int main() {
    int n;
    input(n);

    vector<int> trees(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &trees[i]);
    }

    int q;
    input(q);

    vector<int> dp(n + 1);

    int k;
    while (q--) {
        input(k);

        fill(dp.begin(), dp.end(), INF);
        dp[1] = 0;

        deque<int> dq;
        dq.push_back(1);

        auto get_value = [&](int idx) -> pair<int, int> {
            return { dp[idx], -trees[idx] };
        };

        for (int i = 2; i <= n; i++) {
            while (!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }

            int pre = dq.front();
            dp[i] = dp[pre] + (trees[pre] <= trees[i]? 1: 0);
            // print(pre, dp[i]);

            while (!dq.empty() && get_value(i) <= get_value(dq.back())) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        print(dp[n]);
    }

    return 0;
}

/*
^^^TEST^^^
3
1 2 3
2
1
100
-----
2
1
$$$TEST$$$

^^^TEST^^^
4
1 100 2 3
2
2
100
-----
1
1
$$$TEST$$$

^^^TEST^^^
9
4 6 3 6 3 7 2 6 5
2
2
5
-----
2
1
$$$TEST$$$

*/
