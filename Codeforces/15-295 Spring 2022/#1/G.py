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

const int N = 212345;

struct Edge {
    int dest;
    int tag;
};

int n, m;
vector<int> cs[N];
vector<Edge> g[N];
vector<int> ans;
vector<bool> visited;
vector<bool> checked;
vector<int> mp[N][2];
queue<int> q;

bool dfs(int ptag, int cur, deque<int>& path) {
    assert(0 < cur && cur <= m);
    if (visited[cur]) {
        return true;
    }

    visited[cur] = true;
    path.push_back(cur);

    for (const auto& e : g[cur]) {
        int nxt = e.dest;
        int tag = e.tag;

        if (tag == -ptag) {
            continue;
        }

        // reverse the direction
        if (tag > 0) {
            ans[tag] = 0;
        } else {
            ans[-tag] = 1;
        }

        if (dfs(tag, nxt, path)) {
            return true;
        }
        ans[abs(tag)] = -1;
    }

    path.pop_back();
    return false;
}

void bfs() {
    while (!q.empty()) {
        int cur = q.front();
        // print("bfs", cur);
        q.pop();

        for (const auto& e : g[cur]) {
            int idx = e.tag;
            if (checked[e.dest]) {
                continue;
            }
            if (ans[abs(idx)] == -1) {
                if (idx > 0) {
                    ans[idx] = 1;
                } else {
                    ans[-idx] = 0;
                }
            }
            q.push(e.dest);
            checked[e.dest] = true;
        }
    }
    // print("--");
}


int main() {
    input(m, n);

    int k;
    int a, b;
    ans = vector<int>(n + 1, -1);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &a);
#ifdef __CPRUN__
            cs[i].push_back(a);
#endif

            int p = a > 0? 1: 0;
            mp[abs(a)][p].push_back(i);
        }
    }

    visited = vector<bool>(m + 1, false);
    checked = vector<bool>(m + 1, false);

    for (int i = 1; i <= n; i++) {
        if (mp[i][0].size() == 0) {
            ans[i] = 1;
            for (auto node1 : mp[i][1]) {
                q.push(node1);
                checked[node1] = true;
            }
        } else if (mp[i][1].size() == 0) {
            ans[i] = 0;
            for (auto node1 : mp[i][0]) {
                q.push(node1);
                checked[node1] = true;
            }
        } else {
            assert(mp[i][0].size() == 1);
            assert(mp[i][1].size() == 1);
            a = mp[i][0][0];
            b = mp[i][1][0];
            assert(a <= m);
            assert(b <= m);
            g[a].push_back({b, +i});
            g[b].push_back({a, -i});
        }
    }

    bool valid = true;
    for (int i = 1; i <= m; i++) {
        bfs();
        if (checked[i]) {
            continue;
        }

        deque<int> path;
        valid = dfs(INF, i, path);
        if (valid) {
            for (auto node : path) {
                q.push(node);
                checked[node] = true;
            }
        } else {
            break;
        }
    }

    if (!valid) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 1; i <= n; i++) {
            ans[i] = max(ans[i], 0);
            printf("%d", ans[i]);
        }
        puts("");
    }

#ifdef __CPRUN__
    if (valid) {
        for (int i = 1; i <= m; i++) {
            bool res = false;
            for (auto node : cs[i]) {
                int g = 0;
                if (node < 0) {
                    g = 1;
                }
                assert(ans[abs(node)] == 0 || ans[abs(node)] == 1);
                res |= g ^ ans[abs(node)];
            }
            if (!res) {
                print("clause", i, "is false");
            }
        }
    }
#endif

    return 0;
}

/*

^^^TEST^^^
2 2
2 1 -2
2 2 -1
-----
YES
11
$$$TEST$$$

^^^TEST^^^
4 3
1 1
1 2
3 -1 -2 3
1 -3
-----
NO
$$$TEST$$$


^^^^TEST^^^
5 6
2 1 2
3 1 -2 3
4 -3 5 4 6
2 -6 -4
1 5
-------
YES
100010
$$$$TEST$$$

^^^TEST^^^
5 5
3 2 3 -5
1 4
2 -1 -4
2 1 -2
2 -3 5
-----
YES
00111
$$$TEST$$$

^^^TEST^^^
11 12
1 4
3 2 3 -4
3 1 -2 5
3 -7 -8 -12
1 -3
4 8 -10 11 12
1 -6
2 7 -9
2 10 -11
2 6 9
2 -1 -5
------
YES
010110101101
$$$TEST$$$

^^^^TEST^^^
5 5
3 2 3 -5
1 4
2 -1 -4
2 1 -2
2 -3 5
----
YES
00111
$$$TEST$$$

^^^TEST^^^
10 10
1 -4
1 6
2 -7 -8
3 -3 9 4
6 -5 -6 -1 -9 8 10
1 -5
2 2 7
2 3 -10
1 1
1 -2
------
YES
1010011010
$$$TEST$$$

^^^TEST^^^
10 9
1 -1
1 8
1 -9
4 -6 9 -5 -8
1 6
2 -7 -2
2 7 3
3 -4 5 1
1 -2
2 4 -3
-----
YES
000001110
$$$TEST$$$

^^^TEST^^^
21 24
3 -21 -23 24
2 -16 18
4 3 5 -6 7
1 23
1 -18
2 -19 -24
1 15
4 8 9 11 13
3 -9 12 -13
3 -1 2 6
3 -15 16 -17
4 -2 -4 -5 -7
1 4
3 -8 -10 -14
2 21 -22
1 17
2 10 14
2 -11 -12
2 1 -3
2 20 22
2 19 -20
-----
NO
$$$TEST$$$

*/
 
