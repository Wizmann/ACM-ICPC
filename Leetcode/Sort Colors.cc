class Solution {
public:
    void sortColors(int A[], int n) 
    {
        int p = 0;
        move(A, n, 0, p);
        move(A, n, 1, p);
        move(A, n, 2, p);
    }
    
    void move(int A[], int n, int x, int& p)
    {
        for (int i = p; i < n; i++) {
            if (A[i] == x) {
                swap(A[i], A[p]);
                p++;
            }
        }
    }
};
