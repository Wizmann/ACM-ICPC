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
const llint MOD = 998244353LL;

int n;
vector<int> g[N];
vector<int> degree;

vector<int> bfs() {
    vector<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            q.push_back(i);
        }
    }
    
    size_t rem = n;

    while (!q.empty()) {
        if (q.size() == rem) {
            break;
        }

        set<int> q2;

        for (auto cur : q) {
            // print(cur);
            rem--;
            for (auto nxt : g[cur]) {
                if (degree[nxt] == 0) {
                    continue;
                }
                degree[cur]--;
                degree[nxt]--;

                q2.insert(nxt);
            }
        }

        q.clear();
        for (auto nxt : q2) {
            if (degree[nxt] <= 1) {
                q.push_back(nxt);
            }
        }
        // puts("");
    }
    return q;
}

pair<int, int> dfs(int pre, int cur) {
    pair<int, int> res = {0, 1};

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }

        auto p2 = dfs(cur, nxt);

        if (p2.first + 1 > res.first) {
            res = p2;
            res.first++;
        } else if (p2.first + 1 == res.first) {
            res.second += p2.second;
        }
    }

    return res;
}

llint solve(vector<pair<int, int> >& ps) {
    sort(ps.begin(), ps.end(), greater<pair<int, int>>());

    /*
    for (auto p : ps) {
        print(p.first, p.second);
    }
    */

    if (ps.size() <= 1) {
        return 1;
    }

    int m = ps.size();

    int v1 = ps[0].first;
    int v2 = ps[1].first;

    llint res = 0;
    if (v1 == v2) {
        vector<int> ns;
        for (int i = 0; i < m; i++) {
            if (ps[i].first != v1) {
                break;
            }
            ns.push_back(ps[i].second);
        }
        res = 1;
        for (auto num : ns) {
            res = (res * (num + 1)) % MOD;
        }
        for (auto num : ns) {
            res = (res - num + MOD) % MOD;
        }
        res = (res - 1 + MOD) % MOD;
    } else {
        res += 1LL * ps[0].second * ps[1].second % MOD;
        res %= MOD;
    }

    return res;
}

int main() {
    input(n);

    degree = vector<int>(n, 0);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);

        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    vector<int> center = bfs();
    assert(center.size() == 1 || center.size() == 2);

    llint res = 0;
    vector<pair<int, int> > ps;
    if (center.size() == 1) {
        for (auto nxt : g[center[0]]) {
            auto p = dfs(center[0], nxt);
            ps.push_back(p);
        }
        res = solve(ps);
    } else {
        auto p1 = dfs(center[0], center[1]);
        auto p2 = dfs(center[1], center[0]);
        ps.push_back(p1);
        ps.push_back(p2);
        res = solve(ps);
    }

    print(res % MOD);

    return 0;
}

/*

^^^TEST^^^
5
1 2
2 3
3 4
4 5
-----
1
$$$TEST$$$

^^^TEST^^^
5
1 2
1 3
1 4
4 5
-----
2
$$$TEST$$$

^^^TEST^^^
4
1 2
1 3
1 4
-----
4
$$$TEST$$$

*/

