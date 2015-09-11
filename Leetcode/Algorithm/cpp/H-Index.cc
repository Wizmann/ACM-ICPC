class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            int val = citations[i];
            int num = n - i;
            
            if (num <= val) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};
