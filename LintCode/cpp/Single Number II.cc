class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer 
     */
    int singleNumberII(vector<int> &A) {
        vector<int> bits(32, 0);
        for (auto a: A) {
            for (int i = 0; i < 32; i++) {
                if (a & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans |= (bits[i] % 3) << i;
        }
        return ans;
    }
};

