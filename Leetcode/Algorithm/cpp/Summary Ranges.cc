int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        if (nums.empty()) {
            return res;
        }
        
        nums.push_back(INF);
        
        int l = -INF;
        int r = -INF;
        
        for (auto num: nums) {
            if (num - r != 1 && r != -INF) {
                if (l == r) {
                    res.push_back(to_string(l));
                } else {
                    res.push_back(
                        to_string(l) + "->" + to_string(r));
                }
                l = r = num;
            } else if (r == -INF) {
                l = r = num;
            } else {
                r = num;
            }
        }
        return res;
    }
};
