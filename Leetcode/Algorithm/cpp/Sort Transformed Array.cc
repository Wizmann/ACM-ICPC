const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int pivot = 0;
        int s = 1;
        if (a < 0) {
            s = -1;
            a = -a;
            b = -b;
            c = -c;
        }
        if (a != 0) {
            pivot = -1 * b / 2 / a;
        } else if (b > 0) {
            pivot = -INF;
        } else {
            pivot = INF;
        }
        
        int p = lower_bound(nums.begin(), nums.end(), pivot) - nums.begin();
        int q = 0;
        
        if (p == 0) {
            p = -1;
            q = 0;
        } else {
            q = p;
            p--;
        }
        
        vector<int> res;
        
        auto f = [=](int x) { return a * x * x + b * x + c; };
        
        while (p >= 0 || q < nums.size()) {
            int x = p >= 0? f(nums[p]): INF;
            int y = q < nums.size()? f(nums[q]): INF;
            
            if (x < y) {
                res.push_back(x);
                --p;
            } else {
                res.push_back(y);
                ++q;
            }
        }
        
        if (s == -1) {
            for (auto& item: res) {
                item = -item;
            }
            reverse(res.begin(), res.end());
        }

        return res;
    }
};
