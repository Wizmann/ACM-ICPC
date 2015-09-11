// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
    typedef long long llint;
public:
    int firstBadVersion(int n) {
        llint l = 1;
        llint r = n;
        
        while (l <= r) {
            llint m = (l + r) >> 1;
            if (isBadVersion(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
