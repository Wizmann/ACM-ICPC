class Solution {
    /*
     * param k : As description.
     * param n : As description.
     * return: An integer denote the count of digit k in 1..n
     */
public:
    int digitCounts(int k, int n) {
        int count = 0;
        int base = 1;
        while (n >= base) {
            int curBit = n % (base*10) / base;
            int higher = n / (base*10);
            int lower = n % base;
            if (curBit < k) {
                count += higher * base;
            }
            else if (curBit == k) {
                count += higher * base + lower + 1;
            } else {
                count += (higher + 1) * base;
            }
            base *= 10;
        }
        return count;
    }
};
