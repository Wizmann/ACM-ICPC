class Solution {
public:
    const int INF = 1<<28;
    int maxSubArray(int A[], int n) {
        int ans = -INF;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            ans = max(ans, sum)
            if(sum <= 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
};