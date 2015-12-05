class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = n - i;
            if (citations[i] >= cnt) {
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
