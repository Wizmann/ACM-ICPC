class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int last = -1;
        for (int i = 0; i < n; /* pass */) {
            int delta = -1;
            if (bits[i] == 1) {
                delta = 2;
            } else {
                delta = 1;
            }
            i += delta;
            last = delta;
        }
        return last == 1;
    }
};
