#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <set> 

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int DIGIT = 10;

typedef long long llint;

struct Edge {
    int dest;
    int cost;
};

int n, k;
char dp[SIZE][DIGIT];
char visit1[SIZE];
set<int> nodes;
vector<llint> ans;

vector<Edge> g[SIZE];

void dfs1(int cur) {
    queue<pair<int, int> > q;
    q.push({cur, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        
        cur = p.first;
        int l = p.second;
        
        dp[cur][l] = 1;
        nodes.insert(cur);
        visit1[cur] = 1;

        for (auto e: g[cur]) {
            int next = e.dest;
            int cost = e.cost;

            if (dp[next][(l + cost) % 10]) {
                continue;
            }
            dp[next][(l + cost) % 10] = 1;
            q.push({next, (l + cost) % 10});
        }
    }
}

void dfs2(int cur) {
    vector<int> digits = vector<int>(10, 0);
    for (auto node: nodes) {
        for (int i = 0; i < 10; i++) {
            digits[i] += dp[node][i];
            
            if (node != cur) {
                ans[i] += dp[node][i];
            }
        }
    }
    
    
    for (auto node: nodes) {
        if (node == cur) {
            continue;
        }
        
        vector<int> tt = vector<int>(10, 0);
        for (int i = 0; i < 10; i++) {
            if (dp[node][i] == 0) {
                continue;
            }
            int mv = (10 - i) % 10;
            for (int j = 0; j < 10; j++) {
                int next = (j + mv) % 10;
                tt[next] = max(tt[next], digits[j]);
            }
            for (int j = 0; j < 10; j++) {
                int next = (j + mv) % 10;
                tt[next] -= dp[node][j];
            }
        }
        for (int i = 0; i < 10; i++) {
            ans[i] += tt[i];
        }
    }
}

int main() {
    input(n >> k);
    memset(dp, 0, sizeof(dp));

    int a, b, c;
    set<pair<int, int> > hash;
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &a, &b, &c);
        c %= 10;
        g[a].push_back({b, c});
        g[b].push_back({a, (10 - c) % 10});
    }
    
    ans.resize(10);
    
    memset(visit1, 0, sizeof(visit1));
    for (int i = 1; i <= n; i++) {
        if (visit1[i]) {
            continue;
        }
        
        nodes.clear();
        memset(dp, 0, sizeof(dp));
        dfs1(i);
        //print(i);
        dfs2(i);
    }

    for (auto item: ans) {
        print(item);
    }
    
    return 0;
}
