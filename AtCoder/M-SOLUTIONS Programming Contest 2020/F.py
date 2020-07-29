#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 200200;
const llint INF = 0x3f3f3f3f3f3f3fLL;

struct Plane {
    int x, y;
    int dir;
};

vector<int> xp[N][4];
vector<int> yp[N][4];
vector<int> lp[N * 2][4];
vector<int> rp[N * 2][4];

llint check(vector<int>& p1, vector<int>& p2) {
    llint mini = INF;
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    for (auto u: p1) {
        auto iter = lower_bound(p2.begin(), p2.end(), u);
        if (iter == p2.end()) {
            continue;
        }
        mini = min(mini, 1LL * (*iter - u));
    }
    return 5LL * mini;
}

llint check2(vector<int>& p1, vector<int>& p2) {
    llint mini = INF;
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    for (auto u: p1) {
        auto iter = lower_bound(p2.begin(), p2.end(), u);
        if (iter != p2.end()) {
            mini = min(mini, 1LL * abs(*iter - u));
        }
    }
    return 10LL * mini;
}


int main() {
    int n;
    input(n);

    int x, y;
    char dir[4];
    for (int i = 0; i < n; i++) {
        scanf("%d%d%s", &x, &y, dir);
        int u = 0;
        switch (dir[0]) {
            case 'U': u = 0; break;
            case 'R': u = 1; break;
            case 'D': u = 2; break;
            case 'L': u = 3; break;
            default: {
                 assert(false);
            }
        }

        xp[x][u].push_back(y);
        yp[y][u].push_back(x);

        rp[x + y][u].push_back(x);
        // print("rp" << ' ' << x + y << ' ' << u << ' ' << x);

        lp[x - y + N][u].push_back(x);
        // print("lp" << ' ' << x - y + N << ' ' << u << ' ' << x);
    }

    llint mini = INF;
    for (int i = 0; i < N; i++) {
        mini = min(mini, check(yp[i][1], yp[i][3]));
        mini = min(mini, check(xp[i][0], xp[i][2]));
    }
    for (int i = 0; i < N * 2; i++) {
        mini = min(mini, check2(rp[i][1], rp[i][0]));
        mini = min(mini, check2(rp[i][2], rp[i][3]));

        mini = min(mini, check2(lp[i][0], lp[i][3]));
        mini = min(mini, check2(lp[i][1], lp[i][2]));
    }

    if (mini >= INF) {
        puts("SAFE");
    } else {
        printf("%lld\n", mini);
    }

    return 0;
}

