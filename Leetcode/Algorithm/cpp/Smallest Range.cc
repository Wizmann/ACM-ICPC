const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<
            pair<int, int>, 
            function< bool(pair<int, int>, pair<int, int>) > 
        > st([&](pair<int, int> a, pair<int, int> b) {
            if (nums[a.first][a.second] != nums[b.first][b.second]) {
                return nums[a.first][a.second] < nums[b.first][b.second];
            } else {
                return a.first < b.first;
            }
        });
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert({i, 0});
        }
        
        int ans = INF;
        vector<int> res = {-INF, -INF};
        while (true) {
            int mini = nums[st.begin()->first][st.begin()->second];
            int maxi = nums[st.rbegin()->first][st.rbegin()->second];

            if (maxi - mini < ans) {
                ans = maxi - mini;
                res = {mini, maxi};
            }
            
            if (st.begin()->second + 1 >= nums[st.begin()->first].size()) {
                break;
            } else {
                auto iter = st.begin();
                auto cur = *iter;
                st.erase(iter);
                cur.second++;
                st.insert(cur);
            }
        }
        return res;
    }
};
