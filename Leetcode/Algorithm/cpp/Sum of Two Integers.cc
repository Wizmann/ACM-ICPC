class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int c = a & b;
            int d = a ^ b;
            a = d;
            b = c << 1;
        }
        return a;
    }
};
