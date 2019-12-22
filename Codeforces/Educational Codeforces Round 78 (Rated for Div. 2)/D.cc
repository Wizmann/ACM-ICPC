#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
const int INF = 0x3f3f3f3f;
const int SIZE = 512345;
 
vector<int> g[SIZE];
char visit[SIZE];
 
int dfs(int cur) {
    if (visit[cur]) {
        return 0;
    }
    visit[cur] = 1;
    int tot = 0;
    for (auto nxt : g[cur]) {
        tot += dfs(nxt);
    }
    return tot + 1;
}
 
int main() {
    int n;
    input(n);
 
    vector<pair<int, int> > lines;
 
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());
 
    int edges = 0;
    map<int, int> mp;
 
    for (int i = 0; i < n; i++) {
        const auto& line = lines[i];
        int l = line.first;
        int r = line.second;
 
        auto iter = mp.lower_bound(l);
        while (iter != mp.end() && iter->first <= r) {
            g[i].push_back(iter->second);
            g[iter->second].push_back(i);
            ++iter;
            edges++;
 
            if (edges >= n) {
                break;
            }
        }
 
        if (edges >= n) {
            break;
        }
        mp[r] = i;
    }
 
    memset(visit, 0, sizeof(visit));
 
    if (edges == n - 1 && dfs(0) == n) {
        puts("YES");
    } else {
        puts("NO");
    }
 
    return 0;
}
