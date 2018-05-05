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

const int N = 123;

int r, c, h, v;
char board[N][N];

void init() {

}

bool solve() {
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cnt += board[i][j] == '@';
        }
    }

    if (cnt == 0) {
        return true;
    }

    if (cnt % ( (h + 1) * (v + 1) ) != 0) {
        return false;
    }

    int c1 = 0;
    int cnt1 = cnt / (h + 1);
    vector<int> d1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            c1 += board[i][j] == '@';
        }

        if (c1 == cnt1) {
            d1.push_back(i);
            c1 = 0;
        } else if (c1 > cnt1) {
            // print(__LINE__);
            return false;
        }
    }

    if (c1 != 0) {
        // print(__LINE__);
        return false;
    }
    if (d1.size() != h + 1) {
        // print(__LINE__);
        return false;
    }

    int cnt2 = cnt / (h + 1) / (v + 1);
    vector<int> c2(h + 1, 0);
    vector<int> d2;
    for (int j = 0; j < c; j++) {
        int gt = 0;
        int eq = 0;
        int p = 0;

        for (int i = 0; i < r; i++) {
            c2[p] += board[i][j] == '@';

            if (i == d1[p]) {
                eq += c2[p] == cnt2;
                gt += c2[p] > cnt2;
                p++;
            }
        }

        /*
        print(">>" << gt << ' ' << eq);
        for (auto item: c2) {
            printf("%d ", item);
        }
        puts("");
        */

        if (gt > 0) {
            // print(__LINE__);
            return false;
        }
        if (eq == h + 1) {
            c2 = vector<int>(h + 1, 0);
            d2.push_back(j);
        }
    }

    if (d2.size() != v + 1) {
        // print(__LINE__);
        return false;
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);
    for (int case_ = 1; case_ <= T; case_++) {
        printf("Case #%d: ", case_);

        input(r >> c >> h >> v);

        for (int i = 0; i < r; i++) {
            scanf("%s", board[i]);
        }

        init();

        puts(solve()? "POSSIBLE": "IMPOSSIBLE");
    }
    return 0;
}