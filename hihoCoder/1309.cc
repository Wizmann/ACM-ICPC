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

int n;
vector<pair<int, int> > ns;

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    
    input(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        ns.push_back({a, +i});
        ns.push_back({b, -i});
    }
    sort(ns.begin(), ns.end());
    
    int tot = 0;
    int cur = 0;
    
    for (auto wi: ns) {
        int nr = wi.second;
        
        if (nr < 0) {
            nr = -nr;
            cur--;
        } else {
            if (cur < tot) {
                cur++;
            } else {
                cur++;
                tot++;
            }
        }
    }
    print(tot);
    return 0;
}
