typedef long long llint;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const int n = weights.size();
        multiset<int> st;
        for (int i = 1; i < n; i++) {
            st.insert(weights[i - 1] + weights[i]);
        }

        llint maxi = 0;
        auto iter1 = st.rbegin();
        for (int i = 0; i < k - 1; i++) {
            maxi += *(iter1++);
        }

        llint mini = 0;
        auto iter2 = st.begin();
        for (int i = 0; i < k - 1; i++) {
            mini += *(iter2++);
        }

        return maxi - mini;       
    }
};
