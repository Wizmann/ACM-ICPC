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
 
int main() {
    int T;
    input(T);
 
    while (T--) {
        int n;
        scanf("%d", &n);
        map<int, int> mp;
 
        vector<int> ps(n + 1);
 
        int a;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            mp[i] = a;
            ps[a] = i;
        }
 
        assert(mp.size() == n);
 
        vector<int> rs(n + 1);
 
        set<int> st;
        int pre = ps[1];
        for (int i = 1; i <= n; i++) {
            int l = min(pre, ps[i]);
            int r = max(pre, ps[i]);
 
            auto iter = mp.lower_bound(l);
            auto jter = mp.upper_bound(r);
 
            while (iter != jter) {
                st.insert(iter->second);
                iter = mp.erase(iter);
            }
 
            if (st.size() == i) {
                rs[i] = 1;
            }
        }
 
        string res;
        for (int i = 1; i <= n; i++) {
            res += to_string(rs[i]);
        }
 
        puts(res.c_str());
    }
 
    return 0;
}
