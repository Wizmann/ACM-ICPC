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
 
int n;
map<int, int> ps;
 
struct Node {
    int p, cnt;
};
 
vector<int> solve() {
    vector<Node> ns;
    for (const auto& p: ps) {
        ns.push_back({p.first, p.second});
    }
    int m = ns.size();
 
    if (m == 1) {
        return {0, 0, 0};
    }
 
    int gp = ns[m - 1].p;
    int g = ns[m - 1].cnt;
 
    int sp_max = -INF;
    int sp_min = INF;
    int s = 0;
 
    int idx = -1;
    for (int i = m - 2; i >= 0; i--) {
        s += ns[i].cnt;
        sp_max = max(sp_max, ns[i].p);
        sp_min = min(sp_min, ns[i].p);
 
        if (s > g) {
            idx = i - 1;
            break;
        }
    }
 
    if (s <= 0) {
        return {0, 0, 0};
    }
 
    if (idx < 0) {
        return {0, 0, 0};
    }
 
    int b = 0;
    int bp_max = -INF;
    for (int i = idx; i >= 0; i--) {
        int bb = b + ns[i].cnt;
        if ((g + s + bb) * 2 > n) {
            break;
        }
        bp_max = max(bp_max, ns[i].p);
        b = bb;
    }
 
    if (b <= 0) {
        return {0, 0, 0};
    }
 
    if (g >= s || g >= b) {
        return {0, 0, 0};
    }
 
    if ((g + s + b) * 2 > n) {
        return {0, 0, 0};
    }
 
    assert(g > 0 && s > 0 && b > 0);
    return {g, s, b};
}
 
int main() {
    int T;
    input(T);
 
    while (T--) {
        scanf("%d", &n);
        ps.clear();
 
        int a;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            ps[a]++;
        }
 
        vector<int> res = solve();
        for (auto num: res) {
            printf("%d ", num);
        }
        puts("");
    }
 
    return 0;
}
