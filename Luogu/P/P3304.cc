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

const int SIZE = 200000;

struct Edge {
    int dest, cost;
};

vector<Edge> g[SIZE];

int dfs1(int pre, int cur, llint& d) {
    int maxi = cur;
    llint maxv = 0;
    for (auto nxt : g[cur]) {
        if (pre == nxt.dest) {
            continue;
        }

        llint dd = 0;
        int p = dfs1(cur, nxt.dest, dd);
        if (dd + nxt.cost > maxv) {
            maxv = dd + nxt.cost;
            maxi = p;
        }
    }

    d = maxv;
    return maxi;
}

bool dfs2(int pre, int cur, int dest, vector<int>& path) {
    path.push_back(cur);
    if (cur == dest) {
        return true;
    }

    for (auto nxt : g[cur]) {
        if (pre == nxt.dest) {
            continue;
        }

        if (dfs2(cur, nxt.dest, dest, path)) {
            return true;
        }
    }

    path.pop_back();
    return false;
}

void dfs3(int pre, int cur, llint& maxi, int& maxicnt, map<int, pair<int, int> >& mp) {
    maxi = 0;
    maxicnt = 1;
    for (auto nxt : g[cur]) {
        if (pre == nxt.dest) {
            continue;
        }

        llint maxi_ = 0;
        int maxicnt_ = 0;
        dfs3(cur, nxt.dest, maxi_, maxicnt_, mp);

        if (maxi_ + nxt.cost > maxi) {
            maxi = maxi_ + nxt.cost;
            maxicnt = maxicnt_;
        } else if (maxi_ + nxt.cost == maxi) {
            maxicnt += maxicnt_;
        }
    }

    mp[cur] = { maxi, maxicnt };
}

int main() {
    int n;
    input(n);

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    llint d1 = 0;
    int p1 = dfs1(-1, 1, d1);

    llint d2 = 0;
    int p2 = dfs1(-1, p1, d2);

    vector<int> path2;
    dfs2(-1, p2, p1, path2);

    llint maxi1 = 0;
    int maxicnt1 = 0;
    map<int, pair<int, int> > mp1;
    dfs3(-1, p1, maxi1, maxicnt1, mp1);

    llint maxi2 = 0;
    int maxicnt2 = 0;
    map<int, pair<int, int> > mp2;
    dfs3(-1, p2, maxi2, maxicnt2, mp2);

    int m = path2.size();
    llint maxv = 0;
    int maxi = 0;
    for (int i = 0; i + 1 < m; i++) {
        int x1 = path2[i + 1];
        int x2 = path2[i];
        llint cnt = 1LL * mp1[x2].second * mp2[x1].second;
        if (cnt > maxv) {
            maxv = cnt;
            maxi = 1;
        } else if (cnt == maxv) {
            maxi++;
        }
    }

    print(d2);
    print(maxi);

    return 0;
}

/*

^^^TEST^^^
6
3 1 1000
1 4 10
4 2 100
4 5 50
4 6 100
-----
1110
2
$$$TEST$$$

^^^TEST^^^
6
3 1 1234567890
1 4 10
4 2 100
4 5 1234567890
4 6 100
-----
2469135790
3
$$$TEST$$$

*/
