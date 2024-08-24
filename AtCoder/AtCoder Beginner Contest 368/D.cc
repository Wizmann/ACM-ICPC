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

vector<int> g[SIZE];
set<int> st;

int dfs(int pre, int cur) {
    int tot = 0;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        tot += dfs(cur, nxt);
    }

    if (tot) {
        return tot + 1;
    } else if (st.count(cur)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, k;
    input(n, k);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        st.insert(a);
    }

    int m = dfs(-1, *st.begin());
    print(m);

    return 0;
}

/*

^^^TEST^^^
7 3
1 2
1 3
2 4
2 5
3 6
3 7
1 3 5
-----
4
$$$TEST$$$

^^^TEST^^^
4 4
3 1
1 4
2 1
1 2 3 4
-----
4
$$$TEST$$$

^^^^^TEST^^^^
5 1
1 4
2 3
5 2
1 2
1
-----------
1
$$$TEST$$$$

*/
