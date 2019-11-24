#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

int n;
vector<int> g[SIZE];
vector<int> ns;

pair<llint, llint> dfs(int pre, int cur) {
    int cnt = 0;
    vector<llint> pos, neg;
    for (int i = 0; i < g[cur].size(); i++) {
        if (g[cur][i] != pre) {
            cnt++;
            auto p = dfs(cur, g[cur][i]);
            if (p.first) {
                assert(p.first > 0);
                pos.push_back(p.first);
            }

            if (p.second) {
                assert(p.second > 0);
                neg.push_back(p.second);
            }
        }
    }

    if (cnt == 0) {
        if (ns[cur] > 0) {
            return {0, ns[cur]};
        } else {
            return {-ns[cur], 0};
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    llint tp = 0;
    llint tn = 0;
    llint root = ns[cur];

    for (llint i = 0, j = 0; i < pos.size(); i++) {
        llint delta = pos[i] - j;
        root += delta;
        j = pos[i];
        tp += delta;
    }

    for (llint i = 0, j = 0; i < neg.size(); i++) {
        llint delta = neg[i] - j;
        root -= delta;
        j = neg[i];
        tn += delta;
    }

    if (root > 0) {
        tn += root;
    } else {
        tp += -root;
    }

    // print(cur << ' ' << tp << ' ' << tn);

    return {tp, tn};
}

int main() {
    input(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    auto res = dfs(-1, 0);
    print(res.first + res.second);

    return 0;
}
