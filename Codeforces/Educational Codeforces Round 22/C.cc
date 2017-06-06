#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 222222;

int n, x;
vector<int> g[SIZE];
int ans;

void dfs(int pre, int cur, int depth, vector<int>& mark) {
    mark[cur] = depth;
    for (auto item: g[cur]) {
        if (item == pre) {
            continue;
        }
        dfs(cur, item, depth + 1, mark);
    }
}

void dfs2(int pre, int cur, int depth, const vector<int>& A, const vector<int>& B) {
    if (A[cur] <= B[cur]) {
        return;
    }
    ans = max(ans, A[cur] * 2);
    for (auto item: g[cur]) {
        if (item == pre) {
            continue;
        }
        dfs2(cur, item, depth + 1, A, B);
    }
}

int main() {
    int a, b;
    input(n >> x);
    for (int i = 0; i < n - 1; i++) {
        input(a >> b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> A(n + 1);
    vector<int> B(n + 1);
    
    dfs(-1, 1, 0, A);
    dfs(-1, x, 0, B);

    ans = 0;
    dfs2(-1, x, 0, A, B);
    print(ans);
    return 0;
}
