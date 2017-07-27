const double eps = 1e-6;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = -10000;
        double r = 10000;
        while (fabs(l - r) > eps) {
            double m = (l + r) / 2;
            if (solve(nums, m, k)) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
private:
    bool solve(const vector<int>& nums, double m, int k) {
        int n = nums.size();
        
        double s = 0;
        set<double> st;
        st.insert(0);
        
        double cur = 0;
        for (int i = 0; i < k; i++) {
            cur += nums[i] - m;
        }
        
        if (cur >= 0) {
            return true;
        }

        for (int i = k; i < n; i++) {
            cur += nums[i] - m;
            s += nums[i - k] - m;
            st.insert(s);
            if (cur > *st.begin()) {
                return true;
            }
        }
        return false;
    }
};
