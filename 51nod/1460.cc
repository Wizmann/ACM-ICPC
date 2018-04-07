#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n, m;
vector<pair<llint, llint> > islands;
vector<pair<llint, llint> > segs;
multiset<int> bridges;

int main() {
    freopen("input.txt", "r", stdin);

    input(n >> m);
    islands.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &islands[i].first, &islands[i].second);
    }

    for (int i = 0; i + 1 < n; i++) {
        llint a = islands[i + 1].first - islands[i].second;
        llint b = islands[i + 1].second - islands[i].first;
        segs.push_back({a, b});
    }

    sort(segs.begin(), segs.end(), [](const pair<llint, llint>& p1, const pair<llint, llint>& p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            } else {
                return p1.first < p2.first;
            }
        });

    for (llint i = 0, b = 0; i < m; i++) {
        scanf("%lld", &b);
        bridges.insert(b);
    }
    
    bool flag = true;
    for (const auto& seg: segs) {
        auto iter = bridges.lower_bound(seg.first);
        if (iter == bridges.end()) {
            flag = false;
            break;
        } else if (*iter > seg.second) {
            flag = false;
            break;
        } else {
            bridges.erase(iter);
        }
    }

    if (flag) {
        print("YES");
    } else {
        print("NO");
    }

    return 0;
}
