#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    freopen("a.txt", "r", stdin);
    
    int n, m;
    vector<pair<int, int> > ns;

    int a, b;

    input(n >> m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        ns.push_back({a, +1});
        ns.push_back({b, -1});
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        ns.push_back({a, +2});
        ns.push_back({b, -2});
    }
    
    sort(ns.begin(), ns.end());
    
    int pre = ns.begin()->first;
    int cntA = 0;
    int cntB = 0;
    
    int ans = 0;
    for (auto p: ns) {
        if (cntA > 0 && cntB == 0) {
            ans += p.first - pre;
        }
        pre = p.first;
        switch (p.second) {
            case +1: cntA++; break;
            case -1: cntA--; break;
            case +2: cntB++; break;
            case -2: cntB--; break;
        }
    }

    print(ans);

    return 0;
}
