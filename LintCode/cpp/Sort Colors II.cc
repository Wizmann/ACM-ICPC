class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        int n = colors.size();
        int kk = k + 1;
        for (auto& c: colors) {
            int cc = c % kk;
            colors[cc - 1] += kk;
        }
        int p = 0;
        int q = 0;
        while (p < n && q < n) {
            int u = colors[q] / kk;
            for (int i = 0; i < u; i++) {
                colors[p] = (colors[p] / kk) * kk + q + 1;
                p++;
            }
            q++;
        }
        for (auto& c: colors) {
            c %= kk;
        }
    }
};
