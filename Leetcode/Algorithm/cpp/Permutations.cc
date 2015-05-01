class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while (_next_permutation(num));
        return res;
    }
private:
    bool _next_permutation(vector<int>& num) {
        int n = num.size();
        for (int i = n - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) {
                _swap_the_minimum(num, i, n);
                reverse(num.begin() + i + 1, num.end());
                return true;
            }
        }
        return false;
    }
    
    void _swap_the_minimum(vector<int>& num, int pos, int n) {
        for (int i = n - 1; i >= pos; i--) {
            if (num[i] > num[pos]) {
                swap(num[i], num[pos]);
                return;
            }
        }
    }
};
