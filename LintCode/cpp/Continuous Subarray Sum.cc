class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        int n = A.size();
        int st = 0;
        int maxi = numeric_limits<int>::min();
        int sum = 0;
        pair<int, int> ans = {-1, -1};
        
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum > maxi) {
                maxi = sum;
                ans = {st, i};
            }
            if (sum <= 0) {
                st = i + 1;
                sum = 0;
            }
        }
        return {
            ans.first,
            ans.second
        };
    }
};
