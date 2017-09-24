const int INF = 0x3f3f3f3f;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        set<int> st;

        for (int i = 0; i < n; i++) {
            int cur = flowers[i];
            auto p = st.equal_range(cur);
            
            if (p.first != st.begin()) {
                auto iter = --p.first;
                int dis = cur - *iter - 1;
                if (dis == k) {
                    return i + 1;
                }
            }
            
            if (p.second != st.end()) {
                auto iter = p.second;
                int dis = *iter - cur - 1;
                if (dis == k) {
                    return i + 1;
                }
            }
            
            st.insert(cur);
        }
        return -1;
    }
};
