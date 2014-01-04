class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = -INF;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
