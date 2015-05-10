class Solution {
    
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        int n = nums.size();
        
        if (n == 1) {
            return {0, 0};
        }
        
        vector<pair<int, int> > sums;
        sums.push_back({0, -1});
        
        for (int i = 0, sum = 0; i < n; i++) {
            sum += nums[i];
            sums.push_back({sum, i});
        }
        sort(sums.begin(), sums.end());
        
        
        int mini = INF;
        auto p = pair<int, int>(0, 0);
        for (int i = 0; i + 1 < n; i++) {
            auto a = sums[i];
            auto b = sums[i + 1];
            
            int diff = abs(a.first - b.first);
            
            if (diff < mini) {
                p = pair<int, int>(
                    min(a.second, b.second) + 1,
                    max(a.second, b.second)
                );
                mini = diff;
            }
        }
        return vector<int>({p.first, p.second});
    }
private:
    static const int INF = numeric_limits<int>::max();
};
