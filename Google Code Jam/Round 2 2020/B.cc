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

const int SIZE = 123;
const int MAXI = 1000000;

class Solution {
public:
    void init() {
        scanf("%d%d", &n, &m);

        int a, b;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &a);
            if (a > 0) {
                tick.push_back({a, i});
            } else {
                a = -a + 1;
                order.push_back({a, i});
            }
        }

        tick.push_back({0, 1}); // source 1
        tick.push_back({MAXI, SIZE}); // phony node
        
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            edges.push_back({a, b});
        }
    }

    void solve() {
        sort(tick.begin(), tick.end());
        sort(order.begin(), order.end());

        int p = 0;
        int q = 0;
        int cnt = 0;
        int v = 0;

        values.resize(SIZE + 1);

        while (p < tick.size() && q < order.size()) {
            if (cnt < order[q].first - 1) {
                v = tick[p].first + 1;
                values[tick[p].second] = tick[p].first;
                p++;
                cnt++;
            } else {
                values[order[q].second] = v;
                q++;
                if (order[q].first > order[q - 1].first) {
                    v++;
                }
                cnt++;
            }
        }
        while (p < tick.size()) {
            v = tick[p].first + 1;
            values[tick[p].second] = tick[p].first;
            p++;
            cnt++;
        }
        while (q < order.size()) {
            values[order[q].second] = v;
            v++;
            q++;
            cnt++;
        }
        /*
        for (int i = 1; i <= n; i++) {
            printf(" %d", values[i]);
        }
        puts("");
        */

        for (const auto& e : edges) {
            int a = values[e.first];
            int b = values[e.second];
            printf(" %d", max(1, abs(a - b)));
        }
        puts("");
    }

private:
    int n, m;
    vector<pair<int, int> > order;
    vector<int> orderp;
    vector<pair<int, int> > tick;
    vector<int> values;
    vector<pair<int, int> > edges;
};

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        Solution S;
        S.init();

        printf("Case #%d:", case_ + 1);
        S.solve();
    }

    return 0;
}

/*

^^^TEST^^^
3
4 4
-1 -3 -2
1 2
1 3
2 4
3 4
4 4
-1 -1 -1
1 4
1 2
1 3
2 3
3 2
-2 -1
2 3
1 3
-----
Case #1: 5 10 1 5
Case #2: 2020 2020 2020 2020
Case #3: 1000000 1000000
$$$TEST$$$

^^^TEST^^^
1
6 9
10 -2 -5 15 20
1 2
1 3
2 3
2 4
2 5
3 5
3 6
4 5
5 6
---
Case #1: 10 12 4 15 8 3 9 7 5
$$$TEST$$$

*/
