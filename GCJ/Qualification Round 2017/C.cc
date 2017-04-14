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

class Solution {
public:
    Solution(llint n_, llint k_): n(n_), k(k_) {
        // pass
    }

    pair<llint, llint> solve() {
        map<llint, llint> mp;

        mp[n] = 1;
        while (k) {
            llint maxi = mp.rbegin()->first;
            llint count = mp.rbegin()->second;

            if (count >= k) {
                // print(maxi / 2 << ' ' << (maxi - 1) / 2);
                return { maxi / 2, (maxi - 1) / 2 };
            }

            k -= count;
            mp.erase(mp.find(maxi));

            mp[(maxi - 1) / 2] += count;
            mp[maxi / 2] += count;
        }

        return {-1, -1};
    }

private:
    llint n, k;
};

int main() {
    pair<llint, llint> p1 = {1, 0};
    assert(Solution(4, 2).solve() == p1);

    pair<llint, llint> p2 = {1, 0};
    assert(Solution(5, 2).solve() == p2);

    pair<llint, llint> p3 = {1, 1};
    assert(Solution(6, 2).solve() == p3);

    pair<llint, llint> p4 = {0, 0};
    assert(Solution(1000, 1000).solve() == p4);

    pair<llint, llint> p5 = {500, 499};
    assert(Solution(1000, 1).solve() == p5);

    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        llint a, b;
        input(a >> b);
        auto S = Solution(a, b);
        auto p = S.solve();
        printf("Case #%d: %lld %lld\n", case_ + 1, p.first, p.second);
    }
    return 0;
}
