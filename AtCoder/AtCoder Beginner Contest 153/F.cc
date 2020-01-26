#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    int n, d, a;
    input(n >> d >> a);

    vector<pair<llint, llint> > ps(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &ps[i].first, &ps[i].second);
    }
    sort(ps.begin(), ps.end());

    llint tot = 0;
    llint res = 0;
    deque<pair<llint, llint> > q;

    vector<pair<llint, llint> > bombs;

    for (auto p : ps) {
        llint x = p.first;
        llint h = p.second;

        while (!q.empty()) {
            llint bx = q.begin()->first;
            llint bh = q.begin()->second;

            if (x > bx) {
                tot -= bh;
                assert(tot >= 0);
                q.pop_front();
            } else {
                break;
            }
        }

        if (h > tot) {
            llint rem = h - tot;
            assert(rem > 0);
            llint b = (rem + a - 1) / a;
            res += b;
            tot += 1LL * b * a;
            q.push_back({x + 2LL * d, 1LL * b * a});

            bombs.push_back({x + d, b});
        }
    }
    print(res);

    /*
    for (auto bomb : bombs) {
        llint pos = bomb.first;
        llint cnt = bomb.second;

        for (auto& p : ps) {
            if (p.first >= pos - d && p.first <= pos + d) {
                p.second = max(0LL, p.second - 1LL * cnt * a);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        auto p = ps[i];
        print(i << ' ' << ps[i].first << ' ' << ps[i].second);
        assert(p.second == 0);
    }
    */

    return 0;
}
