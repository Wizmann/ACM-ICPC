class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     */
    int backPack(int m, vector<int> A) {
        int n = A.size();
        dp[0] = 1;
        for (auto& obj: A) {
            for (int j = m; j >= 0; j--) {
                if (dp[j]) {
                    dp[j + obj] = 1;
                }
            }
        }
        for (int i = m; i >= 0; i--) {
            if (dp[i]) {
                return i;
            }   
        }
        return 0;
    }
private:
    static const int SIZE = 102400;
private:
    int dp[SIZE];
};
