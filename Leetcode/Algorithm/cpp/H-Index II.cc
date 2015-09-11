class Solution {
public:
    int hIndex(vector<int>& citations) {
        // assert(citations is sorted)
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            int h_idx = n - i;
            if (h_idx <= citations[i]) {
                return h_idx;
            }
        }
        return 0;
    }
};
