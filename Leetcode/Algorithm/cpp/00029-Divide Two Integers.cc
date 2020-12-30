class Solution {
public:
    typedef long long llint;
    int divide(int dividend, int divisor) {
        int sig = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        return sig * do_solve(abs(llint(dividend)), abs(llint(divisor)));
    }
    
    int do_solve(llint a, llint b) {
        int ans = 0;
        for (int i = 0;/* PASS */; i++) {
            if (a < (b << i)) {
                break;
            }
            ans = i;
        }
        
        if ((b << ans) > a) return 0;
        else return (1 << ans) | do_solve(a - (b << ans), b);
    }
};
