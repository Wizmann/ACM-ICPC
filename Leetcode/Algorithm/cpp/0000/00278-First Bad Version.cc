// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0;
        int r = n;
        while (l <= r) {
            int m = (l >> 1) + (r >> 1) + (l & r & 1);
            bool res = isBadVersion(m);
            if (res) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
