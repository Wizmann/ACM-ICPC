#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int n, m, w;
int father[SIZE];
int weight[SIZE];
int beauty[SIZE];
int dp[2][SIZE];
map<int, vector<int> > mp;

void init() {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

void make_union(int a, int b) {
    father[find_father(b)] = find_father(a);
}

int solve() {
    int ptr = 0;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    int tot = mp.size();
    auto iter = mp.begin();

    for (int i = 0; i < tot; i++) {
        int next = ptr ^ 1;

        const auto& v = iter->second;
        ++iter;

        memset(dp[next], -1, sizeof(dp[next]));

        int sumup_bb = 0;
        int sumup_ww = 0;
        int nn = v.size();
        for (int j = 0; j <= nn; j++) {
            auto& item = v[j];

            int bb, ww;
            if (j < nn) {
                bb = beauty[item];
                ww = weight[item];
                sumup_bb += bb;
                sumup_ww += ww;
            } else {
                bb = sumup_bb;
                ww = sumup_ww;
            }

            for (int k = 0; k <= w; k++) {
                if (dp[ptr][k] != -1 && k + ww <= w) {
                    dp[next][k + ww] = 
                        max(dp[next][k + ww], dp[ptr][k] + bb);
                }
            }
        }
        for (int j = 0; j <= w; j++) {
            dp[next][j] = max(dp[next][j], dp[ptr][j]);
        }
        ptr = next;
    }

    int ans = 0;
    for (int i = 0; i <= w; i++) {
        ans = max(ans, dp[ptr][i]);
    }
    return ans;
}

int main() {
    init();

    input(n >> m >> w);
    for (int i = 0; i < n; i++) {
        input(weight[i]);
    }
    for (int i = 0; i < n; i++) {
        input(beauty[i]);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        input(a >> b);
        a -= 1;
        b -= 1;
        make_union(a, b);
    }

    for (int i = 0; i < n; i++) {
        find_father(i);
    }

    for (int i = 0; i < n; i++) {
        int f = find_father(i);
        if (mp.find(f) == mp.end()) {
            mp[f] = vector<int>();
        }
        mp[f].push_back(i);
    }

    print(solve());

    return 0;
}
