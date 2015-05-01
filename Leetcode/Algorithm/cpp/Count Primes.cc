class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        sieve.reset();
        for (int i = 3; i <= n; i += 2) {
            if (sieve[i] != 0) {
                continue;
            }
            for (int j = 2; i * j <= n; j++) {
                sieve[i * j] = 1;
            }
        }  
        
        int cnt = 0;
        for (int i = 3; i < n; i += 2) {
            if (sieve[i] == 0) {
                cnt++;
            }
        }
        return ++cnt;
    }
private:
    static const int SIZE = 2500000;
    bitset<SIZE> sieve;
};
