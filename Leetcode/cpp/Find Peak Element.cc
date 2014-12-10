class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 0) {
            return -1;
        }
        if (num.size() == 1) {
            return 0;
        }
        
        int n = num.size();
        
        if (num[0] > num[1]) {
            return 0;
        }
        if (num[n - 1] > num[n - 2]) {
            return n - 1;
        }
        
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (num[m - 1] < num[m] && num[m] > num[m + 1]) {
                return m;
            }
            if (num[m] < num[m - 1]) {
                r = m;
            } else if (num[m] < num[m + 1]) {
                l = m;
            }
        }
        // assert (false);
        return -1;
    }
};
