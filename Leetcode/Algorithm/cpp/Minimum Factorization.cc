typedef long long llint;

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) {
            return a;
        }
        vector<int> n(10, 0);
        for (int i = 9; i >= 2; i--) {
            while (a % i == 0) {
                n[i]++;
                a /= i;
            }
        }
        
        if (a != 1) {
            return 0; 
        }
        
        llint res = 0;
        for (int i = 2; i <= 9; i++) {
            for (int j = 0; j < n[i]; j++) {
                res = res * 10 + i;
                
                if (res > numeric_limits<int>::max()) {
                    return 0;
                }
            }
        }
        return res;
    }
};
