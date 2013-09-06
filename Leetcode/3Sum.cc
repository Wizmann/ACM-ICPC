class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        for (int i = 0; i < num.size(); i++) {
            if (i - 1 >= 0 && num[i - 1] == num[i]) {
                continue;
            }
            
            int j = i + 1, k = num.size() - 1;
            while (true) {
                while (j < num.size() && j - 1 != i && num[j - 1] == num[j]) {
                    j++;
                }
                while (k >= 0 && k + 1 < num.size() && num[k + 1] == num[k]) {
                    k--;
                }
                if (j >= k) {
                    break;
                }
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> t;
                    t.push_back(num[i]);
                    t.push_back(num[j]);
                    t.push_back(num[k]);
                    res.push_back(t);
                }
                if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};
