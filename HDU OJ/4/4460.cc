// Result: 2016-02-14 19:41:51	Accepted	4460	608MS	2204K	2175 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[SIZE];
vector<int> dis;
unordered_map<string, int> mp;
vector<bool> visit;

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
    mp.clear();
    dis.clear();
}

void spfa(int st) {
    queue<int> q;
    q.push(st);
    visit = vector<bool>(n);
    visit[st] = 1;
    dis = vector<int>(n, INF);
    dis[st] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visit[cur] = 0;

        for (auto next: g[cur]) {
            if (dis[next] > dis[cur] + 1) {
                dis[next] = dis[cur] + 1;
                if (!visit[next]) {
                    q.push(next);
                    visit[next] = 1;
                }
            }
        }
    }
}

void do_dfs(int cur) {
    visit[cur] = 1;
    for (auto next: g[cur]) {
        if (!visit[next]) {
            do_dfs(next);
        }
    }
}

bool dfs() {
    visit = vector<bool>(n);
    do_dfs(0);
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    while (input(n) && n) {
        init();

        string a, b;
        for (int i = 0; i < n; i++) {
            input(a);
            mp[a] = i;
        }

        input(m);

        for (int i = 0; i < m; i++) {
            input(a >> b);
            int a_ = mp[a];
            int b_ = mp[b];
            g[a_].push_back(b_);
            g[b_].push_back(a_);
        }
        
        int ans = 0;
        if (!dfs()) {
            puts("-1");
            continue;
        }
        for (int i = 0; i < n; i++) {
            spfa(i);
            for (int j = 0; j < n; j++) {
                ans = max(ans, dis[j]);
            }
        }

        print(ans);
    }
    return 0;
}
