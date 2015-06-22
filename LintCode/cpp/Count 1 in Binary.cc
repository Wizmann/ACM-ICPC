class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int res = 0;
        while (num) {
            res++;
            num -= lowbit(num);
        }
        return res;
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }
};
