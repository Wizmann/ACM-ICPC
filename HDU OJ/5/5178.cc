#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

class Solution {
public:
    Solution(int n_, int k_, vector<int>& ns_) : \
            n(n_), k(k_), ns(ns_) {
        // pass
    }

    llint solve() {
        sort(ns.begin(), ns.end());

        int l = 0;
        int r = 0;

        llint res = 0;

        while (l < n) {
            while (r < n && ns[r] - ns[l] <= k) {
                r++;
            }
            res += (r - l - 1);
            l++;
        }
        return res;
    }
private:
    int n, k;
    vector<int>& ns;
};

int main() {
    int T;
    input(T);
    while (T--) {
        int n, k;
        vector<int> ns;
        scanf("%d%d", &n, &k);
        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        printf("%lld\n", Solution(n, k, ns).solve());
    }
    return 0;
}
