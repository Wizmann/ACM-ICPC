#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;
typedef unsigned long long ullint;

const int SIZE = 555;
const ullint PRIME = 23456789;
const ullint MOD = 0xdeaddeadbeefULL;

unordered_map<int, int> mp;
vector<int> g[SIZE];
int n, m, p;

void reorder(int idx) {
    int maxi = -1;
    int ptr = -1;

    for (int i = 0; i < m; i++) {
        int prev = g[idx][(i - 1 + m) % m];
        int cur = g[idx][i];
        int delta = ((cur - prev) % p + p) % p;
        if (delta > maxi) {
            maxi = delta;
            ptr = i;
        }
    }

    int base = g[idx][ptr];
    for (int i = 0; i < m; i++) {
        g[idx][i] = (g[idx][i] - base + p) % p;
    }
    sort(g[idx].begin(), g[idx].end());
}

void prepare() {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = g[i][j];
            if (mp.find(u) == mp.end()) {
                mp[u] = ++idx;
            }
        }
    }
}

ullint get_hash(int idx) {
    ullint res = 0;
    for (int i = 0; i < m; i++) {
        int u = g[idx][i];
        res = ((res * PRIME) % MOD + u) % MOD;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int x;
    input(n >> m >> p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            g[i].push_back(x);
        }
        sort(g[i].begin(), g[i].end());
        reorder(i);
    }

    prepare();

    unordered_map<ullint, int> mp;
    for (int i = 0; i < n; i++) {
        auto u = get_hash(i);
        mp[u]++;
    }

    llint ans = 0;
    for (auto p: mp) {
        ans += 1LL * p.second * (p.second - 1) / 2;
    }
    print(ans);

    return 0;
}
