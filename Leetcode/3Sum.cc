class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());
        ans.clear();
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && num[i - 1] == num[i]) {
                continue;
            }
            int p = i + 1, q = n - 1;
            while (p < q) {
                int s = num[i] + num[p] + num[q];
                if (s == 0) {
                    append_record(num[i], num[p], num[q]);
                }
                if (s >= 0) {
                    int qq = num[q];
                    do {
                        q--;
                    } while (q > p && num[q] == qq);
                }
                if (s <= 0) {
                    int pp = num[p];
                    do {
                        p++;
                    } while (q > p && num[p] == pp);
                }
            }
        }
        return ans;
    }
private:
    void append_record(int a, int b, int c) {
        ans.push_back(vector<int>({a, b, c}));
    }
private:
    vector<vector<int> > ans;
};
