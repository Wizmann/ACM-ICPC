#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 111111;

int n, p;
llint board[3][SIZE];

llint range_sum(int idx, int l, int r) {
    llint lv = l - 1 >= 0? board[idx][l - 1]: 0;
    llint rv = board[idx][r];
    return rv - lv;
}

llint magic(int idx) {
    return ((range_sum(2, idx, n - 1) - range_sum(1, idx+ 1, n - 1)) % p + p) % p;
}

int main() {
    input(n >> p);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &board[i][j]);
            board[i][j] += j - 1 >= 0 ? board[i][j - 1]: 0;
        }
    }

    multiset<int> mst;
    for (int i = 0; i < n; i++) {
        mst.insert(magic(i));
    }

    llint ans = 0;
    for (int i = 0; i < n; i++) {
        llint cur = range_sum(0, 0, i) + range_sum(1, i, n - 1);
        cur %= p;
        
        //print(cur);

        auto iter = mst.lower_bound(p - cur);
        if (iter != mst.begin()) {
            --iter;
            llint x = *iter;
            ans = max(ans, (x + cur) % p);
        }

        if (!mst.empty()) {
            llint x = *mst.rbegin();
            ans = max(ans, (x + cur) % p);
        }
        mst.erase(mst.find(magic(i)));
    }
    print(ans);

    return 0;
}
