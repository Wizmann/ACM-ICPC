#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

set<int> nums[SIZE];

int solve(int x, int k, int s) {
    if (x % k != 0) {
        return -1;
    }
    set<int>& st = nums[k];

    int ans = -1;
    int v = -1;
    
    if (st.empty()) {
        return -1;
    }
    auto iter = st.upper_bound(s - x);
    if (iter == st.begin()) {
        return -1;
    }
    --iter;

    while (true) {
        int u = *iter;
        if (u + x <= s) {
            if (u + x <= ans) {
                break;
            }
            if ((u ^ x) > ans) {
                ans = u ^ x;
                v = u;
            }
        }
        if (iter == st.begin()) {
            break;
        }
        iter = prev(iter);
    }

    return v;
}

int main() {
    freopen("input.txt", "r", stdin);

    int Q;
    input(Q);

    int cmd;
    int x, k, s;

    while (Q--) {
        scanf("%d", &cmd);

        if (cmd == 1) {
            scanf("%d", &x);
            for (int i = 1; 1LL * i * i < SIZE; i++) {
                if (x % i == 0) {
                    nums[i].insert(x);
                    nums[x / i].insert(x);
                }
            }
        } else {
            scanf("%d%d%d", &x, &k, &s);
            printf("%d\n", solve(x, k, s));
        }
    }
    return 0;
}
