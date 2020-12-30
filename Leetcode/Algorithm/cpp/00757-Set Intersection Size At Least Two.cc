class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& va, const vector<int>& vb) {
            if (va[1] != vb[1]) {
                return va[1] < vb[1];
            } else {
                return va[0] > vb[0];
            }
        });
        
        vector<int> ms;
        for (const auto& interval: intervals) {
            int m = ms.size();
            int cnt = 0;
            for (int i = m - 1; i >= 0 && m - i <= 2; i--) {
                int u = ms[i];
                if (interval[0] <= u && u <= interval[1]) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                ms.push_back(interval[1] - 1);
                ms.push_back(interval[1]);
            }
            
            if (cnt == 1) {
                ms.push_back(interval[1]);
            }
        }
        return ms.size();
    }
};
