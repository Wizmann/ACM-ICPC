#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;
const int INF = 0x3f3f3f3f;

int n, x, y;

llint inverse_num(vector<int>& ns) {
    if (ns.size() <= 1) {
        return 0;
    }

    int m = ns.size() / 2;

    vector<int> ls(ns.begin(), ns.begin() + m);
    vector<int> rs(ns.begin() + m, ns.end());

    llint res = 0;
    res += inverse_num(ls);
    res += inverse_num(rs);

    ns.clear();

    while (!ls.empty() || !rs.empty()) {
        int a = ls.empty()? -INF: *ls.rbegin();
        int b = rs.empty()? -INF: *rs.rbegin();

        if (a > b) {
            ns.push_back(a);
            res += rs.size();
            ls.pop_back();
        } else {
            ns.push_back(b);
            rs.pop_back();
        }
    }
    reverse(ns.begin(), ns.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    while (input(n >> x >> y)) {
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        llint u = inverse_num(ns);
        printf("%lld\n", 1LL * min(x, y) * u);
    }
    return 0;
}
