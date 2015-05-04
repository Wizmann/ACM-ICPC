class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        int n = colors.size();
        for (auto& c: colors) {
            c--;
        }
        for (int i = 0; i < n; i++) {
            int u = colors[i] % k;
            colors[u] += k;
        }
        for (int i = 0, j = 0; i < k; i++) {
            int u = colors[i] / k;
            for (int p = 0; p < u; p++) {
                colors[p + j] = (colors[p + j] / k) * k;
                colors[p + j] += i;
            }
            j += u;
        }
        for (auto& c: colors) {
            c = (c % k) + 1;
        }
    }
};
