class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        res.clear();
        singleNumberIII(A, 0, A.size());
        if (res.size() == 1) {
            res.push_back(0);
        }
        return res;
    }
private:
    void singleNumberIII(vector<int>& A, int st, int end) {
        if (end - st == 1) {
            res.push_back(A[st]);
            return;
        }
        int rand_ = rand() % (end - st);
        int pivot_value = *(A.begin() + st + rand_);
        auto pivot = partition(A.begin() + st, A.begin() + end, [pivot_value](int a) {
            return a < pivot_value;
        });
        int mid = pivot - A.begin();
        int l = 0;
        int r = 0;

        for (int i = st; i < mid; i++) {
            l ^= A[i];
        }
        for (int i = mid; i < end; i++) {
            r ^= A[i];
        }
        if (l != 0 && r != 0) {
            res = {l, r};
        }
        if (l != 0 && r == 0) {
            singleNumberIII(A, st, mid);
        }
        if (l == 0 && r != 0) {
            singleNumberIII(A, mid, end);
        }
    }
private:
    vector<int> res;
};
