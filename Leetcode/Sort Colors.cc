class Solution {
public:
    void sortColors(int A[], int n) {
        int l = 0, r = n - 1;
        for (int i = 0; i <= r; /*pass*/) {
            switch(A[i]) {
                case 0: swap(A[i++], A[l++]); break;
                case 2: swap(A[i], A[r--]); break;
                default: i++; break;
            }
        }
    }
};
