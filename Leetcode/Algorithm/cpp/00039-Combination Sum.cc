class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int dp[SIZE] = {0};
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int> > > res;
        res.resize(SIZE);
        
        int p = 0;
        dp[0] = 1;
        res[0].push_back(vector<int>());
        
        for (int i = 0; i < (int)candidates.size(); i++) {
            int now = candidates[i];
            for (int j = 0; j < target; j++) {
                if (dp[j]) {
                    dp[j + now] = 1;
                    for (auto iter = res[j].begin(); iter != res[j].end(); ++iter) {
                        vector<int> vec = *iter;
                        vec.push_back(now);
                        res[j + now].push_back(vec);
                    }
                }
            }
        }
        return res[target];
    }
    
    static const int SIZE = 1024;
};
