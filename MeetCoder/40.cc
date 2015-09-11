class Solution {
public:
    int makeSequence(vector<int> &a) {
            int n = a.size();
            for (int i = 0; i < n; i++) {
                a[i] -= i;
            }
            return n - lis(a);
    }
private:
    int lis(const vector<int>& a) {
        vector<int> st;
        for (auto num: a) {
            if (num <= 0) {
                continue;
            }
            if (st.empty() || num >= *st.rbegin()) {
                st.push_back(num);
            } else {
                auto iter = upper_bound(st.begin(), st.end(), num);
                *iter = num;
            }
        }
        return st.size();
    }
};
