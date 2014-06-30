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
const llint INF = 1LL << 49;

int info[SIZE];
int cnt[SIZE];
int dis[SIZE];
vector<int> g[SIZE];

int n, m;

void init()
{
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0, sizeof(dis));
    memset(info, 0, sizeof(info));
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
}

void deal(int v, int now)
{
    if (v == now) {
        return;
    }
    g[now].push_back(v);
    cnt[now]++;
    dis[now] += v;
}

void preload()
{
    for (int i = 0; i < m; i++) {
        int now = info[i];
        if (i - 1 >= 0) {
            int l = info[i - 1];
            deal(l, now);
        }
        if (i + 1 < m) {
            int r = info[i + 1];
            deal(r, now);
        }
    }
}

llint calc(int orig, int now)
{
    llint oans, nans;
    oans = nans = 0;
    for (auto iter = g[orig].begin(); iter != g[orig].end(); ++iter) {
        oans += abs(*iter - orig);
        nans += abs(*iter - now);
    }
    return nans - oans;
}


llint solve()
{
    llint ans = INF;
    llint baseline = 0;
    
    for (int i = 0; i + 1 < m; i++) {
        baseline += abs(info[i] - info[i + 1]);
    }
    
    // print(baseline);
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            ans = min(ans, baseline);
            continue;
        }
        nth_element(g[i].begin(), g[i].begin() + g[i].size() / 2, g[i].end());
        
        int mid = g[i][g[i].size() / 2];

        llint t = baseline + calc(i, mid);
        ans = min(ans, t);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    while (input(n >> m)) {
        init();
        for (int i = 0; i < m; i++) {
            scanf("%d", &info[i]);
        }
        preload();
        print(solve());
    }
    return 0;
}
