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

const int SIZE = 312345;

int n, m, k;

struct Edge {
    int dest, id;
};

vector<Edge> g[SIZE];
vector<int> ans;

void solve() {
    queue<int> q;
    q.push(1);

    ans = vector<int>(m, INF);
    vector<bool> visited(n + 1, false);
    vector<pair<int, int> > discnt(n + 1, {INF, 0});

    discnt[1] = {0, 1};

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;

        for (auto nxtp : g[cur]) {
            int nxt = nxtp.dest;
            int id = nxtp.id;

            if (visited[nxt]) {
                if (ans[id] == INF) {
                    ans[id] = k;
                }
                continue;
            }

            int nd = discnt[cur].first + 1;

            if (nd > discnt[nxt].first) {
                if (ans[id] == INF) {
                    ans[id] = k;
                }
                continue;
            }

            if (nd < discnt[nxt].first) {
                discnt[nxt] = { nd, 1 };
            } else if (nd == discnt[nxt].first) {
                discnt[nxt].second = 2;
            }

            ans[id] = discnt[nxt].second;
            if (!visited[nxt]) {
                q.push(nxt);
            }
        }
    }

    /*
    for (int i = 0; i < m; i++) {
        print(">>", ans[i]);
    }
    */

    for (int i = 0; i < m; i++) {
        if (ans[i] > k) {
            puts("No");
            return;
        }
    }

    puts("Yes");
    for (int i = 0; i < m; i++) {
        if (i) {
            printf(" ");
        }
        assert(0 < ans[i] && ans[i] <= k);
        printf("%d", ans[i]);
    }
    puts("");
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(n, m, k);

        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back({b, i});
        }

        solve();
    }

    return 0;
}

/*

^^^TEST^^^
2
3 2 3
1 2
2 3
2 2 1
1 2
1 2
-----
Yes
1 2
No
$$$TEST$$$

^^^TEST^^^
2
3 2 3
1 2
1 3
3 3 3
1 2
1 3
2 3
-----
Yes
1 1
Yes
1 1 3
$$$TEST$$$

^^^TEST^^^
1
2 2 1
1 1
2 2
-----
No
$$$TEST$$$

^^^TEST^^^
2
2 3 1
1 1
2 2
1 2
2 3 2
2 2
2 2
1 2
-----
Yes
1 1 1
Yes
2 2 1
$$$TEST$$$

^^^TEST^^^
4
4 4 1
1 2
1 3
2 4
3 4
4 4 2
1 2
1 3
2 4
3 4
4 5 2
1 2
1 3
2 4
3 4
1 4
4 6 2
1 2
1 3
2 4
3 4
2 4
3 4
-----
No
Yes
1 1 1 2
Yes
1 1 2 2 1
Yes
1 1 1 2 2 2
$$$TEST$$$

*/
