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

int n;
vector<int> ns;
vector<vector<int> > g;

bool solve1() {
    bool flag = false;
    for (int i = 31; i >= 0; i--) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (ns[j] & (1 << i)) {
                cnt++;
            }
        }

        if (cnt % 2 == 0) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (ns[j] & (1 << j)) {
                ns[j] = 1;
            } else {
                ns[j] = 0;
            }
        }
        flag = true;
        break;
    }
    return flag;
}

void do_solve2(int pre, int cur, bool& bt0, bool& bf0, bool& bt1, bool& bf1) {
    bt0 = bt1 = bf1 = false;
    bf0 = true;
    if (ns[cur]) {
        bt1 = true;
    } else {
        bf1 = true;
    }

    for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];

        if (next == pre) {
            continue;
        }

        bool bt0_, bf0_, bt1_, bf1_;
        do_solve2(cur, next, bt0_, bf0_, bt1_, bf1_);

        if (ns[cur] && bt0_) {
            bf1 = true;
        }

        if (!ns[cur] && bf0_) {
            bt1 = true;
        }

        if (bt0_ || bt1_) {
            bt0 = true;
        }

        if (bf0_ || bt0_) {
            bf0 = true;
        }
    }
}

bool solve2() {
    bool bt0, bf0, bt1, bf1;
    do_solve2(-1, 1, bt0, bf0, bt1, bf1);

    return bt0 || bf0;
}

int main() {
    int T;
    input(T);

    int a, b;
    while (T--) {
        input(n);

        ns = vector<int>(n + 1);
        g = vector<vector<int> >(n + 1);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        bool flag = solve1();
        
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        if (flag == false) {
            puts("D");
            continue;
        }

        flag = solve2();
        if (flag) {
            puts("Q");
        } else {
            puts("T");
        }
    }

    return 0;
}
