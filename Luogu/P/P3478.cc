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

const int SIZE = 1234567;

vector<int> g[SIZE];
vector<llint> depthsum;
vector<llint> childcnt;
llint maxi = 0;
llint maxv = 1;

void dfs1(int pre, int cur, llint& sum, llint& cnt) {
    sum = 0;
    cnt = 1;

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }

        llint sum_ = 0;
        llint cnt_ = 0;

        dfs1(cur, nxt, sum_, cnt_);
        sum += sum_ + cnt_;
        cnt += cnt_;
    }

    depthsum[cur] = sum;
    childcnt[cur] = cnt;
    // print(cur, sum, cnt);
}

void dfs2(int pre, int cur, llint parent, llint parentcnt) {
    // print(cur, depthsum[cur] + parent);
    if (depthsum[cur] + parent > maxi) {
        maxv = cur;
        maxi = depthsum[cur] + parent;
    }

    parent += parentcnt + 1;
    parentcnt += 1;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        parent += childcnt[nxt] * 2 + depthsum[nxt];
        parentcnt += childcnt[nxt];
    }

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs2(cur, nxt, parent - (childcnt[nxt] * 2 + depthsum[nxt]), parentcnt - childcnt[nxt]);
    }
}

int main() {
    int n;
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    depthsum = vector<llint>(n + 1, 0);
    childcnt = vector<llint>(n + 1, 0);

    llint _1, _2;
    dfs1(-1, 1, _1, _2);
    dfs2(-1, 1, 0, 0);
    print(maxv);

    return 0;
}

/*

^^^TEST^^^
1
-----
1
$$$TEST$$$

^^^TEST^^^
2
1 2
-----
1
$$$TEST$$$

^^^TEST^^^
3
3 2
2 1
-----
1
$$$TEST$$$

^^^TEST^^^
6
1 2
1 3
2 4
3 5
3 6
-----
4
$$$TEST$$$

^^^TEST^^^
8
1 4
5 6
4 5
6 7
6 8
2 4
3 4
-----
7
$$$TEST$$$

*/
