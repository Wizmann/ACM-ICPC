// https://codeforces.com/problemset/problem/284/D

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

void printLL(llint x) {
    puts(to_string(x).c_str());
}

map<pair<llint, int>, llint> dp;

llint dfs(llint x,
          int l,
          int n,
          const vector<int>& ns,
          set<pair<llint, int> >& visited) {
    if (x <= 0 || x > n) {
        return 0;
    }

    pair<llint, int> key = {x, l};
    if (visited.count(key) > 0) {
        return INF;
    }
    visited.insert(key);

    if (dp.count(key) > 0) {
        return dp[key];
    }

    llint nx = -1;
    llint ny = -1;
    if (l % 2 == 0) {
        nx = x + ns[x];
        ny = ns[x];
    } else {
        nx = x - ns[x];
        ny = ns[x];
    }
    dp[key] = dfs(nx, l ^ 1, n, ns, visited) + ny;
    return dp[key];
}

vector<llint> solve(int n, vector<int>& ns) {
    vector<llint> res;
    for (int i = 1; i < n; i++) {
        ns[1] = i;
        llint x = 1;
        llint y = 0;

        llint nx = x + ns[1];
        llint ny = y + ns[1];

        x = nx;
        y = ny;

        set<pair<llint, int> > visited;
        llint u = dfs(x, 1, n, ns, visited);
        llint ans = u + y;

        res.push_back(ans >= INF? -1: ans);
    }
    return res;
}

int main() {
    int n;
    input(n);

    vector<int> ns(n + 2);

    for (int i = 2; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    auto ans = solve(n, ns);
    for (auto num : ans) {
        printLL(num);
    }

    return 0;
}
