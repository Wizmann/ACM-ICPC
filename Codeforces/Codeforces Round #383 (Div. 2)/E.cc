#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE =  111111 * 2;

vector<int> nr;
vector<int> g[SIZE];
vector<int> color;

bool dfs(int cur, int c) {
    if (color[cur]) {
        return color[cur] == c;
    }

    color[cur] = c;

    bool res = true;
    for (auto next: g[cur]) {
        res &= dfs(next, -c);
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    input(n);

    int a, b;
    for (int i = 0; i < n; i++) {
        input(a >> b);
        nr.push_back(a);
        nr.push_back(b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < 2 * n; i += 2) {
        int cur = i + 1;
        int next = (i + 1) % (2 * n) + 1;
        g[cur].push_back(next);
        g[next].push_back(cur);
        // print(cur << ' ' << next);
    }

    color = vector<int>(2 * n + 1, 0);
    bool flag = true;
    for (int i = 1; i <= 2 * n && flag; i++) {
        if (color[i]) {
            continue;
        }

        flag &= dfs(i, 1);

    }

    if (!flag) {
        puts("-1");
    } else {
        for (int i = 0; i < n; i++) {
            int a = nr[i * 2];
            int b = nr[i * 2 + 1];
            printf("%d %d\n", color[a] == -1? 1: 2, color[b] == -1? 1: 2);
        }
    }

    return 0;
}

