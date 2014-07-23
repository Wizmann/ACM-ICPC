class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        while (true) {
            res.push_back(num);
            bool flag = false;
            for (int i = n - 2; i >= 0; i--) {
                int ii = i + 1;
                if (num[i] < num[ii]) {
                    swap(num[i], num[get_max_pos(i, num)]);
                    reverse(num.begin() + ii, num.end());
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        return res;
    }
    int get_max_pos(int pos, vector<int>& num) {
        for (int i = num.size() - 1; i > pos; i--) {
            if (num[i] > num[pos]) {
                pos = i;
            }
        }
        return pos;
    }
};
