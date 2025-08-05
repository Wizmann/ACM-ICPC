typedef long long llint;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto num : nums) {
            tot += num;
        }

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert({nums[i], i});
        }

        vector<long long> res;

        for (const auto& q : queries) {
            int idx = q[0];

            auto it = st.find({nums[idx], idx});
            if (it != st.end()) {
                tot -= nums[idx];
                st.erase(it);
            }

            int k = q[1];
            while (!st.empty() && k) {
                auto jt = st.begin();
                tot -= jt->first;
                st.erase(jt);
                k--;
            }

            res.push_back(tot);
        }
        return res;
    }
private:
    llint tot = 0;
    set<pair<int, int> > st;
};
