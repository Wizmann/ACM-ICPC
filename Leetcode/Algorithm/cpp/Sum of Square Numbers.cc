typedef long long llint;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; 2LL * i * i <= c; i++) {
            llint a = 1LL * i * i;
            llint b = 1LL * c - a;
            
            if (isSquare(b)) {
                return true;
            }
        }
        return false;
    }
private:
    bool isSquare(llint x) {
        llint t = sqrt(x);
        return t * t == x;
    }
};
