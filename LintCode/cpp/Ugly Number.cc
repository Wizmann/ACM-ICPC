class Solution {
    typedef long long llint;
    static const llint INF = 0x3f3f3f3f3f3f3f3fLL;
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        const int N = 3;
        vector<llint> factors = {3, 5, 7};
        vector<llint> uglynums = {1};
        vector<llint> pointers = {0, 0, 0};
        
        for (int i = 0; i < k; /* pass */) {
            llint mini = INF;
            int pp = -1;
            for (int j = 0; j < N; j++) {
                int p = pointers[j];
                llint v = uglynums[p] * factors[j];
                if (v < mini) {
                    pp = j;
                    mini = v;
                }
            }
            pointers[pp]++;
            if (mini != *uglynums.rbegin()) {
                uglynums.push_back(mini);
                i++;
            }
        }
        return *uglynums.rbegin();
    }
};
