class Solution {
public:
    typedef long long llint;
    int divide(llint dividend, llint divisor) {
    	int sig = ((dividend < 0) ^ (divisor < 0)) == 1 ? -1: 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        if (dividend < divisor) {
            return 0;
        }
        
        int res = 0;
        int now = 0;
        llint sum = 0;
        
        while (true) {
            llint next = sum + (divisor << now);
            if (next < dividend) {
                res += 1 << now;
                now++;
                sum = next;
                if (sum + divisor > dividend) {
                    break;
                }
            } else if (next == dividend) {
                res += 1 << now;
                break;
            } else {
                now--;
            }
        }
        return sig == 1 ? res : -res;
    }
};
