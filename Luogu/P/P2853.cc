#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234;

int k, n, m;
vector<int> g[SIZE];

void dfs(int pos, vector<bool>& visited, vector<int>& cnt) {
    if (visited[pos]) {
        return;
    }
    visited[pos] = true;
    cnt[pos]++;
    for (auto nxt: g[pos]) {
        dfs(nxt, visited, cnt);
    }
}

int main() {
    input(k >> n >> m);

    vector<int> cows;
    for (int i = 0; i < k; i++) {
        int cow;
        scanf("%d", &cow);
        cows.push_back(cow);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    vector<int> cnt(n + 1, 0);
    vector<bool> visited(n + 1, false);

    for (auto cow: cows) {
        visited = vector<bool>(n + 1, false);
        dfs(cow, visited, cnt);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == k) {
            res++;
        }
    }
    print(res);

    return 0;
}

/*
^^^TEST^^^
2 4 4
2
3
1 2
1 4
2 3
3 4
---
2
$$$TEST$$$
*/
