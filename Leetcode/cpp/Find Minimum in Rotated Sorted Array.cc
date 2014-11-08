class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        return do_findMin(num, 0, n - 1);
    }
private:
    int do_findMin(vector<int>& num, int st, int end) {
        int l = st, r = end;
        if (l == r) {
            return num[l];
        }
        int res = min(num[st], num[end]);
        int mid = (l + r) >> 1;
        if (num[l] > num[mid]) {
            res = min(res, do_findMin(num, st, mid));
        } else {
            res = min(res, do_findMin(num, mid + 1, end));
        }
        return res;
    }
};
