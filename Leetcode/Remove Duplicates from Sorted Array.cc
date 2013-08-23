class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int now = INT_MIN;
        int ptr = 0;
        int len = 0;
        while (ptr <= n) {
            if (ptr == n || A[ptr] != now) {
                if (now != INT_MIN) {
                    A[len++] = now;
                }
                if (ptr != n) {
                    now = A[ptr];
                }
            }
            
            ptr++;
        }
        return len;
    }
};
