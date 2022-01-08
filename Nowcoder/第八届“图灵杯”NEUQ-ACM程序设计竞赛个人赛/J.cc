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

const int SIZE = 333;

int n, m;
int g[SIZE][SIZE];

int main() {
    input(n, m);

    int a, b, c;
    memset(g, -1, sizeof(g));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = c;
        g[b][a] = c;
    }

    int q;
    input(q);

    int k;
    vector<int> path;
    path.reserve(n * 2);
    llint res = INFLL;
    vector<bool> visited(n + 1, false);
    while (q--) {
        scanf("%d", &k);
        path.resize(k);
        visited = vector<bool>(n + 1, false);
        for (int i = 0; i < k; i++) {
            scanf("%d", &path[i]);
        }
        path.push_back(0);

        if (path.size() != n + 1) {
            continue;
        }

        int cur = 0;
        llint tot = 0;
        for (auto p : path) {
            if (!visited[p]) {
                visited[p] = true;
            } else {
                tot = INFLL;
                break;
            }

            if (g[cur][p] == -1) {
                tot = INFLL;
                break;
            }
            tot += g[cur][p];
            cur = p;
        }

        res = min(res, tot);
    }

    if (res == INFLL) {
        res = -1;
    }
    print(res);

    return 0;
}

/*

^^^TEST^^^
5 10
0 1 5
0 5 12
1 2 2
2 3 8
3 4 13
1 3 11
0 2 5
0 4 9
4 5 6
3 5 7
5
5 1 3 2 3 1
5 3 2 1 4 5
5 2 1 3 5 4
6 1 2 3 4 5 1
5 1 2 3 5 4
-----
37
$$$TEST$$$

*/
