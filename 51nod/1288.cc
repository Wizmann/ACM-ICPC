#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n, m;
vector<int> ds, ps;

int main() {
    freopen("input.txt", "r", stdin);
    
    input(n >> m);
    ds.resize(n + 1);
    ps.resize(n + 1);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ds[i]);
        scanf("%d", &ps[i]);
    }
    ds[n] = 0;
    ps[n] = 0;

    map<int, int> mp;
    llint total = 0;
    llint cost = 0;

    for (int i = 0; i <= n; i++) {
        int d = ds[i];
        int p = ps[i];
        while (!mp.empty() && mp.rbegin()->first > p) {
            //print(total << ' ' << mp.rbegin()->second);
            cost -= 1LL * mp.rbegin()->second * mp.rbegin()->first;
            total -= mp.rbegin()->second;
            assert (total >= 0);
            mp.erase(mp.find(mp.rbegin()->first));
        }
        assert (total >= 0 && total <= m);
        mp[p] += m - total;
        cost += 1LL * p * (m - total);
        total = m;
            
        while (!mp.empty() && d) {
            int cur = mp.begin()->second;
            cur = min(d, cur);
            //print(total << ' ' << mp.begin()->first << ' ' << cur);
            d -= cur;
            mp.begin()->second -= cur;
            total -= cur;
            if (mp.begin()->second == 0) {
                mp.erase(mp.find(mp.begin()->first));
            }
        }
        
        if ( (mp.empty() && d) || total < 0 ) {
            cost = -1;
            break;
        }
    }

    print(cost);

    return 0;
}
