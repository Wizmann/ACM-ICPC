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

int n;
vector<int> A, B, P;
vector<pair<int, int> > res;
map<int, int> mp;

bool do_solve(int cur) {
    if (B[P[cur]] >= A[cur]) {
        return false;
    }
    int nxt = -1;
    auto iter = mp.find(cur);
    assert (iter != mp.end());
    nxt = iter->second;
    mp.erase(iter);

    iter = mp.find(P[cur]);
    mp.erase(iter);

    res.push_back({cur, nxt});
    swap(P[cur], P[nxt]);
    assert(P[cur] == cur);

    if (P[nxt] != nxt) {
        mp.insert({P[nxt], nxt});
        return do_solve(nxt);
    }
    return true;
}

int main() {
    input(n);
    A = vector<int>(n, 0);
    B = vector<int>(n, 0);
    P = vector<int>(n, 0);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
        P[i]--;
    }

    vector<pair<int, int> > ps;
    for (int i = 0; i < n; i++) {
        ps.push_back({A[i], i});
    }
    sort(ps.begin(), ps.end());

    for (int i = 0; i < n; i++) {
        if (P[i] != i) {
            mp.insert({P[i], i});
        }
    }

    for (int i = 0; i < n; i++) {
        int idx = ps[i].second;
        if (P[idx] == idx) {
            continue;
        }
        if (!do_solve(idx)) {
            break;
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (P[i] != i) {
            flag = false;
            break;
        }
    }

    if (flag) {
        print(res.size());
        for (const auto& p: res) {
            printf("%d %d\n", p.first + 1, p.second + 1);
        }
    } else {
        puts("-1");
    }

    return 0;
}

/*
^^^TEST^^^
4
3 4 8 6
5 3 1 3
3 4 2 1
----
3
3 4
1 3
4 2
$$$TEST$$$

^^^TEST^^^
4
1 2 3 4
4 3 2 1
4 3 2 1
---
-1
$$$TEST$$$

^^^TEST^^^
1
58
998244353
1
----
0
$$$TEST$$$

*/

