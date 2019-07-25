#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution
{
public:
    Solution(int n_, vector<int>& ns_) : n(n_), ns(ns_) {
        // pass
    }

    int solve() {
        for (int i = 0; i < n; i++) {
            ns[i] -= i;
        }

        vector<int> st;
        for (int i = 0; i < n; i++) {
            int cur = ns[i];
            auto iter = upper_bound(st.begin(), st.end(), cur);
            if (iter == st.end()) {
                st.push_back(cur);
            } else {
                *iter = cur;
            }
        }

        return n - st.size();
    }
private:
    int n;
    vector<int>& ns;
};

int main() {
    int T;
    input(T);

    int case_ = 0;

    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        printf("Case #%d:\n", ++case_); 
        printf("%d\n", Solution(n, ns).solve());
    }

    return 0;
}
