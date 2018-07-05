class Solution {
public:
    Solution(int N_, vector<int> blacklist_): n(N_), m(blacklist_.size()), blacklist(blacklist_) {
        sort(blacklist.begin(), blacklist.end());
        for (int i = 0; i < m; i++) { blacklist[i] -= i; }
    }
    
    int pick() {
        int u = rand() % (n - m);
        int d = upper_bound(blacklist.begin(), blacklist.end(), u) - blacklist.begin();
        return u + d;
    }
    int n, m;
    vector<int> blacklist;
};
