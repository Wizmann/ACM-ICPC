/*
分类讨论

1. 结果为0的情况
2. 结果为整个数列相加的情况
3. 结果为单个循环节的最大子数组和
4. 结果为两个循环节的最大子数组和
5. 结果为第一个循环节的后辍 + (k - 2)个循环节 + 最后一个循环节的前辍
*/

typedef long long llint;

const int MOD = 1000000000 + 7;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int n = arr.size();
        llint res = 0;
        
        llint t = accumulate(arr.begin(), arr.end(), 0);
        res = max(res, t * k);
        
        {
            llint tot = 0;
            llint mini = 0;

            for (int i = 0; i < n; i++) {
                tot += arr[i];
                res = max(res, tot - mini);
                mini = min(tot, mini);
            }
        }
        
        if (k >= 2) {
            llint l = 0;
            llint r = 0;
            
            llint totl = 0;
            for (int i = 0; i < n; i++) {
                totl += arr[i];
                l = max(l, totl);
            }
            
            llint totr = 0;
            for (int i = n - 1; i >= 0; i--) {
                totr += arr[i];
                r = max(r, totr);
            }
            
            res = max(res, l + r);
            res = max(res, l + r + 1LL * (k - 2) * t);
        }
        return res % MOD;
    }
};
