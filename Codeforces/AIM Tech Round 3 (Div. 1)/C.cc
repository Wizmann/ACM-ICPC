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

const int SIZE = 412345;

int n;
vector<int> g[SIZE];
vector<int> subsize;
vector<int> maxsub;
vector<int> ans;

int dfs1(int pre, int cur) {
    int cursize = 1;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        cursize += dfs1(cur, nxt);
    }
    return subsize[cur] = cursize;
}

int dfs2(int pre, int cur) {
    int res = subsize[cur];
    if (res > n / 2) {
        res = 0;
    }
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        res = max(res, dfs2(cur, nxt));
    }
    return maxsub[cur] = res;
}

void dfs3(int pre, int cur, int parent, int parentsub) {
    assert(parentsub <= n / 2);
    ans[cur] = true;
    if (parent > n / 2) {
        ans[cur] = false;
        ans[cur] = (parent - parentsub <= n / 2);
    }
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        if (subsize[nxt] > n / 2) {
            ans[cur] = false;
            ans[cur] = (subsize[nxt] - maxsub[nxt] <= n / 2);
        }
    }

    int tot = 0;
    multiset<int> st1, st2;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        tot += subsize[nxt];
        st1.insert(subsize[nxt]);
        st2.insert(maxsub[nxt]);
    }

    int nxtsub = parent;
    if (nxtsub > n / 2) {
        nxtsub = 0;
    }
    nxtsub = max(nxtsub, parentsub);

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        tot -= subsize[nxt];
        st1.erase(st1.find(subsize[nxt]));
        st2.erase(st2.find(maxsub[nxt]));

        int nxtsub2 = nxtsub;
        if (!st2.empty()) {
            nxtsub2 = max(nxtsub2, *st2.rbegin());
        }

        dfs3(cur, nxt, parent + tot + 1, nxtsub2);

        st1.insert(subsize[nxt]);
        st2.insert(maxsub[nxt]);
        tot += subsize[nxt];
    }
}

int main() {
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    subsize = vector<int>(n + 1, 0);
    maxsub = vector<int>(n + 1, 0);
    ans = vector<int>(n + 1, -1);

    dfs1(-1, 1);
    dfs2(-1, 1);
    dfs3(-1, 1, 0, 0);
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
3
1 2
2 3
-----
1 1 1 
$$$TEST$$$

^^^TEST^^^
5
1 2
1 3
1 4
1 5
-----
1 0 0 0 0 
$$$TEST$$$

^^^TEST^^^
7
1 2
1 3
2 4
2 5
3 6
3 7
-----
1 1 1 1 1 1 1
$$$TEST$$$

^^^TEST^^^
5
1 2
1 3
1 5
2 4
-----
1 1 1 0 1
$$$TEST$$$

^^^TEST^^^
10
1 2
1 5
5 6
1 3
3 4
2 7
7 8
2 9
9 10
-----
1 1 1 1 1 1 1 1 1 1 
$$$TEST$$$

^^^TEST^^^
8
1 2
1 3
1 4
2 5
3 6
4 7
7 8
-----
1 1 1 1 1 1 1 0 
$$$TEST$$$

*/
