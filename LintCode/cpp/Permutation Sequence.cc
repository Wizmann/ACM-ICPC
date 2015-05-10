class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
       const int factors[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
       memset(visit, 0, sizeof(visit));
       k--;
       string res;
       
       k %= factors[n];
       
       for (int i = 1; i <= n; i++) {
           int a = k / factors[n - i];
           int b = k % factors[n - i];
           
           res += to_string(get_nth(a));
           k = b;
       }
       return res;
    }
private:
    int get_nth(int n) {
        for (int i = 1; i < SIZE; i++) {
            if (!visit[i] && n == 0) {
                visit[i] = 1;
                return i;
            }
            if (!visit[i]) {
                n--;
            }
        }
        return -1;
    }
private:
    static const int SIZE = 10;
    int visit[SIZE];
};
