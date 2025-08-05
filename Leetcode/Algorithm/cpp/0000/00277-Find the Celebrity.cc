// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int p = 0;
        int q = n - 1;
        
        while (p < q) {
            if (knows(p, q)) {
                p++;
            } else {
                q--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != p && !knows(i, p)) {
                return -1;
            }
            if (i != p && knows(p, i)) {
                return -1;
            }
        }
        return p;
    }
};
