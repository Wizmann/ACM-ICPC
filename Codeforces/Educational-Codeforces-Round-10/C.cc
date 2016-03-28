#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct Node {
    int l, r;
};

int n, m;
vector<int> pos;
vector<pair<int, int> > nodes;

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> m);
    pos.resize(n + 1);

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        pos[a] = i;
    }
    
    set<pair<int, int> > sp;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        int aa = min(pos[a], pos[b]);
        int bb = max(pos[a], pos[b]);
        sp.insert({aa, bb});
    }
    
    for (auto p: sp) {
        nodes.push_back(p);
    }

    sort(nodes.begin(), nodes.end(), 
            [](const pair<int, int>& na, const pair<int, int>& nb) {
                if (na.second != nb.second) {
                    return na.second < nb.second;
                }
                return na.first > nb.first;
            });
    
    /*
    for (auto p: nodes) {
        printf("%d %d\n", p.first, p.second);
    }
    puts("--");
    */

    int l = 0;
    int r = 0;
    int ptr = 0;
    llint ans = 0;

    while (r + 1 < n && l < n) {
        r++;
        while (ptr < nodes.size() && l <= r && r >= nodes[ptr].second) {
            l = max(l, nodes[ptr].first + 1);
            ptr++;
        }
        
        // print(l << ' ' << r);
        ans += (r - l + 1);
    }
    print(ans + 1);

    return 0;
}
