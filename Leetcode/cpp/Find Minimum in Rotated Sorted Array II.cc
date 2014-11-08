class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        res = INF;
        do_findMin(num, 0, n - 1);
        return res;
    }
private:
    void do_findMin(vector<int>& num, int st, int end) {
        int l = st, r = end;
        res = min(res, num[st]);
        if (l == r) { return; }
        int mid = (l + r) >> 1;
        if (num[l] == num[mid] && num[mid] == num[r]) {
            do_findMin(num, st, mid);
            do_findMin(num, mid + 1, end);
        }
        if (num[mid] < num[l]) {
            do_findMin(num, st, mid);
        } else {
            do_findMin(num, mid + 1, end);
        }
    }
    int res;
    const int INF = 0x3f3f3f3f;
};
