const int INF = 1 << 29;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        int diff = INF;
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            int j = i + 1, k = num.size() - 1;
            while(j < k) {
                int cur = num[i] + num[j] + num[k];
                int cur_diff =  cur - target;
                if (abs(cur_diff) < diff) {
                    diff = abs(cur_diff);
                    res = cur;
                }
                
                if (cur_diff > 0) k--;
                else j++;
            }
        }
        return res;
    }
};
