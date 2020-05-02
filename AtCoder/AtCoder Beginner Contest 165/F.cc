#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 212345;

int n;
vector<int> ns;
vector<int> res;
vector<int> g[N];

void dfs(int pre, int cur, vector<int>& lis) {
    function<void()> callback;

    if (lis.empty() || ns[cur] > lis.back()) {
        lis.push_back(ns[cur]);
        callback = [&]{ lis.pop_back(); };
    } else {
        auto iter = lower_bound(lis.begin(), lis.end(), ns[cur]);
        int idx = distance(lis.begin(), iter);
        int u = lis[idx];
        callback = [&] { lis[idx] = u; };

        lis[idx] = ns[cur];
    }

    res[cur] = lis.size();

    for (auto nxt: g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs(cur, nxt, lis);
    }

    callback();
}

int main() {
    input(n);
    ns.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> lis;

    res.resize(n + 1);
    dfs(-1, 1, lis);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}

