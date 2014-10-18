class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int p = 0, q = p + 1;
        
        while (q < n) {
            if (num[p] < num[q]) {
                q++;
                continue;
            }
            if (num[p] > num[q]) {
                p = q;
                q = p + 1;
                continue;
            }
            for (int i = 0; i < n; i++) {
                int pp = (p + i) % n;
                int qq = (q + i) % n;
                if (num[pp] < num[qq]) {
                    q = qq;
                    break;
                } else if (num[pp] > num[qq]) {
                    p = q;
                    q = p + 1;
                    break;
                }
            }
            p = q;
            q = p + 1;
        }
        return num[p];
    }
};
