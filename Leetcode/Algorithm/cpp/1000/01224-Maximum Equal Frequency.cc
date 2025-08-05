class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        set<pair<int, int> > st;
        map<int, int> mp;
        const int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int cnt = mp[num];
            if (cnt != 0) {
                pair<int, int> p = {cnt, num};
                st.erase(st.find(p));
            }
            st.insert({cnt + 1, num});
            mp[num]++;
            
            int mini = st.begin()->first;
            int maxi = st.rbegin()->first;
            // cout << i << ' ' << mini << ' ' << maxi << ' ' << st.size() << endl;
            if (maxi == mini + 1 && mini * st.size() == i) {
                res = i + 1;
            }
            
            if (mini == 1 && maxi * (st.size() - 1) == i) {
                res = i + 1;
            }
            
            if (st.size() == 1) {
                res = i + 1;
            }
        }
        return res;
    }
};
