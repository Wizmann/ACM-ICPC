class Solution {
public:
    typedef long long llint;
    static const int ERROR_CODE = 2147483647;
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return ERROR_CODE;
        }
        
        int sig = (dividend >= 0? 1: -1) * (divisor >= 0? 1: -1);
        llint res = _divide(
            abs(static_cast<llint>(dividend)),
            abs(static_cast<llint>(divisor))
        ) * sig;
        if (res > numeric_limits<int>::max()) {
            return ERROR_CODE;
        }
        return static_cast<int>(res);
    }
private:
    llint _divide(llint dividend, llint divisor) {
        llint res = 0;
        for (int i = 31; i >= 0; i--) {
            llint u = divisor << i;
            if (u <= dividend) {
                dividend -= u;
                res |= (1LL << i);
            }
        }
        return res;
    }
};
