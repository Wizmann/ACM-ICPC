class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) {
            return 1;
        }
        vector<int> ns(10, 0);
        for (int i = 2; i < 10; i++) {
            while (a != 1 && a % i == 0) {
                ns[i]++;
                a /= i;
            }
        }
        if (a != 1) {
            return 0;
        }

        if (ns[3]) {
            int c = ns[3] / 2;
            ns[3] -= c * 2;
            ns[9] += c;
        }
        
        if (ns[2]) {
            int c = ns[2] / 3;
            ns[2] -= c * 3;
            ns[8] += c;
        }
        
        if (ns[2] && ns[3]) {
            int c = min(ns[2], ns[3]);
            ns[2] -= c;
            ns[3] -= c;
            ns[6] += c;
        }
        
        if (ns[2]) {
            int c = ns[2] / 2;
            ns[2] -= c * 2;
            ns[4] += c;
        }
        
        long long ans = 0;
        for (int i = 2; i < 10; i++) {
            for (int j = 0; j < ns[i]; j++) {
                ans = ans * 10 + i;
            }
            if (ans > numeric_limits<int>::max()) {
                return 0;
            }
        }
        return ans;
    }
};
