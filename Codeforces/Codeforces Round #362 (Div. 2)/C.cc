#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

map<llint, llint> mp;

llint lca(llint a, llint b) {
    set<llint> st;
    while (a) {
        st.insert(a);
        a /= 2;
    }

    while (b) {
        if (st.count(b) != 0) {
            return b;
        }
        b /= 2;
    }
    return -1;
}

void update_path(llint f, llint a, llint c) {
    while (a != f) {
        mp[a] += c;
        a /= 2;
    }
}

llint sumup_path(llint f, llint a) {
    llint res = 0;
    while (a != f) {
        res += mp[a];
        a /= 2;
    }
    return res;
}

llint sumup_path(llint f, llint a, llint b) {
    return sumup_path(f, a) + sumup_path(f, b);
}


int main() {
    int Q;
    input(Q);

    int cmd;
    llint a, b, c;
    while (Q--) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%lld%lld%lld", &a, &b, &c);
            llint f = lca(a, b);
            update_path(f, a, c);
            update_path(f, b, c);
        } else {
            scanf("%lld%lld", &a, &b);
            llint f = lca(a, b);
            printf("%lld\n", sumup_path(f, a, b));
        }
    }
    return 0;
}
