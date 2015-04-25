#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111;

int n, m;
int ans;
vector<int> g[SIZE];
char visit[SIZE];

void init() {
    ans = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
}

void do_solve(int p, int& child_num) {
    int sum = 0;
    visit[p] = 1;
    for (auto i: g[p]) {
        if (visit[i]) {
            continue;
        }
        int t = 0;
        do_solve(i, t);
        sum += t;
    }
    sum++;
    if (sum % 2 == 0) {
        ans++;
    }
    child_num = sum;
}

void solve() {
    int child_num = 0;
    do_solve(1, child_num);
}

int main() {
    int a, b;
    while (input(n >> m)) {
        init();
        for (int i = 0; i < m; i++) {
            input(a >> b); 
            g[a].push_back(b);
            g[b].push_back(a);
        }
        solve();
        print(ans - 1);
    }
    return 0;
}
