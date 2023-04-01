#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

struct Seed {
    int num;
    llint len;
    int value;
    int id;
};

llint d;
int n;
int x;
vector<Seed> seeds;

llint solve() {
    seeds.push_back({0, d, 0, n});
    sort(seeds.begin(), seeds.end(),
         [](const Seed& s1, const Seed& s2) {
            return s1.len < s2.len;
        });

    multimap<int, Seed> mp;
    set<llint> scan;

    for (auto& seed : seeds) {
        scan.insert(seed.len);
    }

    llint cur = d;
    int p = 0;
    llint res = 0;
    while (!scan.empty()) {
        llint nxt = *scan.begin();
        scan.erase(scan.begin());

        while (p < n && seeds[p].len < nxt) {
            auto& seed = seeds[p];
            mp.insert({seed.value, seed});
            p++;
        }

        llint tot = 1LL * x * (cur - (d - nxt));

        while (!mp.empty() && tot) {
            auto iter = --mp.end();

            llint cnt = min<llint>(tot, iter->second.num);
            tot -= cnt;
            iter->second.num -= cnt;

            res += 1LL * cnt * iter->second.value;
            /*
            printf("D(%lld,%lld) id: %d, v:%d n:%lld\n",
                    (d - nxt), cur, iter->second.id, iter->second.value, cnt);
            */

            if (iter->second.num == 0) {
                mp.erase(iter);
            }
        }
        cur = d - nxt;
    }
    return res;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        input(d, n, x);

        seeds.clear();

        int q; // num
        llint l; // len
        int v; // value
        for (int i = 0; i < n; i++) {
            scanf("%d%lld%d", &q, &l, &v);
            seeds.push_back({q, l, v, i});
        }

        llint res = solve();
        printf("Case #%d: %lld\n", case_ + 1, res);
    }

    return 0;
}

/*

^^^TEST^^^
2
5 4 1
1 2 3
1 3 10
1 4 5
1 2 2
5 1 1
1 1 1
-----
Case #1: 18
Case #2: 1
$$$TEST$$$

^^^TEST^^^
1
5 3 4
5 2 3
2 3 10
2 4 5
-----
Case #1: 45
$$$TEST$$$

*/
