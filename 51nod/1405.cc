#pragma comment(linker, "/STACK:10240000,10240000") 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111111;

typedef long long llint;

int n;
vector<int> g[SIZE];
int cnt[SIZE];
llint dp[SIZE];

void init() {
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
}

void dfs0(int ptr, int pre, int depth) {
    for (auto child: g[ptr]) {
        if (child == pre) {
            continue;
        }
        
        dfs0(child, ptr, depth + 1);
        cnt[ptr] += cnt[child];
    }
    cnt[ptr]++;
    dp[1] += depth;
    return;
}

void dfs1(int ptr, int pre) {
    if (pre != -1) {
        dp[ptr] = dp[pre] + n - cnt[ptr] * 2;
    }
    
    for (auto child: g[ptr]) {
        if (child == pre) {
            continue;
        }
        
        dfs1(child, ptr);
    }
}


int main() {
    int a, b;
    input(n);
    init();
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs0(1, -1, 0);
    dfs1(1, -1);
    
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", dp[i]);
    }
    
    return 0;
}
