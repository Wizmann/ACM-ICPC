class Solution {
public:
    /**
     * @param n: The number of digits
     * @return: All narcissistic numbers with n digits
     */
    vector<int> getNarcissisticNumbers(int n) {
        int l = 1;
        if (n == 1) {
            l = 0;
        } else {
            for (int i = 0; i < n - 1; i++) {
                l *= 10;
            }
        }
        int r = 1;
        for (int i = 0; i < n; i++) {
            r *= 10;
        }

        vector<int> pows(10, 1);
        for (int i = 0; i <= 9; i++) {
            pows[i] = pow(i, n);
        }

        vector<int> res;
        for (int i = l; i < r; i++) {
            int cur = i;
            int tot = 0;
            while (cur) {
                tot += pows[cur % 10];
                cur /= 10;
            }
            // cout << i << ' ' << tot << endl;
            if (tot == i) {
                res.push_back(i);
            }
        }
        return res;
    }
};
