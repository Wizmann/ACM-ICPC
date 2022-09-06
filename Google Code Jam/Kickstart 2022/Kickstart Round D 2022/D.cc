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

const int N = 123456;

vector<int> g[N];
set<int> g2[N];

int n, m, k;

vector<bool> visited;
int rem;

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }

    rem--;
    visited[cur] = true;

    if (rem <= 0) {
        return;
    }

    for (auto nxt : g[cur]) {
        dfs(nxt);
    }
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }

        int a, b;
        input(n, m, k);

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);

            g[b].push_back(a);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            rem = k + 1;
            visited = vector<bool>(n + 1, false);
            dfs(i);
            if (rem <= 0) {
                cnt++;
            }
        }

        printf("Case #%d: %d\n", case_ + 1, cnt);
    }

    return 0;
}

/*

^^^TEST^^^
2
3 2 1
1 2
2 3
3 3 1
1 2
2 3
3 1
-------
Case #1: 2
Case #2: 3
$$$TEST$$$

^^^TEST^^^
2
3 2 2
1 2
2 3
3 3 2
1 2
2 3
3 2
-----
Case #1: 1
Case #2: 2
$$$TEST$$$

*/


