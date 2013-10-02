class Solution {
public:
    int trap(int A[], int n) {
        int MaxLeft[n], MaxRight[n];
        memset(MaxLeft, 0, sizeof(MaxLeft));
        memset(MaxRight, 0, sizeof(MaxRight));
        
        for (int i = 0; i < n; i++) {
            if (i) MaxLeft[i] = max(A[i], MaxLeft[i-1]);
            else MaxLeft[i] = A[i];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) MaxRight[i] = max(A[i], MaxRight[i+1]);
            else MaxRight[i] = A[i];
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ml = i - 1 >= 0? MaxLeft[i-1] : 0;
            int mr = i + 1 < n? MaxRight[i+1] : 0;
            int h = min(ml, mr) - A[i];
            ans += h > 0? h : 0;
        }
        return ans;
    }
};
