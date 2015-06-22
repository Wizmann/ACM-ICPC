class Solution {
public:
    int candy(vector<int> &ratings) {
        int ans = 0;
        int n = ratings.size();
        vector<int> qs(n, 0);
        qs[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                qs[i] = qs[i - 1] + 1;
            } else {
                qs[i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                qs[i] = max(qs[i + 1] + 1, qs[i]);
            }
        }
        for (auto i: qs) {
            ans += i;
        }
	return ans;
    }
};
