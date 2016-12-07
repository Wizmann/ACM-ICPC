#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution {
public:
    Solution(int n_, int k_, int a_, vector<int> queries_):
            n(n_), k(k_), a(a_), queries(queries_) {
        // pass
    }
    
    int solve() {
        map<int, int> slots;
        slots[1] = n;
        int maxi = (n + 1) / (a + 1);
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            auto query = queries[i];
            auto iter = slots.upper_bound(query);
            if (iter == slots.begin()) {
                while(true) {
                    // TLE assert
                }
            }
            --iter;
            int l = iter->first;
            int r = iter->second;
            int len = r - l + 1;
            if (len >= a) {
                int l1 = l;
                int r1 = query - 1;

                int l2 = query + 1;
                int r2 = r;
                
                slots.erase(slots.find(l));
                
                maxi = maxi - (len + 1) / (a + 1);
                if (l1 <= r1) {
                    slots[l1] = r1;
                    maxi += (r1 - l1 + 1 + 1) / (a + 1);
                }
                if (l2 <= r2) {
                    slots[l2] = r2;
                    maxi += (r2 - l2 + 1 + 1) / (a + 1);
                }
                
                if (maxi < k) {
                    return i + 1;
                }
            } else {
                // pass
            }
        }
        return -1;
    }
private:
    int n, k, a;
    vector<int> queries;
};

int main() {
    int n, k, a;
    input(n >> k >> a);
    int m;
    input(m);
    vector<int> queries(m, 0);
    for (int i = 0; i < m; i++) {
        input(queries[i]);
    }
    
    Solution S(n, k, a, queries);
    print(S.solve());
    return 0;
}
