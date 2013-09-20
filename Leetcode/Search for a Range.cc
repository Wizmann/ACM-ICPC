class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int a = lb(A, n, target);
        int b = ub(A, n, target) - 1;
        
        if (A[a] != target) a = b = -1;
        if (A[b] != target) a = b = -1;
        
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        
        return vec;
    }
    
    int lb(int A[], int n, int target) {
        int first = 0;
        while (n) {
            int half = n >> 1;
            int mid = first + half;
            
            if (A[mid] < target) {
                first = mid + 1;
                n = n - half - 1;
            } else {
                n = half;
            }
        }
        return first;
    }
    
    int ub(int A[], int n, int target) {
        int first = 0;
        while (n) {
            int half = n >> 1;
            int mid = first + half;
            
            if (A[mid] <= target) {
                first = mid + 1;
                n = n - half - 1;
            } else {
                n = half;
            }
        }
        return first;
    }
};
