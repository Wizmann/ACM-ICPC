class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        int n = A.size();
        long long a = 0;
        long long b = 0;
        
        for (int i = 0; i < n; i++) {
            long long aa = A[i] + b;
            long long bb = max(a, b);
            
            a = aa;
            b = bb;
        }
        
        return max(a, b);
    }
};
