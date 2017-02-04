#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

class Solution {
public:
    Solution(int n_, llint q_, vector<int> ns_): n(n_), q(q_), ns(ns_) {
        // pass
    }
    
    int solve() {
        int l = 1;
        int r = n;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (_solve(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (r > n) {
            return -1;
        }
        return l;
    }
private:
    bool _solve(int m) {
        int step = 1;
        llint tot = 0;
        priority_queue<int> pq;
        for (int i = 0; i < m; i++) {
            pq.push(ns[i]);
        }
        
        for (int i = m; i < n; i++) {
            int cur = pq.top();
            pq.pop();
            tot += 1LL * step * cur;
            step++;
            pq.push(ns[i]);
        }
        
        while (!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            tot += 1LL * step * cur;
            step++;
        }
        
        return tot <= q;
    }
private:
    int n;
    llint q;
    vector<int> ns;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    llint q;
    vector<int> ns;
    
    input(n >> q);
    ns.resize(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    
    print(Solution(n, q, ns).solve());
    
    return 0;
}
