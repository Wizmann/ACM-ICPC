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

const int SIZE = 123456;

vector<int> g[SIZE];
vector<int> level;

void dfs(int pre, int cur, int depth) {
    if ((int)level.size() <= depth) {
        level.push_back(0);
    }
    level[depth]++;

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs(cur, nxt, depth + 1);
    }
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        int n, q;
        scanf("%d%d", &n, &q);

        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }

        int a, b;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        level = vector<int>();
        dfs(-1, 1, 0);

        for (int i = 0; i < q; i++) {
            scanf("%d", &a);
        }

        /*
        for (auto l : level) {
            printf("%d ", l);
        }
        puts("");
        */
        
        int cnt = 0;
        for (int i = 0; i < (int)level.size(); i++) {
            if (level[i] <= q) {
                cnt += level[i];
                q-= level[i];
            } else {
                break;
            }
        }

        printf("Case #%d: %d\n", case_ + 1, cnt);
    }

    return 0;
}

/*
^^^^^TEST^^^^
2
1 1
1
3 2
1 2
1 3
1
2
-------------
Case #1: 1
Case #2: 1
$$$TEST$$$


^^^TEST^^^
2
4 4
1 2
1 3
2 4
3
3
3
3
5 2
1 2
5 3
3 1
2 4
4
5
-----
Case #1: 4
Case #2: 1
$$$TEST$$$

*/
