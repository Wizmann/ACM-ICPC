class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        set<pair<int, int> > st;
        const int n = A.size();
        for (int i = 0; i < n; i++) {
            int cur = A[i];
            st.insert({cur - i, i});
        }
        
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int cur = A[i];
            auto iter = st.find({cur - i, i});
            st.erase(iter);
            ans = max(ans, cur + i + st.rbegin()->first);
        }
        return ans;
    }
};
