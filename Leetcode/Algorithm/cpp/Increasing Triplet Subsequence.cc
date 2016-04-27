const int INF = 0x3f3f3f3f;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> st(3, INF);
        for (auto num: nums) {
            for (int i = 0; i < 3; i++) {
                if (num <= st[i]) {
                    st[i] = num;
                    break;
                }
            }
        }
        return st[2] != INF;
    }
};
