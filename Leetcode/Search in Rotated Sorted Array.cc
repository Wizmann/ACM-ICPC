class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        
        while (l <= r) {
            int v0 = A[l], v1 = A[r];
            int mid = (l + r) >> 1;
            if (A[mid] >= v0) {
                if (target >= v0 && target <= A[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target < v0 && target > A[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        if (r + 1 < n && A[r + 1] == target) {
            return r + 1;
        }
        return -1;
    }
};
