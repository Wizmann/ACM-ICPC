class Solution {
public:
    bool canJump(int A[], int n) {
        int cover = 0;
        for (int i = 0; i <= cover && i < n; i++) {
            cover = max(cover, i + A[i]);
        }
        return (cover >= n - 1);
    }
};
