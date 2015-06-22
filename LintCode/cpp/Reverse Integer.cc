class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        int sig = n < 0? -1: 1;
        auto str = to_string(n);
        reverse(str.begin(), str.end());
        str = (sig < 0? "-": "") + str;
        auto res = strtol(str.c_str(), NULL, 10);
        if (res > numeric_limits<int>::max() ||
                res < numeric_limits<int>::min()) {
            res = 0;
        }
        return errno == ERANGE? 0: res;
    }
};
