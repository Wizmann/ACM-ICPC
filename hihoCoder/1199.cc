#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

const int SIZE = 11111;

vector<int> g[SIZE];
vector<int> ps, qs;
int n;

pair<llint, llint> dfs(int pre, int cur) {  
    vector<pair<llint, llint> > subtrees;
    for (auto next: g[cur]) {
        if (next == pre) {
            continue;
        }
        subtrees.push_back(dfs(cur, next));
    }
    sort(subtrees.begin(), subtrees.end(), [](pair<llint, llint> a, pair<llint, llint> b) {
        return a.second != b.second? a.second > b.second: a.first < b.first;
    });
    
    llint need = ps[cur];
    llint wallet = -ps[cur] + qs[cur];
    
    for (auto subtree: subtrees) {
        wallet -= subtree.first;
        need = max(need, -wallet);
        wallet += subtree.second;
    }
    // print(cur << ' ' << need << ' ' << need + wallet);
    return {need, need + wallet};
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    ps.resize(n);
    qs.resize(n);
    for (int i = 0; i < n; i++) {
        input(ps[i] >> qs[i]);
    }
    
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        input(a >> b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    
    print(dfs(-1, 0).first);
    return 0;
}
