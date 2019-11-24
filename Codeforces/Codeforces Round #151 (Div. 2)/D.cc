#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, m;
vector<set<int> > g;
vector<int> cs;

int main() {
    input(n >> m);

    g.resize(n);
    cs.resize(n);

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        scanf("%d", &cs[i]);
        mp[cs[i]] = -1;
    }

    int idx = 0;
    for (auto kv: mp) {
        mp[kv.first] = idx++;
    }

    for (int i = 0; i < n; i++) {
        cs[i] = mp[cs[i]];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        if (cs[a] != cs[b]) {
            g[cs[a]].insert(cs[b]);
            g[cs[b]].insert(cs[a]);
        }
    }

    int maxi = 0;
    int maxv = 0;

    for (int i = 0; i < n; i++) {
        if (g[i].size() > maxi) {
            maxi = g[i].size();
            maxv = i;
        }
    }

    // print(maxi << ' ' << maxv);

    int res = -1;
    for (auto kv: mp) {
        if (kv.second == maxv) {
            res = kv.first;
        }
    }
    print(res);
    return 0;
}
