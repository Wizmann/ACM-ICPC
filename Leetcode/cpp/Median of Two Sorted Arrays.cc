class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int tot = m + n;
        if (tot & 1) {
            return do_findKth(A, m, B, n, tot / 2 + 1);
        } else {
            return (do_findKth(A, m, B, n, tot / 2) +
                    do_findKth(A, m, B, n, tot / 2 + 1)) / 2;
        }
    }
private:
    double do_findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return do_findKth(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k - 1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        int pa = min(k >> 1, m);
        int pb = k - pa;
        
        if (A[pa - 1] < B[pb - 1]) {
            return do_findKth(A + pa, m - pa, B, n, k - pa);
        } else if (A[pa - 1] > B[pb - 1]) {
            return do_findKth(A, m, B + pb, n - pb, k - pb);
        } else {
            return A[pa - 1];
        }
    }
};
