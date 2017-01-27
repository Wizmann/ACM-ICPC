#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

int n, q;
vector<int> pins;
set<llint> pins_set;
map<llint, int> pins_mp;

int do_solve(llint pos, llint len, int dir, int step) {
    assert(len >= 0);
    
    if (len == 0) {
        return pos;
    }
    
    // print(pos << ' ' << len << ' ' << dir);

    llint l = pos - len;
    llint r = pos + len;
    
    llint ll = *pins_set.lower_bound(l);
    llint rr = *(--pins_set.upper_bound(r));
    
    if (ll >= pos) {
        ll = INF;
    }
    if (rr <= pos) {
        rr = INF;
    }
    
    if (rr != INF) {
        if (step != 0) {
            len %= (rr - pos) * 2;
        }
        if (len >= (rr - pos)) {
            len -= (rr - pos);
            return do_solve(rr, len, -dir, step + 1);
        } else {
            assert(step != 0);
            return do_solve(pos, len, dir, step + 1);
        }
    }

    if (ll != INF) {
        if (step != 0) {
            len %= (pos - ll) * 2;
        }
        if (len >= (pos - ll)) {
            len -= (pos - ll);
            return do_solve(ll, len, -dir, step + 1);
        } else {
            assert(step != 0);
            return do_solve(pos, len, dir, step + 1);
        }
    }
    return pos;
}

int solve(int pos, int len) {
    return do_solve(pos, len, +1, 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    input(n >> q);
    pins.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pins[i]);
        pins_set.insert(pins[i]);
        pins_mp[pins[i]] = i;
    }
    
    int pos, len;
    while (q--) {
        scanf("%d%d", &pos, &len);
        int ans = solve(pins[pos - 1], len);
        printf("%d\n", pins_mp[ans] + 1);
    }
    return 0;
}
