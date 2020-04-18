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

bool check(const vector<int>& ns, int u) {
    int n = ns.size();
    llint maxi = u == 0? 0: ((1LL << u) - 1);
    llint pre = 1LL * ns[n - 1] + maxi;

    for (int i = n - 2; i >= 0; i--) {
        llint delta = pre - ns[i];
        if (delta < 0) {
            return false;
        }

        llint cur = 1LL * ns[i] + min(maxi, delta);
        // print(ns[i] << ' ' << cur);
        assert(cur <= pre);
        pre = cur;
    }

    return true;
}

int solve(const vector<int>& ns) {
    int l = 0;
    int r = 40;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(ns, m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void test() {
    vector<int> v6 = {1000000000, 88888888, -1000000000};
    print(solve(v6));

    vector<int> v2 = {1, 2, 3, 4, 5};
    assert(check(v2, 0) == true);
    assert(solve(v2) == 0);

    vector<int> v1 = {1, 7, 6, 5};
    assert(check(v1, 0) == false);
    assert(check(v1, 1) == false);
    assert(check(v1, 2) == true);

    assert(solve(v1) == 2);


    vector<int> v3 = {0, -4};
    assert(solve(v3) == 3);

    vector<int> v4 = {-10, 10, 2, 100};
    for (int i = 0; i < 4; i++) {
        assert(check(v4, i) == false);
    }
    assert(check(v4, 4) == true);
    assert(solve(v4) == 4);

    vector<int> v5 = {-10, 10, 2, -100};
    for (int i = 0; i < 7; i++) {
        assert(check(v5, i) == false);
    }
    assert(check(v5, 8) == true);

    vector<int> v7 = {1};
    assert(solve(v7) == 0);
    
    srand(0);
    for (int case_ = 0; case_ < 100; case_++) {
        int n = rand() % 100000 + 1;
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            ns[i] = rand() % 1000000000;
            if (rand() % 2 != 0) {
                ns[i] *= -1;
            }
        }

        int u = solve(ns);
        for (int i = 0; i < u; i++) {
            assert(check(ns, i) == false);
        }
        assert(check(ns, u) == true);
    }
    puts("OK");
}

int main() {
    // test();

    int T;
    input(T);
    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        int res = solve(ns);
        printf("%d\n", res);
    }
    return 0;
}
