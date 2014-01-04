class Solution {
public:
    int search(int A[], int n, int target) {
        int pivot = find_pivot(A, 0, n - 1);
        
        if (pivot == -1) return -999;
        
        if (target < A[0] || pivot == 0) {
            int res = _lower_bound(A + pivot, n - pivot - 1, target);
            if (res == -1) return res;
            else return res + pivot;
        } else {
            return _lower_bound(A, pivot, target);
        }
    }
    
    int _lower_bound(int A[], int n, int target) {
        int now = 0;
        int step = n;
        while (step) {
            int half = step >> 1;
            int mid = now + half;
            
            if (A[mid] >= target) {
                step = half;
            } else {
                now = mid + 1;
                step = step - half - 1;
            }
        }
        
        if (A[now] != target) return -1;
        
        return now;
    }
    
    int find_pivot(int A[], int st, int end) {
        if (end - st + 1 <= 3) {
            int res = st;
            while (st <= end) {
                if (A[st] < A[res]) {
                    res = st;
                }
                st++;
            }
            return res;
        }
        
        int mid = (st + end) >> 1;
        
        int a = A[st];
        int b = A[mid];
        int c = A[end];
        
        if (b < a && b < c) {
            return find_pivot(A, st, mid);
        } else if (b > a && b > c) {
            return find_pivot(A, mid, end);
        } else {
            return 0;
        }
    }
};
